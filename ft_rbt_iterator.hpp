/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/12 23:28:05 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "ft_iterator_traits.hpp"

namespace ft
{
template< class node_type> //if i add the tree, I can add the compare maybe
class RBTreeIterator : ft::iterator<ft::bidirectional_iterator_tag, node_type>
{
	public:
		typedef ft::bidirectional_iterator_tag				iterator_category;
		typedef node_type									value_type;
		typedef node_type*									pointer;
		typedef node_type&									reference;
		typedef typename node_type::key_value_pair			pointer_v;
	
	
	///Constructors
	RBTreeIterator(void) : ptr(NULL), nil_ptr(NULL) {};
	RBTreeIterator(pointer node_ptr, pointer last_element) : ptr(node_ptr), nil_ptr(last_element){};
	RBTreeIterator(const RBTreeIterator &copy) : ptr(copy.ptr), nil_ptr(copy.nil_ptr) {};
	RBTreeIterator &operator=(const RBTreeIterator &other)
	{
		ptr = other.ptr;
		nil_ptr = other.nil_ptr;
		return (*this);
	}

	///Operators - Increment|Decrement
	RBTreeIterator &operator++()	//pre-increment
	{
		pointer temp = ptr;
		if ((ptr->parent == NULL) || (ptr->right != nil_ptr))
		{
			temp = ptr->right;
			while(temp->left != nil_ptr && temp->left->value->first > ptr->value->first)
				temp = temp->left;
			ptr = temp;
			return(*this);
		}
		while(ptr->parent->value->first < ptr->value->first)
		{
			ptr = ptr->parent;
			if (ptr->parent == NULL)
			{
				ptr = nil_ptr;
				return(*this);
			}
		}
		ptr = ptr->parent;
		return(*this);
	};
	
	RBTreeIterator &operator--()	//pre-decrement
	{
		pointer temp = ptr;
		if (ptr->right != nil_ptr && ptr->left != nil_ptr)
		{
			temp = ptr->left;
			while(temp->right != nil_ptr && temp->right->value->first < ptr->value->first)
				temp = temp->right;
			ptr = temp;
			return(*this);
		}
		while(ptr != nil_ptr && ptr->parent != NULL && ptr->parent->value->first > ptr->value->first)
			ptr = ptr->parent;
		ptr = ptr->parent;
		return(*this);
	};
	
	RBTreeIterator operator++(int) {RBTreeIterator temp(*this); ++(*this); return (temp);} //post-increment
	RBTreeIterator operator--(int) { RBTreeIterator temp(*this); --(*this); return(temp);} //post-derement
	///Operators - (de)reference
	reference operator*() {return (*ptr);};
	pointer_v operator->() {return (ptr->value);};
	


	pointer getPtr(void) const
		{return (ptr);}

	pointer getNilPtr(void) const
		{return (nil_ptr);}
	
	private: 
		pointer ptr;
		pointer nil_ptr;
};

template< class node_type> //if i add the tree, I can add the compare maybe
class const_RBTreeIterator : ft::iterator<ft::bidirectional_iterator_tag, node_type>
{
	public:
		typedef ft::bidirectional_iterator_tag				iterator_category;
		typedef const node_type									value_type;
		typedef node_type*									pointer;
		typedef node_type&									reference;
		typedef typename node_type::key_value_pair			pointer_v;
	
	
	///Constructors
	const_RBTreeIterator(void) : ptr(NULL), nil_ptr(NULL) {};
	const_RBTreeIterator(pointer node_ptr, pointer last_element) : ptr(node_ptr), nil_ptr(last_element){};
	const_RBTreeIterator(const const_RBTreeIterator &copy) : ptr(copy.ptr), nil_ptr(copy.nil_ptr) {};
	const_RBTreeIterator &operator=(const const_RBTreeIterator &other)
	{
		ptr = other.ptr;
		nil_ptr = other.nil_ptr;
		return (*this);
	}
	const_RBTreeIterator &operator=(const RBTreeIterator<node_type> &other)
	{
		ptr = other.getPtr();
		nil_ptr = other.getNilPtr();
		return (*this);
	}

	///Operators - Increment|Decrement
	const_RBTreeIterator &operator++()	//pre-increment
	{
		std::cout << "++\n";
		pointer temp = ptr;
		if ((ptr->parent == NULL) || (ptr->right != nil_ptr))
		{
			// std::cout << "SHOULD BE HERE\n";
			temp = ptr->right;
			while(temp->left != nil_ptr && temp->left->value->first > ptr->value->first)
				temp = temp->left;
			ptr = temp;
			return(*this);
		}
				while(ptr->parent->value->first < ptr->value->first)
		{
			ptr = ptr->parent;
			if (ptr->parent == NULL)
			{
				ptr = nil_ptr;
				return(*this);
			}
		}
		ptr = ptr->parent;
		return(*this);
	};
	
	const_RBTreeIterator &operator--()	//pre-decrement
	{
		pointer temp = ptr;
		if (ptr->right != nil_ptr && ptr->left != nil_ptr)
		{
			temp = ptr->left;
			while(temp->right != nil_ptr && temp->right->value->first < ptr->value->first)
				temp = temp->right;
			ptr = temp;
			return(*this);
		}
		while(ptr != nil_ptr && ptr->parent != NULL && ptr->parent->value->first > ptr->value->first)
			ptr = ptr->parent;
		ptr = ptr->parent;
		return(*this);
	};
	
	const_RBTreeIterator operator++(int) {const_RBTreeIterator temp(*this); ++(*this); return (temp);} //post-increment
	const_RBTreeIterator operator--(int) {const_RBTreeIterator temp(*this); --(*this); return(temp);} //post-derement
	///Operators - (de)reference
	reference operator*() {return (*ptr);};
	pointer_v operator->() {return (ptr->value);};
	


	pointer getPtr(void) const
		{return (ptr);}
	
	private: 
		pointer ptr;
		pointer nil_ptr;
};
	///LOGICAL OPERATORS
	template< class node_type>
	bool operator==(const RBTreeIterator<node_type> &it1, const RBTreeIterator<node_type> &it2)
	{return (it1.getPtr() == it2.getPtr());}

	template< class node_type>
	bool operator==(const const_RBTreeIterator<node_type> &it1, const RBTreeIterator<node_type> &it2)
	{return (it1.getPtr() == it2.getPtr());}

	template< class node_type>
	bool operator!=(const RBTreeIterator<node_type> &it1, const RBTreeIterator<node_type> &it2)
	{return (it1.getPtr() != it2.getPtr());}
	
	template< class node_type>
	bool operator==(const const_RBTreeIterator<node_type> &it1, const const_RBTreeIterator<node_type> &it2)
	{return (it1.getPtr() == it2.getPtr());}

	template< class node_type>
	bool operator!=(const const_RBTreeIterator<node_type> &it1, const const_RBTreeIterator<node_type> &it2)
	{return (it1.getPtr() != it2.getPtr());}
	template< class node_type>
	bool operator!=(const RBTreeIterator<node_type> &it1, const const_RBTreeIterator<node_type> &it2)
	{return (it1.getPtr() != it2.getPtr());}
};

#endif