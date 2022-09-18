/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:40:20 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/17 23:12:38 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include "ft_random_access_iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator : public iterator<	typename iterator_traits<Iterator>::iterator_category,
												typename iterator_traits<Iterator>::value_type,
												typename iterator_traits<Iterator>::difference_type,
												typename iterator_traits<Iterator>::pointer,
												typename iterator_traits<Iterator>::reference>
	{
	private: //deprecated
		Iterator _it;
		
	public:
		Iterator current;
		
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
	
		reverse_iterator(void) : _it(), current() {}
		explicit reverse_iterator(iterator_type _x) : _it(_x), current(_x) {}
		template<typename U>
		reverse_iterator(const reverse_iterator<U> &copy) : _it(copy.base()), current(copy.base()) {}
		template<typename U>
		reverse_iterator	&operator=(const reverse_iterator<U> &other) {_it = current = other.base(); return (*this);}
		
		iterator_type		base(void)						const	{return(_it);}
		reference			operator*(void)					const	{iterator_type tmp = current; return *--tmp;}
		pointer				operator->(void)				const	{return (_it.operator->());}
		// pointer				operator->(void)				const	{iterator_type tmp = current; return (&(tmp->first));}
		reverse_iterator	&operator++(void)						{current--; return(*this);}
		reverse_iterator	operator++(int)							{reverse_iterator temp = *this; current--; return (temp);}
		reverse_iterator	&operator--(void)						{current++; return(*this);}
		reverse_iterator	operator--(int)							{reverse_iterator temp = *this; current++; return (temp);}
		reverse_iterator	operator+(difference_type n)	const	{return (reverse_iterator(current - n));}
		reverse_iterator	&operator+=(difference_type n)			{current -= n; return (*this);}
		reverse_iterator	operator-(difference_type n)	const	{return (reverse_iterator(current + n));}
		reverse_iterator	&operator-=(difference_type n)			{current += n; return (*this);}
		reference			operator[](difference_type n)	const	{return (*(*this + n));}
	};
	
	template <class Iter1, class Iter2>
	bool operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
		{return (lhs.base() == rhs.base());}
		
	template <class Iter1, class Iter2>
	bool operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
		{return (lhs.base() > rhs.base());}
		
	template <class Iter1, class Iter2>
	bool operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
		{return (lhs.base() != rhs.base());}
		
	template <class Iter1, class Iter2>
	bool operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
		{return (lhs.base() < rhs.base());}
		
	template <class Iter1, class Iter2>
	bool operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
		{return (lhs.base() <= rhs.base());}
		
	template <class Iter1, class Iter2>
	bool operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
		{return (lhs.base() >= rhs.base());}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{return (y.base() - x.base());}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
		{return (reverse_iterator<Iterator>(x.base() - n));}
}

#endif