/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_capacity.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/24 01:13:22 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"

namespace ft
{
	template <typename T, typename Allocator>
	void vector<T, Allocator>::resize(size_type n, value_type val) 
	{
		size_type old_size = size();
		if (n < old_size)
		{
			for (int i = n; i != old_size; i++)
			{
				_alloc.destroy(_begin + i);
			}
			_end = _begin + n;
		}
		else if (n > old_size)
		{
			if (n > _capacity)
				adjust_capacity(n);
			for (int i = old_size; i < n; i ++)
			{
				_alloc.construct(_end++, val);
			}
		}
	}
	
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
	
	template <typename T, typename Allocator>
	bool vector<T, Allocator>::empty(void) const
	{
		return (_begin == _end);
	}
	

	

};
