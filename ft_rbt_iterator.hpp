/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/05 10:46:27 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR
# define RBT_ITERATOR

#include "ft_iterator_traits.hpp"

namespace ft
{
	template< class Node>
	class RBTreeIterator : ft::iterator<ft::bidirectional_iterator_tag, Node>
	{
		public:
			typedef ft::bidirectional_iterator_tag				iterator_category;
			typedef Node											value_type;
			typedef Node*											pointer;
			// typedef 
	
		pointer ptr; //should be private

		RBTreeIterator(void) : ptr(NULL) {};		
		pointer operator++()
		{
			
		}
	};

};

#endif