/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_capacity.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/22 13:56:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"

namespace ft
{
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::size(void) const
	{
		return (_end - _begin);
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size(void) const
	{
		return (_alloc.max_size());
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity(void) const
	{
		return (_capacity);
	}
	

};
