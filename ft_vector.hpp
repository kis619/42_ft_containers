/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:08:20 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/17 13:39:22 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef typename allocator_type::pointer	pointer;
		//default constructor 
			explicit vector (const allocator_type& alloc = allocator_type());
			int something(int);

		private:
			allocator_type		_alloc;
			pointer				_capacity;
			pointer				_begin;
			pclose				_end;
		
	};
};

#endif