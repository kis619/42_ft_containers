/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/09 14:45:30 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "ft_iterator_traits.hpp"

namespace ft
{
	template< class node_type>
	class RBTreeIterator : ft::iterator<ft::bidirectional_iterator_tag, node_type>
	{
		public:
			typedef ft::bidirectional_iterator_tag				iterator_category;
			typedef node_type									value_type;
			typedef node_type*									pointer;
			typedef node_type&									reference;
			// typedef typename node_type::pointer_val				pointer_v;
		
		
		RBTreeIterator(void) : ptr(NULL), tail(NULL) {};
		RBTreeIterator(pointer node_ptr, pointer last_element) : ptr(node_ptr), tail(last_element){};
		RBTreeIterator(const RBTreeIterator &copy) : ptr(copy.ptr), tail(copy.tail) {};
		RBTreeIterator &operator=(const RBTreeIterator &other)
		{
		 	ptr = other.ptr;
			tail = other.ptr;
			return (*this);
		}
		RBTreeIterator &operator++(); //pre-increment
		RBTreeIterator &operator--(); //pre-decrement
		
		RBTreeIterator operator++(int) //post-increment
		{
			RBTreeIterator temp(*this);
			(*this)++;
			return (temp);
		}
		RBTreeIterator operator--(int) //post-decrement
		{
			RBTreeIterator temp(*this);
			(*this)--;
			return(temp);
		}
		
		reference operator*() {return (*ptr);};
		pointer operator->() {return (&(operator*().value));};

		private: 
			pointer ptr;
			pointer tail;
	};

};

#endif