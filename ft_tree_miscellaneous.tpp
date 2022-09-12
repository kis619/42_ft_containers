/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_miscellaneous.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:19:59 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/12 18:17:52 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.hpp"

namespace ft
{
	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::print_tree(void) const
	{
		_printHelper("", root, false);
	}

	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::_printHelper(const std::string& prefix, const node_ptr n, bool isLeft) const
	{
		if (n != nil_node && n != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			std::cout << n->value->first << std::endl;

			// enter the next tree level - left and right branch
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->left, true);
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->right, false);
		}
	}

	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::node_ptr RBTree<T, Compare, Allocator>::find(const value_type &val)
	{
		node_ptr node = root;

		while(node != nil_node)
		{
			if (!comp(val, *node->value) && !comp(*node->value, val))
				return (node);
			if (comp(val, *node->value))
				node = node->left;
			else if (comp(*node->value, val))
				node = node->right;
		}
		return (node);
	}
	
	template <class T,  class Compare, class Allocator>
	template<class Key>
	typename RBTree<T, Compare, Allocator>::node_ptr RBTree<T, Compare, Allocator>::find_by_only_key(const Key &key)
	{
		node_ptr node = root;

		while(node != nil_node)
		{
			if (node->value->first == key)
				return (node);
			if (key < node->value->first)
				node = node->left;
			else if (key > node->value->first)
				node = node->right;
		}
		return (node);
	}
	
	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::size_type RBTree<T, Compare, Allocator>::size(void) const
	{
		return (_size);
	}
	
	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::size_type RBTree<T, Compare, Allocator>::max_size(void) const
	{
		return (node_alloc.max_size());
	}
	
	template <class T,  class Compare, class Allocator>
	bool RBTree<T, Compare, Allocator>::empty(void) const
	{
		return (_size == 0);
	}

	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::allocator_type RBTree<T, Compare, Allocator>::get_allocator(void) const
	{
		return (alloc);
	}

	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::value_comp RBTree<T, Compare, Allocator>::get_comp(void)
	{
		return (comp);
	}

	template <class T,  class Compare, class Allocator>
	void RBTree<T, Compare, Allocator>::clearNode(node_ptr n)
	{
		node_alloc.deallocate(n, sizeof(Node));
	}

	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::node_ptr RBTree<T, Compare, Allocator>::min(node_ptr node) const
	{
		while(node->left != nil_node)
			node = node->left;
		return (node);
	}

	template <class T,  class Compare, class Allocator>
	typename RBTree<T, Compare, Allocator>::node_ptr RBTree<T, Compare, Allocator>::max(node_ptr node) const
	{
		while(node->right != nil_node)
			node = node->right;
		return(node);
	}
}