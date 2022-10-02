/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zangelis <zangelis@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:27:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/03 00:28:37 by zangelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED true
# define BLACK false
# include "ft_utils.hpp"
# include "ft_rbt_iterator.hpp"

namespace ft
{

template <class val>
struct Node
{
	typedef		val	value_type;
	
	bool		colour;
	value_type	*value;
	Node		*parent;
	Node		*left;
	Node		*right;
};

template <class T,  class Compare, class Allocator>
class RBTree
{
	template <	class Key, class U, class Comp,class Alloc>
	friend class map;
	template < class Key, class Comp, class Alloc>
	friend class set;
	
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef Compare											value_comp;
		typedef size_t											size_type;
		typedef ft::Node<value_type>							node;
		typedef ft::Node<value_type>*							node_ptr;
		typedef RBTreeIterator<node>							iterator;
		typedef const_RBTreeIterator<node>						const_iterator;

	private:
		node_ptr				root;
		node_ptr				nil_node;
		std::allocator<node>	node_alloc;
		allocator_type			alloc;
		value_comp				comp;
		size_type				_size;

	public:
	RBTree(const value_comp &comp_, const allocator_type &alloc_) : alloc(alloc_), comp(comp_), _size(0)
	{
		nil_node = node_alloc.allocate(1);
		nil_node->colour = BLACK;
		nil_node->parent = NULL;
		nil_node->left = nil_node;
		nil_node->right = nil_node;
		root = nil_node;
	}

	void deallocateNil(void)
	{
		node_alloc.deallocate(nil_node, 1);
	}

	void clear_node(node_ptr node)
	{
		if (node != nil_node)
			alloc.deallocate(node->value, 1);
		node_alloc.deallocate(node, 1);
	}

	///INSERT
	node_ptr	insert_val(const value_type &val);
	void 		fix_insert(node_ptr child);
	void 		rotate_left(node_ptr x); //util for insert and erase
	void 		rotate_right(node_ptr x); //util for insert and erase
	
	///ERASE
	size_type	erase(const value_type &val);
	void		fix_erase(node_ptr x);
	void		rb_transplant(node_ptr u, node_ptr v); 	//util for erase

	///MISCELLANEOUS
	void			print_tree(void) const;
	void			_printHelper(const std::string& prefix, const node_ptr n, bool isLeft) const;
	node_ptr		find(const value_type &val) const;
	template<class Key>
	node_ptr		find_by_only_key(const Key &key) const;
	size_type		size(void) const;
	size_type		max_size(void) const;
	bool			empty(void) const; 
	allocator_type	get_allocator(void) const;
	value_comp		get_comp(void);
	void			clearNode(node_ptr n);
	node_ptr		min(node_ptr node)	const;
	node_ptr		max(node_ptr node)	const;

	///ITERATORS
	iterator begin(void)
	{
		return iterator(min(root), min(root), nil_node);
	}
	const_iterator begin(void) const
	{
		return const_iterator(min(root), min(root), nil_node);
	}
	
	iterator end(void)
	{
		iterator it = iterator(nil_node, min(root), nil_node);
		return it;
	}
	
	const_iterator end(void) const
	{
		return const_iterator(nil_node, min(root), nil_node);
	}

	iterator insert(const value_type &val)
	{
		return iterator(insert_val(val), min(root), nil_node);
	}

	protected:
	///GETTERS
		node_ptr getRoot(void) const
		{
			return(root);
		}

		node_ptr getNil(void) const
		{
			return(nil_node);
		}

		value_comp getComp(void) const
		{
			return(comp);
		}
};
}

#include "ft_tree_erase.tpp"
#include "ft_tree_insert.tpp"
#include "ft_tree_miscellaneous.tpp"
#endif
