/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_modifiers.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zangelis <zangelis@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/03 00:09:24 by zangelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include "tests/colours.h"
#include <signal.h>
namespace ft
{
	template <typename T, typename Allocator>
	template <class InputIterator>
	void vector<T, Allocator>::assign (InputIterator first, InputIterator last,
										typename enable_if<!is_integral<InputIterator>::value>::type*)
	{
		clear();
		size_type n = last - first;
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
		if (old_size + 1 > _capacity)
			old_size = adjust_capacity();
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
			////move the elements
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
	void vector<T, Allocator>::insert (iterator position, InputIterator first, InputIterator last,
										typename enable_if<!is_integral<InputIterator>::value>::type*)
	{
		size_type n = last - first;
		if (size_type(_capacity - size()) >= n)
		{
			for (size_type i = 0; i < (size() - (&(*position) - _begin)); i++)
				_alloc.construct(_end - i + n - 1, *(_end - i - 1));
			_end += n;
			while (first != last)
			{
				_alloc.construct(&(*position), *first);
				first++;
				position++;
			}
		}
		else
		{
			size_type n_cap = 1;
			if (_capacity)
				n_cap = _capacity * 2;
			if (n + size() > 2 * _capacity)
				n_cap = n + size();
			
			pointer new_start = _alloc.allocate(n_cap);
			pointer new_end = new_start;
			try
			{
				for (int i = 0; i < &(*position) - _begin; i++)
				{
					_alloc.construct(new_start + i, *(_begin + i));
					new_end++;
				}
				for (int j = 0; first != last; first++, j++)
				{
					_alloc.construct(new_start + (&(*position) - _begin) + j, *first);
					new_end++;
				}
				for (size_type k = 0; k < size() - (&(*position) - _begin); k++)
				{
					_alloc.construct(new_start + (&(*position) - _begin) + n + k, *(&(*position) + k));
					new_end++;
				}
			}
			catch (...)
			{
				while (new_start != new_end)
					_alloc.destroy(new_end--);
				_alloc.destroy(new_end);
				_alloc.deallocate(new_start, n_cap);
				throw ;
			}
			for (size_type l = 0; l < size(); l++)
			{
				_alloc.destroy(_begin + l);
			}
			_alloc.deallocate(_begin, _capacity);
			_begin = new_start;
			_end = new_end;
			_capacity = n_cap;
		}
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position)
	{
		size_type pos = end() - position;
		if (pos <= 0) //the original segfaults//couldn't recreate it hence forcing it 
		{
			raise(SIGSEGV);
		}
		pointer p = &(*position);
		for (size_type i = 0; i < pos - 1; i++)
		{
			_alloc.destroy(p + i);
			_alloc.construct(p + i, *(p + i + 1));
		}
		_end--;
		return (iterator(p));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator first, iterator last)
	{
		size_type pos = end() - first;
		size_type diff = last - first;
		if (pos <= 0) //the original segfaults//couldn't recreate it hence forcing it 
			raise(SIGSEGV);
		pointer p = &(*first);
		while(first != last)
		{
			_alloc.destroy(&(*first));
			first++;
			_end--;
		}
		for (size_type i = 0; i < pos - diff; i++)
		{
			_alloc.destroy(p + i);
			_alloc.construct(p + i, *(p + i + diff));
		}
		return (iterator(p));
	}

	template <typename T, typename Allocator>
	void vector<T, Allocator>::swap(vector &x)
	{
		pointer			temp_beign;	
		pointer			temp_end;
		size_type		temp_capacity;
		allocator_type	temp_alloc;
		
		temp_alloc		=	_alloc;
		temp_beign		=	_begin;
		temp_end		=	_end;
		temp_capacity	=	_capacity;
		
		_alloc			=	x._alloc;
		_begin			=	x._begin;
		_end			=	x._end;
		_capacity		=	x._capacity;

		x._alloc		=	temp_alloc;
		x._begin		=	temp_beign;
		x._end			=	temp_end;
		x._capacity		=	temp_capacity;
	}

	template <typename T, typename Allocator>
	void vector<T, Allocator>::clear(void)
	{
		size_type old_size = size();
		
		for(size_type i = 0; i < old_size; i++)
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
	typename vector<T, Allocator>::size_type vector<T, Allocator>::adjust_capacity(size_type n)
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
