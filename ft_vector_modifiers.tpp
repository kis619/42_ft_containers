/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_modifiers.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/24 22:09:56 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include "tests/colours.h"

namespace ft
{
	template <typename T, typename Allocator>
	template <class InputIterator>
	void vector<T, Allocator>::assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type*)
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
	void vector<T, Allocator>::assign(size_type n, const value_type &val)
	{
		clear();
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
				_alloc.construct(_end++, val);
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
	typename vector<T, Allocator>::iterator vector<T, Allocator>::insert (iterator position, const value_type &val)
	{
		size_type pos = end() - position;
		size_type diff = position - begin();
		
		if(size() + 1 > _capacity)
			adjust_capacity();
		for(size_type i = 0; i < pos; i++)
			_alloc.construct(_end - i, *(_end - i - 1));
		_alloc.construct(_end - pos, val);
		_end++;
		return(begin() + diff);
	}
	
	template <typename T, typename Allocator>
	void vector<T, Allocator>::insert (iterator position, size_type n, const value_type& val)
	{
		if (n)
		{
			size_type pos = end() - position;
			if(size() + n > _capacity)
				adjust_capacity(size() + n);
			////moved the elements
			for(size_type i = 0; i <= pos; i++)
				_alloc.construct(_end - i + n, *(_end - i));
			////add the new ones
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_end - (pos), val);
				_end++;
			}
		}
	}
	
	template <typename T, typename Allocator>
	template<class InputIterator>
	void vector<T, Allocator>::insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type*)
	{
		size_type n = last - first;
		int i = 0;
		if (n)
		{
			size_type pos = end() - position;
			if(size() + n > _capacity)
					adjust_capacity(size() + n);
			for(size_type i = 0; i <= pos; i++)
					_alloc.construct(_end - i + n, *(_end - i));
			while (first != last)
			{
				_alloc.construct(_end - (pos), *(first.base()));
				first++;
				_end++;
				std::cout << "idx: " << i++ << std::endl;
				
			}
		}
		// _end += n;
		// while (first != last)
		// {
		// 	_alloc.construct(&(*position), *first);
		// 	first++;
		// 	position++;
		// }
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
	typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator(void) const
	{
		return(_alloc);
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::adjust_capacity(int n)
	{
		size_type old_size = size();
		size_type new_capacity = 1;
		if (_capacity) 
			new_capacity = _capacity * 2;
		if (n > 2 * _capacity)
			new_capacity = n;
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
	
};
