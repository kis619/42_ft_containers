/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:08:20 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/24 18:25:14 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stack>
#include "ft_iterator.hpp"
#include "ft_utils.hpp"
#include <stdexcept>

// using std::enable_if; ///need to re-write those two
using std::is_integral; //

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
			typename enable_if<!is_integral<InputIterator>::value>::type* = NULL);
//copy constructor
	vector (const vector& x); //TBD

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

/////////////////////////////////CAPACITY//////////////////////
	size_type	size(void) const;
	size_type	max_size(void) const;
	void		resize (size_type n, value_type val = value_type());
	size_type	capacity(void) const;
	bool		empty(void) const;
	void		reserve (size_type n);

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

/////////////////////////////////MODIFIERS/////////////////////
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = NULL);
	void assign (size_type n, const value_type& val);
	void pop_back(void);
	void push_back (const value_type &val);
	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);
	// template <class InputIterator>
	// void insert (iterator position, InputIterator first, InputIterator last);
	// iterator erase (iterator position);
	// iterator erase (iterator first, iterator last);
	////////?SWAP
	void clear(void);

/////////////////////////////////ALLOCATOR/////////////////////
	allocator_type get_allocator(void) const;



/////////////////////////////////MISCELANIOUS/////////////////////
	private:
		size_type adjust_capacity(int n = 0); //depending on size and capacity
private:
	allocator_type		_alloc;
	size_type			_capacity;
	pointer				_begin;
	pointer				_end;

};
};

#include "ft_vector_construction.tpp"
#include "ft_vector_iterators.tpp"
#include "ft_vector_element_access.tpp"
#include "ft_vector_capacity.tpp"
#include "ft_vector_modifiers.tpp"
#endif