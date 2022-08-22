/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:08:20 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/22 17:02:50 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stack>
#include "ft_iterator.hpp"
#include <stdexcept>

using std::enable_if;
using std::is_integral;

namespace ft
{
template <typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
	typedef T														value_type;
	typedef Allocator												allocator_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef	typename ft::random_access_iterator<value_type>			iterator;
	typedef	typename ft::const_random_access_iterator<value_type>	const_iterator;
	typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type		difference_type;
	typedef typename allocator_type::size_type						size_type;
	
//////////////////////////////////CONSTRUCTORS//////////////////
//default constructor 
	explicit vector (const allocator_type& alloc = allocator_type());
//fill constructor
	explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
//range constructor
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value>::type* = nullptr);
//copy constructor
	vector (const vector& x);

//destructor
	~vector(void);

//////////////////////////////////ITERATORS//////////////////
	iterator				begin(void);
	const_iterator			begin(void) const;
	iterator				end(void);
	const_iterator			end(void) const;
	reverse_iterator		rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	reverse_iterator		rend(void);
	const_reverse_iterator	rend(void) const;

/////////////////////////////////CAPACITY///////////////////////
	size_type size(void) const;
	size_type max_size(void) const;
	// void resize (size_type n, value_type val = value_type()); //Member type value_type is the type of the elements in the container, defined in vector as an alias of the first template parameter (T).
	size_type capacity(void) const;
	// bool empty() const; //Returns whether the vector is empty (i.e. whether its size is 0).
	// void reserve (size_type n); //Requests that the vector capacity be at least enough to contain n elements. If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).

/////////////////////////////////ELEMENT_ACCESS////////////////
	reference			operator[] (size_type n);
	const_reference		operator[] (size_type n) const;
	reference			at (size_type n); 
	const_reference		at (size_type n) const; 
	reference			front(void);
	const_reference		front(void) const;
	reference			back(void);
	const_reference		back(void) const;
	value_type*			data(void);
	const value_type*	data(void) const;

private:
	allocator_type		_alloc;
	size_type			_capacity;
	pointer				_begin;
	pointer				_end;






	// reference operator[](size_type n)
	// 	{
	// 		return (*(this->_begin + n));
	// 	}

	
};
};

#include "ft_vector_construction.tpp"
#include "ft_vector_iterators.tpp"
#include "ft_vector_element_access.tpp"
#include "ft_vector_capacity.tpp"
#endif