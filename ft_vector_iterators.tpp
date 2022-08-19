/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterators.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:39:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/19 21:45:38 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"

namespace ft
{
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::begin(void)
	{
		return(static_cast<typename vector<T, Allocator>::iterator>(_begin));
	}

	// template<typename T, typename Allocator>
	// typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin(void) const
	// {
	// 	return(const_iterator(_begin));
	// }
};

