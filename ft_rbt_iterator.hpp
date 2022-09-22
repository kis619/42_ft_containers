/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/22 14:29:42 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "ft_iterator_traits.hpp"

namespace ft
{
template< class node_type> //if i add the tree, I can add the compare maybe
class RBTreeIterator : public ft::iterator<ft::bidirectional_iterator_tag, typename node_type::value_type>
{
	public:
		typedef node_type *																				node_ptr;
		typedef typename node_type::value_type															value_type;
		typedef typename node_type::value_type* 														pointer;
		typedef typename node_type::value_type&															reference;
		// typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		// typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		// typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

	///Constructors
	RBTreeIterator(node_ptr ptr = NULL) : ptr(ptr), nil_ptr(ptr) {};
	RBTreeIterator(node_ptr ptr, node_ptr last_element) : ptr(ptr), nil_ptr(last_element){};
	RBTreeIterator(const RBTreeIterator &copy) : ptr(copy.ptr), nil_ptr(copy.nil_ptr) {};
	RBTreeIterator &operator=(const RBTreeIterator &other)
	{
		ptr = other.ptr;
		nil_ptr = other.nil_ptr;
		return (*this);
	}

	RBTreeIterator &operator++()
	{
		node_ptr temp = ptr;
		if (ptr != NULL && ((ptr->parent == NULL) || (ptr->right != nil_ptr)))
		{
			temp = ptr->right;
			while(temp->left != nil_ptr && temp->left->value->first > ptr->value->first)
				temp = temp->left;
			ptr = temp;
			return(*this);
		}
		while(ptr != nil_ptr && ptr->parent != NULL && ptr->value && ptr->parent->value->first < ptr->value->first)
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

	RBTreeIterator &operator--()
	{
		node_ptr temp = ptr;
		if (!temp->parent && temp->left == nil_ptr)
			temp = temp->parent;
		else if (temp == nil_ptr)
			temp = nil_ptr->parent;
		else if (temp->left != nil_ptr && temp->left)
		{
			temp = temp->left;
			while (temp->right != nil_ptr)
			{
				temp = temp->right;
			}
		}
		else if (temp->parent && temp == temp->parent->right)
			temp = temp->parent;
		else if (temp->parent && temp == temp->parent->left)
		{
			while (temp->parent && temp == temp->parent->left)
				temp = temp->parent;
			if (temp->parent)
				temp = temp->parent;
			else 
				temp = nullptr;
		}
		else
			temp = nil_ptr->parent;
		_prev = ptr;
		ptr = temp;
		return (*this);
	};

	RBTreeIterator operator++(int) {RBTreeIterator temp(*this); ++(*this); return (temp);}
	RBTreeIterator operator--(int) { RBTreeIterator temp(*this); --(*this); return(temp);}
	reference operator*(void) const
	{
		return *(ptr->value);
	};
	pointer operator->(void) const {return ptr->value;};

	node_ptr getPtr(void) const
		{return (ptr);}

	node_ptr getNilPtr(void) const
		{return (nil_ptr);}

	private: 
		node_ptr ptr;
		node_ptr nil_ptr;
		node_ptr _prev;
};

template< class node_type>
class const_RBTreeIterator : ft::iterator<ft::bidirectional_iterator_tag, node_type>
{
	public:
		typedef node_type *																				node_ptr;
		typedef const typename node_type::value_type													value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
		
	
	
	///Constructors
	const_RBTreeIterator(node_ptr ptr = NULL) : ptr(ptr), nil_ptr(ptr) {};
	const_RBTreeIterator(node_ptr ptr, node_ptr last_element) : ptr(ptr), nil_ptr(last_element){};
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
		// std::cout << "++\n";
		node_ptr temp = ptr;
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
		node_ptr temp = ptr;
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
	reference operator*() {return *(ptr->value);};
	pointer operator->(void) const {return &(operator*());};
	


	node_ptr getPtr(void) const
		{return (ptr);}
	
	private: 
		node_ptr ptr;
		node_ptr nil_ptr;
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


// 'RBTreeIterator<ft::RBTree<const ft::pair<const int, int>, ft::map<int, int, std::__1::plus<int>, std::__1::allocator<ft::pair<const int, int> > >::value_compare, std::__1::allocator<ft::pair<const int, int> > >::Node>'
// 'RBTreeIterator<ft::RBTree<const ft::pair<const int, int>, ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::value_compare, std::__1::allocator<ft::pair<const int, int> > >::Node>'