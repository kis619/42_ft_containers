/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_insert.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:19:59 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/11 14:06:48 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.hpp"

namespace ft
{
	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::node_ptr RBTree<T, Compare, Allocator>::insert_test(const value_type &val)
	{
		//Binary Search Insertion
		node_ptr new_node	= node_alloc.allocate(1);
		node_ptr parent		= NULL;
		node_ptr current	= root;

		// initialise_RED_node(new_node, val);
		new_node->parent	= NULL;
		new_node->left		= nil_node;
		new_node->right		= nil_node;
		new_node->colour	= RED;
		new_node->value		= alloc.allocate(1);
		alloc.construct(new_node->value, val);
		while(current != nil_node)
		{
			parent = current;
			if (comp(*new_node->value, *current->value))
				current = current->left;
			else if (comp(*current->value, *new_node->value))
				current = current->right;
			else
				return (current);
		}
		// Set the parent and insert the new node
		new_node->parent = parent;
		if (parent == NULL)
			root = new_node;
		else if (comp(*new_node->value, *parent->value))
			parent->left = new_node;
		else
			parent->right = new_node;
		_size++;
		
		//for method .end()
		node_ptr temp = root;
		///make temp the biggest element
		while(temp->right != nil_node)
			temp = temp->right;
		///attach a nil node to it
		this->nil_node->parent = temp;
		
		// if new_node is the root node, recolour it to black and end
		if (new_node->parent == NULL)
		{
			new_node->colour = BLACK;
			return (new_node);
		}
		
		// if parent is root (grandparent is null) then end
		if (new_node->parent->parent == NULL)
			return (new_node);
				
		fix_insert(new_node);
		return(new_node);
	}

	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::fix_insert(node_ptr child)
	{
		node_ptr uncle;
		
		while(child->parent->colour == RED)
		{
			if (child->parent == child->parent->parent->right)
			{
				uncle = child->parent->parent->left;
				if (uncle->colour == RED)
				{
					uncle->colour = BLACK;
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					child = child->parent->parent;
				}
				else if (uncle->colour == BLACK)
				{
					if (child == child->parent->left)
					{
						child = child->parent;
						rotate_right(child);
					}
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					rotate_left(child->parent->parent);
				}
				
			}
			else
			{
				uncle = child->parent->parent->right;
				
				if (uncle->colour == RED)
				{
					uncle->colour = BLACK;
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					child = child->parent->parent;
				}
				else if (uncle->colour == BLACK)
				{
					if (child == child->parent->right)
					{
						child = child->parent;
						rotate_left(child);
					}
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					rotate_right(child->parent->parent);
				}
			}
			
			if (child == root)
				break ;
		}
		root->colour = BLACK;
	}
	
	// rotate left at node x
	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::rotate_left(node_ptr x)
	{
		node_ptr y = x->right;
		x->right = y->left;
		
		if (y->left != nil_node)
			y->left->parent = x;
		
		y->parent = x->parent;
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::rotate_right(node_ptr x)
	{
		node_ptr y = x->left;
		x->left = y->right;
		if (y->right != nil_node)
			y->right->parent = x;
		
		y->parent = x->parent;
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}
}