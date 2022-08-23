/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_modifiers.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/23 13:30:55 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include "tests/colours.h"

namespace ft
{
	template <typename T, typename Allocator>
	void vector<T, Allocator>::clear(void)
	{
		size_type old_size = size();
		
		for(int i = 0; i < old_size; i++)
		{
			_end--;
			_alloc.destroy(_end);
		}
	}
	
	template <typename T, typename Allocator>
	void vector<T, Allocator>::pop_back(void)
	{
		_alloc.destroy(&back());
		_end--;
	}
	
	template <typename T, typename Allocator>
	void vector<T, Allocator>::push_back(const value_type &val)
	{
		size_type old_size = size();
		if (old_size + 1 >  _capacity)
		{
			size_type new_capacity = 1;
			if (_capacity) 
				new_capacity = _capacity * 2;
			pointer tmp = _alloc.allocate(new_capacity);
			for(unsigned int i = 0; i < old_size; i++)
			{
				_alloc.construct(tmp + i, _begin[i]);
				_alloc.destroy(_begin + i);
			}
			_alloc.deallocate(_begin, _capacity);
			_begin = tmp;
			_capacity = new_capacity;
		}
		_alloc.construct(_begin + old_size, val);
		_end = _begin + old_size + 1;
	}
	
	template <typename T, typename Allocator>
	void vector<T, Allocator>::adjust_capacity(void)
	{
		if (size() > _capacity)
		{
			
		}
	}
	
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator(void) const
	{
		return(_alloc);
	}
};
