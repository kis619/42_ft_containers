/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:08:20 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/17 23:32:55 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stack>

using std::enable_if;
using std::is_integral;

namespace ft
{
template <typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
	typedef T									value_type;
	typedef Allocator							allocator_type;
	typedef typename allocator_type::pointer	pointer;
	typedef typename allocator_type::size_type	size_type;
	
//default constructor 
	explicit vector (const allocator_type& alloc = allocator_type());
//fill constructor
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
//range constructor
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename enable_if<!is_integral<InputIterator>::value>::type* = nullptr);

public: ////////SHOULD BE PRIVATE
	allocator_type		_alloc;
	size_type			_capacity;
	pointer				_begin;
	pointer				_end;
	
};
};

#include "ft_vector.tpp"
#endif