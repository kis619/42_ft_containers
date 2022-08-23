/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_modifiers.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/23 15:39:39 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include "tests/colours.h"

namespace ft
{
	template <typename T, typename Allocator>
	template <class InputIterator>
	void vector<T, Allocator>::assign (InputIterator first, InputIterator last)
	{
		clear();
		difference_type n = last - first;
		if (n)
		{
			if (n > _capacity)
			{
				_alloc.deallocate(_begin, _capacity);
				_begin = _alloc.allocate(n);
				_end = _begin;
				_capacity = n;
			}
			while(n)
			{
				_alloc.construct(_end++, *(first.base()));
				first++;
				n--;
			}
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
			_end = _begin + old_size;
			_capacity = new_capacity;
		}
		//OR//
		// size_type old_size = size();
		// if (old_size + 1 > _capacity)
		// 	old_size = adjust_capacity();
		_alloc.construct(_begin + old_size, val);
		_end++;
	}
	
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
	typename vector<T, Allocator>::size_type vector<T, Allocator>::adjust_capacity(void)
	{
		size_type old_size = size();
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
		_end = _begin + old_size;
		_capacity = new_capacity;
		return (old_size);
	}
	
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator(void) const
	{
		return(_alloc);
	}
};
