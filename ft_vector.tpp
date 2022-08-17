/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:16:41 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/17 19:41:12 by kmilchev         ###   ########.fr       */
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
	_capacity(nullptr),
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
			_alloc.construct(_end, val + n);
			_end++;
			n--;
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