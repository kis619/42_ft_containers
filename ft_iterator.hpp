/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:45:10 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/19 21:44:06 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR
# define ITERATOR

#include "ft_iterator_traits.hpp"

namespace ft
{
	template<typename T>
	class random_access_iteratorRRRR : public ft::iterator<random_access_iterator_tag, T>
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
		// random_access_iteratorRRRR(void) : _i(nullptr){};
		explicit random_access_iteratorRRRR(pointer el) : _i(el){}; //not sure if need to be explicit
		// random_access_iteratorRRRR(const random_access_iteratorRRRR& copy) : _i(copy._i) {};
		// virtual ~random_access_iteratorRRRR(void) {};
		// random_access_iteratorRRRR & operator=(const random_access_iteratorRRRR other) {_i = other._i; return(*this);};
		pointer		base() const {return (_i);};
		// reference	operator*(void) const {return (*_i);};
		// pointer		operator->(void) const ;
		// random_access_iteratorRRRR operator++(int);

	
	};
}

#endif