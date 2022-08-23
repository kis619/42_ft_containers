/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_modifiers.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:44:55 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/23 11:47:58 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"

namespace ft
{
	template <typename T, typename Allocator>
	void vector<T, Allocator>::clear(void)
	{
		size_type old_size = size();
		
		for(int i = 0; i < old_size; i++)
		{
			_end--;
			_alloc.destroy(_end);
		}
	}
	
	template <typename T, typename Allocator>
	void vector<T, Allocator>::pop_back(void)
	{
		_alloc.destroy(&back());
		_end--;
	}
	
	template <typename T, typename Allocator>
	void vector<T, Allocator>::adjust_capacity(void)
	{
		if (size() > _capacity)
		{
			
		}
	}
	
	
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator(void) const
	{
		return(_alloc);
	}
};
