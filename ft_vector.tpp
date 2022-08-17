/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:16:41 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/17 23:55:12 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <iostream>

namespace ft
{
	//Default COnstructor
	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(const allocator_type &alloc) :
	_alloc(alloc),
	_capacity(0),
	_begin(nullptr),
	_end(nullptr)
	{
	}
	
	//Fill constructor
	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(size_type n, const value_type &val, const allocator_type &alloc) :
	_alloc(alloc),
	_capacity(n),
	_begin(nullptr),
	_end(nullptr)
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
	_begin(nullptr),
	_end(nullptr)
	{
		_begin = _alloc.allocate(last - first + 15);
		_end = _begin;
		while(first != last)
		{
			_alloc.construct(_end, *first);
			_end++;
			first++;
		}
	}
}

// int main(void)
// {

// 	ft::vector<int> j;
// 	std::cout << j._begin << std::endl;
// 	std::cout << j._end << std::endl;
// 	std::cout << j._capacity << std::endl;
// 	return (0);
// }