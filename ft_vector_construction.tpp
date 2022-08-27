/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_construction.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:16:41 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/27 21:32:56 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <iostream>

namespace ft
{
	//Default Constructor
	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(const allocator_type &alloc) :
	_alloc(alloc),
	_capacity(0),
	_begin(NULL),
	_end(NULL)
	{
	}
	
	//Fill constructor
	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(size_type n, const value_type &val, const allocator_type &alloc) :
	_alloc(alloc),
	_capacity(n),
	_begin(NULL),
	_end(NULL)
	{
		_begin = _alloc.allocate(n);
		_end = _begin;
		while(n)
		{
			_alloc.construct(_end, val);
			_end++;
			n--;
		}
	}
	
	// range constructor  //need to ask Kacper about this enable_if thingy
	template<typename T, typename Allocator>
	template <class InputIterator>
	vector<T, Allocator>::vector(InputIterator first, InputIterator last, const allocator_type &alloc,
		typename enable_if<!is_integral<InputIterator>::value>::type*) :
	_alloc(alloc),
	_capacity(last - first),
	_begin(NULL),
	_end(NULL)
	{
		_begin = _alloc.allocate(last - first);
		_end = _begin;
		while(first != last)
		{
			_alloc.construct(_end, *first);
			_end++;
			first++;
		}
	}

	//copy constructor 
	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(const vector &x)
	{
		std::cout << "Constructor copy called\n";
		_capacity = x.size();
		_begin = _alloc.allocate(_capacity);
		_end = _begin;
		for (size_type i = 0; i < _capacity; i++)
		{
			_alloc.construct(_end, x[i]);
			_end++;
		}
	}

	//destructor
	template<typename T, typename Allocator>
	vector<T, Allocator>::~vector(void)
	{
		clear();
		_alloc.deallocate(_begin, capacity());
	}
}
