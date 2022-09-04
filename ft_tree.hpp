/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:27:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/04 19:00:56 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED true
# define BLACK false
# include "ft_utils.hpp"

namespace ft
{
template <class T,  class Compare, class Allocator>
class RBTree
{
	public:
		struct Node;
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef Compare											value_comp;
		typedef size_t											size_type;			
	
	struct Node
	{
		bool		colour;
		value_type	value;
		Node		*parent;
		Node		*left;
		Node		*right;
	};

	typedef Node*									node_ptr;

	private:
		node_ptr				root;
		node_ptr				nil_node;
		std::allocator<Node>	node_alloc;
		allocator_type			alloc;
		value_comp			comp;
		size_type				_size;
	
	public:
	RBTree(const value_comp &comp_, const allocator_type &alloc_) : comp(comp_), alloc(alloc_), _size(0)
	{
		nil_node = node_alloc.allocate(sizeof(struct Node));
		nil_node->colour = BLACK;
		nil_node->parent = NULL;
		nil_node->left = nil_node;
		nil_node->right = nil_node;
		// nil_node->value = NULL;
		root = nil_node;
	}

	~RBTree(void)
	{
		// node_alloc.deallocate(nil_node, sizeof(struct Node));
	}
	
	void initialise_RED_node(node_ptr new_node, const value_type &val)
	{
		new_node->parent	= NULL;
		new_node->left		= nil_node;
		new_node->right		= nil_node;
		new_node->colour	= RED;
		new_node->value		= val;
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
			std::cout << n->value.first << std::endl;

			// enter the next tree level - left and right branch
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->left, true);
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->right, false);
		}
	}

	///INSERT
	node_ptr insert(const value_type &val);
	void fix_insert(node_ptr child);
	
	///ERASE
	template<class Key>
	size_type erase_unique(const Key &key);
	void erase(const value_type &val);
	void fix_erase(node_ptr x);
	void rb_transplant(node_ptr u, node_ptr v); 	//util for delete

	
	//util for delete
	node_ptr min(node_ptr node)
	{
		while(node->left != nil_node)
			node = node->left;
		return (node);
	}

	node_ptr find(const value_type &val)
	{
		node_ptr node = root;

		while(node != nil_node)
		{
			if (!comp(val, node->value) && !comp(node->value, val))
				return (node);
			if (comp(val, node->value))
				node = node->left;
			else if (comp(node->value, val))
				node = node->right;
		}
		return (node);
	}
	
	template<class Key>
	value_type find_by_only_key(const Key &key)
	{
		node_ptr node = root;

		while(node != nil_node)
		{
			if (node->value.first == key)
				return (node->value);
			if (key < node->value.first)
				node = node->left;
			else if (key > node->value.first)
				node = node->right;
		}
		return (value_type());
	}
	
	size_t size(void)
	{
		return (_size);
	}

	bool empty(void)
	{
		return (_size == 0);
	}

	allocator_type get_allocator(void) const
	{
		return (alloc);
	}

	// key_comp get_comp()
	// {
	// 	return (comp);
	// }
};
}
#endif