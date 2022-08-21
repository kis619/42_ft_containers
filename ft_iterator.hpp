/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:45:10 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/21 17:52:25 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR
# define ITERATOR

#include "ft_iterator_traits.hpp"
	#include <iostream>

namespace ft
{
	template <typename T>
	class const_random_access_iterator;
	
	template<typename T>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
	public:	
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	
	private:
		pointer _i;
		
	public:
		random_access_iterator(void) : _i(nullptr){};
		explicit random_access_iterator(pointer el) : _i(el){};
		random_access_iterator(const random_access_iterator &copy) : _i(copy._i) {};
		// virtual ~random_access_iterator(void) {std::cout << "destructor\n";};

		random_access_iterator	&operator=(const random_access_iterator &other) {_i = other._i; return(*this);};
		pointer					base() const {return (_i);};
		reference				operator*(void) const {return (*_i);};
		pointer					operator->(void) const {return(&(operator*()));};
		random_access_iterator	operator++(int) {random_access_iterator temp(*this); _i++; return(temp);}; //post-increment;
		random_access_iterator	&operator++() {_i++; return(*this);}; //post-increment;
		random_access_iterator	operator--(int) {random_access_iterator temp(*this); _i--; return(temp);}; //post-increment;
		random_access_iterator	&operator--() {_i--; return(*this);}; //post-decrement;
		random_access_iterator	operator+(difference_type n) const {return random_access_iterator(_i + n);}
		random_access_iterator	&operator+=(difference_type n) { _i += n; return (*this);}
		random_access_iterator	operator-(difference_type n) const {return random_access_iterator(_i - n);}
		random_access_iterator	&operator-=(difference_type n) { _i -= n; return (*this);}
		reference				operator[](difference_type n) const {return *(_i + n);};
	};
	
	//////LOGICAL OPERATORS
	template<typename Iter1, typename Iter2>
	bool operator==(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() == rhs.base());}
	
	//comparing with const iterators
	template<typename Iter1, typename Iter2>
	bool operator==(const random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() == rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator<(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() < rhs.base());}
		
	//comparing with const iterators
	template<typename Iter1, typename Iter2>
	bool operator<(const random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() < rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator!=(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() != rhs.base());}
		
	//comparing with const iterators
	template<typename Iter1, typename Iter2>
	bool operator!=(const random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() != rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator>(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() > rhs.base());}
		
	//comparing with const iterators
	template<typename Iter1, typename Iter2>
	bool operator>(const random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() > rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator>=(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() >= rhs.base());}
		
	//comparing with const iterators
	template<typename Iter1, typename Iter2>
	bool operator>=(const random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() >= rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator<=(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() <= rhs.base());}
		
	//comparing with const iterators
	template<typename Iter1, typename Iter2>
	bool operator<=(const random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() <= rhs.base());}

	template<typename Iter>
	random_access_iterator<Iter> operator+(typename random_access_iterator<Iter>::difference_type _n, const random_access_iterator<Iter> & _x )
		{return random_access_iterator<Iter>(_x.base() + _n);}
	
	template<typename Iter1>
	ft::random_access_iterator<int>::difference_type operator-(const random_access_iterator<Iter1>& _x, const random_access_iterator<Iter1>& _y)
		{return (_x.base() - _y.base());}

	/*CONSTANT ITERATOR - same but with value_type as a const. Lets me assign a non-const iterator to a const one
	In the original implementation their is a wrapper template class - does not work for my implementation
	typedef __wrap_iter<pointer>                     iterator;
    typedef __wrap_iter<const_pointer>               const_iterator;
	*/
	template<typename T>
	class const_random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
	public:	
		typedef const typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	
	private:
		pointer _i;
		
	public:
		const_random_access_iterator(void) : _i(nullptr){};
		explicit const_random_access_iterator(pointer el) : _i(el){};
		const_random_access_iterator(const const_random_access_iterator &copy) : _i(copy._i) {};
		template <typename U> //constructor from non-const iterator
		const_random_access_iterator(const random_access_iterator<U> &copy) : _i(copy.base()) {}
		// virtual ~const_random_access_iterator(void) {std::cout << "destructor\n";};
		const_random_access_iterator	&operator=(const const_random_access_iterator &other) {_i = other._i; return(*this);};
		pointer							base() const {return (_i);};
		reference						operator*(void) const {return (*_i);};
		pointer							operator->(void) const {return(&(operator*()));};
		const_random_access_iterator	operator++(int) {const_random_access_iterator temp(*this); _i++; return(temp);}; //post-increment;
		const_random_access_iterator	&operator++() {_i++; return(*this);}; //post-increment;
		const_random_access_iterator	operator--(int) {const_random_access_iterator temp(*this); _i--; return(temp);}; //post-increment;
		const_random_access_iterator	&operator--() {_i--; return(*this);}; //post-decrement;
		const_random_access_iterator	operator+(difference_type n) const {return const_random_access_iterator(_i + n);}
		const_random_access_iterator	&operator+=(difference_type n) { _i += n; return (*this);}
		const_random_access_iterator	operator-(difference_type n) const {return const_random_access_iterator(_i - n);}
		const_random_access_iterator	&operator-=(difference_type n) { _i -= n; return (*this);}
		reference						operator[](difference_type n) const {return *(_i + n);};
	};

	template<typename Iter1, typename Iter2>
	bool operator==(const const_random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() == rhs.base());}
	
	//comparing with non-const iterators
	template<typename Iter1, typename Iter2>
	bool operator==(const const_random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() == rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator<(const const_random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() < rhs.base());}
		
	//comparing with non-const iterators
	template<typename Iter1, typename Iter2>
	bool operator<(const const_random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() < rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator!=(const const_random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() != rhs.base());}
		
	//comparing with non-const iterators
	template<typename Iter1, typename Iter2>
	bool operator!=(const const_random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() != rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator>(const const_random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() > rhs.base());}
		
	//comparing with non-const iterators
	template<typename Iter1, typename Iter2>
	bool operator>(const const_random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() > rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator>=(const const_random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() >= rhs.base());}
		
	//comparing with non-const iterators
	template<typename Iter1, typename Iter2>
	bool operator>=(const const_random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() >= rhs.base());}
		
	template<typename Iter1, typename Iter2>
	bool operator<=(const const_random_access_iterator<Iter1> &lhs, const const_random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() <= rhs.base());}
		
	//comparing with non-const iterators
	template<typename Iter1, typename Iter2>
	bool operator<=(const const_random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2>  &rhs)
		{return (lhs.base() <= rhs.base());}
}

#endif