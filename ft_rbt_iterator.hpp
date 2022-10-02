/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/02 12:42:34 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "ft_iterator_traits.hpp"

namespace ft
{
template< class node_type>
class RBTreeIterator : public ft::iterator<ft::bidirectional_iterator_tag, typename node_type::value_type>
{
	public:
		typedef node_type *																				node_ptr;
		typedef typename node_type::value_type															value_type;
		typedef typename node_type::value_type* 														pointer;
		typedef typename node_type::value_type&															reference;
		typedef const typename node_type::value_type* 													const_pointer;
		typedef const typename node_type::value_type&													const_reference;
	

	template <class T,  class Compare, class Allocator>
	friend class RBTree;
	///CONSTRUCTION
	protected:
		RBTreeIterator(node_ptr ptr, node_ptr first_element, node_ptr last_element) : ptr(ptr), nil_ptr(last_element), first_ptr(first_element){};
	
	public:
	RBTreeIterator(node_ptr ptr = NULL) : ptr(ptr), nil_ptr(ptr), first_ptr(ptr) {};
	RBTreeIterator(const RBTreeIterator &copy) : ptr(copy.ptr), nil_ptr(copy.nil_ptr), first_ptr(copy.first_ptr) {};
	RBTreeIterator &operator=(const RBTreeIterator &other)
	{
		ptr = other.ptr;
		nil_ptr = other.nil_ptr;
		first_ptr = other.first_ptr;
		return (*this);
	}

	RBTreeIterator &operator++(void)//pre-increment
	{
		if (ptr == nil_ptr && first_ptr != ptr)
			ptr = first_ptr;
		else if (ptr->right != nil_ptr) 
		{
			ptr = ptr->right;
			while (ptr->left != nil_ptr)
				ptr = ptr->left;
		}
		else
		{
			node_ptr current = ptr;
			node_ptr tmp = ptr;
			if (ptr->parent == NULL) 
			{ 
				ptr = current->right;
				return (*this);
			}
			ptr = ptr->parent;
			while (ptr->left != tmp)
			{
				if (ptr->parent == NULL)
				{ 
					ptr = current->right;
					break;
				}
				tmp = ptr;
				ptr = ptr->parent;
			}
		}
		return(*this);
	};

	RBTreeIterator &operator--() //pre-decrement
	{
		if (ptr == nil_ptr) 
			ptr = ptr->parent;
		else if (ptr->left != nil_ptr)
		{
			ptr = ptr->left;
			while (ptr->right != nil_ptr)
				ptr = ptr->right;
		} 
		else 
		{
			node_ptr tmp = ptr;
			ptr = ptr->parent;
			while (ptr->right != tmp)
			{
				tmp = ptr;
				if (ptr->parent == NULL)
				{ 
					ptr = tmp->left - 1;
					break;
				}
				ptr = ptr->parent;
			}
		}
		return(*this);
	};

	RBTreeIterator operator++(int) {RBTreeIterator temp(*this); ++(*this); return (temp);} //post-increment
	RBTreeIterator operator--(int) { RBTreeIterator temp(*this); --(*this); return(temp);} //post-derement
	reference operator*(void) {return *(ptr->value);};
	pointer operator->(void) {return ptr->value;};
	const_reference operator*(void) const {return *(ptr->value);};
	const_pointer operator->(void) const {return ptr->value;};

	node_ptr getPtr(void) const
		{return (ptr);}

	node_ptr getNilPtr(void) const
		{return (nil_ptr);}

	node_ptr getFirstPtr(void) const
		{return (first_ptr);}

	private: 
		node_ptr ptr;
		node_ptr nil_ptr;
		node_ptr first_ptr;
};

template< class node_type>
class const_RBTreeIterator : public ft::iterator<ft::bidirectional_iterator_tag, typename node_type::value_type>
{
	public:
		typedef node_type *																				node_ptr;
		typedef const typename node_type::value_type													value_type;
		typedef typename node_type::value_type* 														pointer;
		typedef typename node_type::value_type&															reference;
		typedef const typename node_type::value_type* 													const_pointer;
		typedef const typename node_type::value_type&													const_reference;
		
	
	
	///CONSTRUCTION
	const_RBTreeIterator(node_ptr ptr = NULL) : ptr(ptr), nil_ptr(ptr), first_ptr(ptr) {};
	const_RBTreeIterator(node_ptr ptr, node_ptr first_element, node_ptr last_element) : ptr(ptr), nil_ptr(last_element), first_ptr(first_element){};
	const_RBTreeIterator(const const_RBTreeIterator &copy) : ptr(copy.ptr), nil_ptr(copy.nil_ptr), first_ptr(copy.first_ptr) {};
	const_RBTreeIterator(const ft::RBTreeIterator<node_type> &copy) : ptr(copy.getPtr()), nil_ptr(copy.getNilPtr()), first_ptr(copy.getFirstPtr()) {};
	const_RBTreeIterator &operator=(const const_RBTreeIterator &other)
	{
		ptr = other.ptr;
		nil_ptr = other.nil_ptr;
		first_ptr = other.first_ptr;
		return (*this);
	}
	const_RBTreeIterator &operator=(const ft::RBTreeIterator<node_type> &other)
	{
		ptr = other.getPtr();
		nil_ptr = other.getNilPtr();
		first_ptr = other.getFirstPtr();
		return (*this);
	}

	const_RBTreeIterator &operator++(void)	//pre-increment
	{
		if (ptr == nil_ptr && first_ptr != ptr)
			ptr = first_ptr;
		else if (ptr->right != nil_ptr) 
		{
			ptr = ptr->right;
			while (ptr->left != nil_ptr)
				ptr = ptr->left;
		}
		else
		{
			node_ptr current = ptr;
			node_ptr tmp = ptr;
			if (ptr->parent == NULL) 
			{ 
				ptr = current->right;
				return (*this);
			}
			ptr = ptr->parent;
			while (ptr->left != tmp)
			{
				if (ptr->parent == NULL)
				{ 
					ptr = current->right;
					break;
				}
				tmp = ptr;
				ptr = ptr->parent;
			}
		}
		return(*this);
	};

	const_RBTreeIterator &operator--()	//pre-decrement
	{
		if (ptr == nil_ptr) 
			ptr = ptr->parent;
		else if (ptr->left != nil_ptr)
		{
			ptr = ptr->left;
			while (ptr->right != nil_ptr)
				ptr = ptr->right;
		} 
		else 
		{
			node_ptr tmp = ptr;
			ptr = ptr->parent;
			while (ptr->right != tmp)
			{
				tmp = ptr;
				if (ptr->parent == NULL)
				{ 
					ptr = tmp->left - 1;
					break;
				}
				ptr = ptr->parent;
			}
		}
		return(*this);
	};
	
	const_RBTreeIterator operator++(int) {const_RBTreeIterator temp(*this); ++(*this); return (temp);} //post-increment
	const_RBTreeIterator operator--(int) {const_RBTreeIterator temp(*this); --(*this); return(temp);} //post-derement
	reference operator*(void) {return *(ptr->value);};
	pointer operator->(void) {return ptr->value;};
	const_reference operator*(void) const {return *(ptr->value);};
	const_pointer operator->(void) const {return ptr->value;};

	node_ptr getPtr(void) const
		{return (ptr);}
	
	private: 
		node_ptr ptr;
		node_ptr nil_ptr;
		node_ptr first_ptr;
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