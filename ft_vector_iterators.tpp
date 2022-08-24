/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterators.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:39:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/24 17:20:25 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"

namespace ft
{
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::begin(void)
		{return(iterator(_begin));}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin(void) const
		{return(const_iterator(_begin));}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::end(void)
		{return(iterator(_end));}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end(void) const
		{return(const_iterator(_end));}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin(void)
		{return(static_cast<reverse_iterator>(end()));}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin(void) const
		{return(static_cast<const_reverse_iterator>(end()));}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend(void)
		{return(static_cast<reverse_iterator>(begin()));}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend(void) const
		{return(static_cast<const_reverse_iterator>(begin()));}
};

