/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/10 22:03:15 by kmilchev         ###   ########.fr       */
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
		
		
		RBTreeIterator(void) : ptr(NULL), nil_ptr(NULL) {};
		RBTreeIterator(pointer node_ptr, pointer last_element) : ptr(node_ptr), nil_ptr(last_element){};
		RBTreeIterator(const RBTreeIterator &copy) : ptr(copy.ptr), nil_ptr(copy.nil_ptr) {};
		RBTreeIterator &operator=(const RBTreeIterator &other)
		{
		 	ptr = other.ptr;
			nil_ptr = other.nil_ptr;
			return (*this);
		}
		RBTreeIterator &operator++()
		{
			// std::cout << "++\n";
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
				ptr = ptr->parent;
			ptr = ptr->parent;
			return(*this);
		}; //pre-increment
		
		RBTreeIterator &operator--()
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
			while(ptr->parent->value->first > ptr->value->first)
				ptr = ptr->parent;
			ptr = ptr->parent;
			return(*this);
		}; //pre-decrement
		
		RBTreeIterator operator++(int) //post-increment
		{
			RBTreeIterator temp(*this);
			++(*this);
			return (temp);
		}
		RBTreeIterator operator--(int) //post-decrement
		{
			RBTreeIterator temp(*this);
			--(*this);
			return(temp);
		}
		
		reference operator*() {return (*ptr);};
		pointer_v operator->() {return (ptr->value);};

		private: 
			pointer ptr;
			pointer nil_ptr;

	};

};

#endif