/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:27:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/02 18:58:58 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED false
# define BLACK true
# include "ft_utils.hpp"

namespace ft
{
template <	class Key, class T >
class RBTree
{
	// struct Node;
	public:
		typedef ft::pair<const Key, T>							value_type;
		typedef Key												key_type;
		typedef T												mapped_type;
	
	
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

	node_ptr				root; //should be private
	node_ptr				nil_node; //should be private
	std::allocator<Node>	_node_alloc;

	
	RBTree(void)
	{
		nil_node = _node_alloc.allocate(1);
		nil_node->colour = BLACK;
		nil_node->parent = NULL;
		nil_node->left = NULL;
		nil_node->right = NULL;
		// nil_node->data = NULL;
		root = nil_node;
	}

	// ~RBTree(void)
	// {
	// 	_node_alloc.deallocate(root, 1);
	// }
	
	void initialise_NULL_node(node_ptr node, node_ptr parent)
	{
		node			= _node_alloc.allocate(1);
		node->parent	= parent;
		node->left		= NULL;
		node->right		= NULL;
		node->colour	= BLACK;
		// node->data		= 0;
	}
	
	node_ptr initialise_RED_node(node_ptr new_node, value_type val)
	{
		new_node 			= _node_alloc.allocate(1);
		new_node->parent	= NULL;
		new_node->left		= NULL;
		new_node->right		= NULL;
		new_node->colour	= RED;
		// new_node->data		= val;
	}
	
	void insert(value_type val)
	{
		node_ptr new_node	= initialise_RED_node(new_node, val);
		node_ptr parent		= NULL;
		node_ptr current	= root;

		while(current != nil_node)
		{
			parent = current;
			if (new_node->data.first < val)
				current = current->left;
			else if (new_node->data.first > val)
				current = current->right;
			else
				return;
		}
		
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