/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_traits.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:12:51 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/21 17:18:03 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS
#include <cstddef>

namespace ft
{
	//iterator base class
	//https://cplusplus.com/reference/iterator/iterator/
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
	
	//iterator categories
	struct input_iterator_tag 													{};
	struct output_iterator_tag													{};
	struct forward_iterator_tag	: public input_iterator_tag						{};
	struct bidirectional_iterator_tag : public forward_iterator_tag				{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag		{};

	//iterator_traits
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	// iterator_traits speacialisation
	template<typename T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};
	
	//iterator_traits speacialisation const
	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

}

#endif