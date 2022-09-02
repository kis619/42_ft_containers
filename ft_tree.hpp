/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:27:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/02 20:02:48 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED false
# define BLACK true
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
		new_node 			= node_alloc.allocate(1);
		new_node->parent	= NULL;
		new_node->left		= NULL;
		new_node->right		= NULL;
		new_node->colour	= RED;
		new_node->data		= val;
	}
	
	void insert(value_type val)
	{
		node_ptr new_node;
		// initialise_RED_node(new_node, val);
		new_node 			= node_alloc.allocate(1);
		new_node->parent	= NULL;
		new_node->left		= nil_node;
		new_node->right		= nil_node;
		new_node->colour	= RED;
		new_node->data		= val;
		
		node_ptr parent		= NULL;
		node_ptr current	= root;

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
		new_node->parent = parent;
		if (parent == NULL)
			root = new_node;
		else if (new_node->data.first < parent->data.first)
			parent->left = new_node;
		else
			parent->right = new_node;
		
	}

	// void print_tree(void) const
	// 	{
	// 		_printHelper("ss", root, false);
	// 	}

	// void _printHelper(const std::string& prefix, const node_ptr n, bool isLeft) const
	// {
	// 	if (n != nil_node && n != nullptr)
	// 	{
	// 		std::cout << prefix;

	// 		std::cout << (isLeft ? "├──" : "└──" );

	// 		// print the value of the node
	// 		std::cout << n->data.first << std::endl;

	// 		// enter the next tree level - left and right branch
	// 		_printHelper(prefix + (isLeft ? "│   " : "    "), n->left, true);
	// 		_printHelper(prefix + (isLeft ? "│   " : "    "), n->right, false);
	// 	}
	// }

};
}
#endif