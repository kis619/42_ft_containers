/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:27:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/02 21:44:18 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED true
# define BLACK false
# include "ft_utils.hpp"

namespace ft
{
template <	class Key,
			class T,
			class Allocator = std::allocator<pair<const Key, T> >,
			class Compare = std::less<Key> >
class RBTree
{
	// struct Node;
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair< Key, T>								value_type;
		typedef Allocator										allocator_type;
		typedef Compare											key_compare;
	
	
	struct Node
	{
		bool		colour;
		// key_type	key_value;
		// mapped_type	mapped_value;
		value_type	data;
		Node		*parent;
		Node		*left;
		Node		*right;
	};

	typedef Node*									node_ptr;

	node_ptr				root; // should be private
	node_ptr				nil_node; // should be private
	std::allocator<Node>	node_alloc; // should be private
	allocator_type			alloc;

	
	RBTree(const key_compare &comp = key_compare(),
					const allocator_type &alloc = allocator_type())
	{
		nil_node = node_alloc.allocate(1);
		nil_node->colour = BLACK;
		nil_node->parent = NULL;
		nil_node->left = NULL;
		nil_node->right = NULL;
		// nil_node->data = NULL;
		root = nil_node;
	}

	// ~RBTree(void)
	// {
	// 	node_alloc.deallocate(root, 1);
	// }
	
	void initialise_NULL_node(node_ptr node, node_ptr parent)
	{
		node			= node_alloc.allocate(1);
		node->parent	= parent;
		node->left		= NULL;
		node->right		= NULL;
		node->colour	= BLACK;
	}
	
	void initialise_RED_node(node_ptr new_node, value_type val)
	{
		new_node->parent	= NULL;
		new_node->left		= nil_node;
		new_node->right		= nil_node;
		new_node->colour	= RED;
		new_node->data		= val;
	}
	
	void insert(value_type val)
	{
		//Binary Search Insertion
		node_ptr new_node	= node_alloc.allocate(1);
		node_ptr parent		= NULL;
		node_ptr current	= root;

		initialise_RED_node(new_node, val);
		while(current != nil_node)
		{
			parent = current;
			if (new_node->data.first < current->data.first)
				current = current->left;
			else if (new_node->data.first > current->data.first)
				current = current->right;
			else
				return;
		}

		// Set the parent and insert the new node
		new_node->parent = parent;
		if (parent == NULL)
			root = new_node;
		else if (new_node->data.first < parent->data.first)
			parent->left = new_node;
		else
			parent->right = new_node;
		
		fix_insert(new_node);
	}

	// rotate left at node x
	void rotate_left(node_ptr x)
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
	void rotate_right(node_ptr x)
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
	
	void fix_insert(node_ptr child)
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
				else if (uncle->colour == BLACK) //just else
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
				else if (uncle->colour == BLACK) //just else
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
	
	void print_tree(void) const
		{
			_printHelper("", root, false);
		}

	void _printHelper(const std::string& prefix, const node_ptr n, bool isLeft) const
	{
		if (n != nil_node && n != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			std::cout << n->data.first << std::endl;

			// enter the next tree level - left and right branch
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->left, true);
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->right, false);
		}
	}

};
}
#endif