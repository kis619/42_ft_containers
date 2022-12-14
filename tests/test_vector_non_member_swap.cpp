/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_non_member_swap.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zangelis <zangelis@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/03 00:22:36 by zangelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "colours.h"
#include "utils.hpp"

int main(void)
{
	ft::vector<int> v1(2, 2);
	ft::vector<int> v2(3, 3);
	ft::vector<int> v1_copy(v1);
	ft::vector<int> v2_copy(v2);

	{
		test_name("Test swap");
		//befor swap
		for (size_t i = 0; i < v1.size(); i++)
			assert(v1_copy[i] == v1[i]);
			
		ft::swap(v1, v2);
		//after swap
		for (size_t i = 0; i < v1_copy.size(); i++)
			assert(v1_copy[i] == v2[i]);
		assert(v1_copy.capacity() == v2.capacity());
		assert(v1_copy.size() == v2.size());
		
		for (size_t i = 0; i < v1.size(); i++)
			assert(v2_copy[i] == v1[i]);
		assert(v2_copy.capacity() == v1.capacity());
		assert(v2_copy.size() == v1.size());
	}
	std::cout << COLOUR_DEFAULT;
}