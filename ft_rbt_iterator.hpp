/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:26:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/05 15:12:11 by kmilchev         ###   ########.fr       */
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
			// typedef 
	
		pointer ptr; //should be private

		RBTreeIterator(void) : ptr(NULL) {};		
		pointer operator++();

	};

};

#endif