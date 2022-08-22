// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_vector_element_access.tpp                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
// /*   Updated: 2022/08/22 13:42:39 by kmilchev         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "ft_vector.hpp"

namespace ft
{
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type n)
	{
		return (*(_begin + n));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type n) const
	{
		return (*(_begin + n));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type n)
	{
		if (n >= size())
			throw std::out_of_range("vector");
		return (*(_begin + n));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type n) const
	{
		if (n >= size())
			throw std::out_of_range("vector");
		return (*(_begin + n));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::front()
	{
		return (*(_begin));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
	{
		return (*(_begin));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::back()
	{
		return (*(_end - 1));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
	{
		return (*(_end - 1));
	}
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::value_type* vector<T, Allocator>::data()
	{
		return (_begin);
	}
	
	template <typename T, typename Allocator>
	const typename vector<T, Allocator>::value_type* vector<T, Allocator>::data() const
	{
		return (_begin);
	}


};
