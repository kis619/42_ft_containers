/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:27:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/05 13:50:49 by kmilchev         ###   ########.fr       */
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
		typedef Node*											node_ptr;
	
		struct Node
		{
			bool		colour;
			value_type	value;
			Node		*parent;
			Node		*left;
			Node		*right;
		};


	private:
		node_ptr				root;
		node_ptr				nil_node;
		std::allocator<Node>	node_alloc;
		allocator_type			alloc;
		value_comp				comp;
		size_type				_size;
	
	public:
	RBTree(const value_comp &comp_, const allocator_type &alloc_) : comp(comp_), alloc(alloc_), _size(0)
	{
		nil_node = node_alloc.allocate(1);
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


	///INSERT
	node_ptr	insert(const value_type &val);
	void 		fix_insert(node_ptr child);
	void 		rotate_left(node_ptr x); //util for insert and erase
	void 		rotate_right(node_ptr x); //util for insert and erase
	
	///ERASE
	template<class Key>
	size_type	erase_unique(const Key &key);
	size_type	erase(const value_type &val);
	void		fix_erase(node_ptr x);
	void		rb_transplant(node_ptr u, node_ptr v); 	//util for erase
	node_ptr	min(node_ptr node); //util for erase

	///MISCELLANEOUS
	void			print_tree(void) const;
	void			_printHelper(const std::string& prefix, const node_ptr n, bool isLeft) const;
	node_ptr		find(const value_type &val);
	template<class Key>
	value_type		find_by_only_key(const Key &key);
	size_type		size(void);
	bool			empty(void);
	allocator_type	get_allocator(void) const;
	value_comp		get_comp(void);
	void			clearNode(node_ptr n);
	
	///ITERATORS
	RBTreeIterator<Node> test(void)
	{
		return (RBTreeIterator<Node>(root));
	}
};
}

#include "ft_tree_erase.tpp"
#include "ft_tree_insert.tpp"
#include "ft_tree_miscellaneous.tpp"
#endif