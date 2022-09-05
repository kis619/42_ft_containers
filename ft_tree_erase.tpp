/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_erase.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:19:59 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/05 11:42:32 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.hpp"

namespace ft
{
	template <class T,  class Compare, class Allocator>
	template<class Key>
	typename RBTree<T, Compare, Allocator>::size_type RBTree<T, Compare, Allocator>::erase_unique(const Key &key)
	{
		node_ptr node = root;

		while(node != nil_node)
		{
			if (node->value.first == key)
				break ;
			if (key < node->value.first)
				node = node->left;
			else if (key > node->value.first)
				node = node->right;
		}
		
		erase(node->value);
		return(_size);
	}
	
	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::erase(const value_type &val)
	{
		node_ptr found_node = find(val);
		node_ptr x;
		node_ptr y;

		if (found_node == nil_node) //will adapt this later
		{
			std::cout << "No node\n";
			return ;
		}

		//BST delete
		_size--;
		y = found_node;
		bool y_og_colour = y->colour;

		//if there is only one node
		if (found_node == root && (found_node->left == nil_node && found_node->right == nil_node)) //could use size == 0 here maybe
		{
			//free found_note or simply root
			#include <stdlib.h>
			root = nil_node;
			return ;
		}
		
		if (found_node->left == nil_node)
		{
			x = found_node->right;
			rb_transplant(found_node, found_node->right);
		}
		else if (found_node->right == nil_node)
		{
			x = found_node->left;
			rb_transplant(found_node, found_node->left);
		}
		else
		{
			y = min(found_node->right);
			y_og_colour = y->colour;
			x = y->right;
			if (y->parent == found_node)
				x->parent = y;
			else
			{
				rb_transplant(y, y->right);
				y->right = found_node->right;
				y->right->parent = y;
			}
			rb_transplant(found_node, y);
			y->left = found_node->left;
			y->left->parent = y;
			y->colour = found_node->colour;
		}
		//free found_node;
		if (y_og_colour == BLACK)
		{
			fix_erase(x);
		}
		
		///saw it in Kacper's code // need to check with him what for
		// Node *temp1 = this->root;
		// while (temp1->right != this->nil_node)
		// 	temp1 = temp1->right;
		// this->nil_node->parent = temp1;
	}

	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::fix_erase(node_ptr x)
	{
		node_ptr s;
		while(x != root && x->colour == BLACK)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->colour == RED)
				{
					s->colour = BLACK;
					x->parent->colour = RED;
					rotate_left(x->parent);
					s = x->parent->right;
				}
				
				if (s->left->colour == BLACK && s->right->colour == BLACK)
				{
					s->colour = RED;
					x = x->parent;
				}
				else
				{
					if (s->right->colour == BLACK)
					{
						s->left->colour = BLACK;
						s->colour = RED;
						rotate_right(s);
						s = x->parent->right;
					}
					s->colour = x->parent->colour;
					x->parent->colour = BLACK;
					s->right->colour = BLACK;
					rotate_left(x->parent);
					x = root;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->colour == RED)
				{
					s->colour = BLACK;
					x->parent->colour = RED;
					rotate_right(x->parent);
					s = x->parent->left;
				}

				if (s->right->colour == BLACK && s->right->colour == BLACK)
				{
					s->colour = RED;
					x = x->parent;
				} 
				else
				{
					if (s->left->colour == BLACK)
					{
						s->right->colour = BLACK;
						s->colour = RED;
						rotate_left(s);
						s = x->parent->left;
					} 
					s->colour = x->parent->colour;
					x->parent->colour = BLACK;
					s->left->colour = BLACK;
					rotate_right(x->parent);
					x = root;
				}
			}
		}
		x->colour = BLACK;
	}

	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::rb_transplant(node_ptr u, node_ptr v)
	{
		if (u->parent == NULL)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}
	
	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::node_ptr RBTree<T, Compare, Allocator>::min(node_ptr node)
	{
		while(node->left != nil_node)
			node = node->left;
		return (node);
	}
}