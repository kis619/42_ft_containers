/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_construction.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:20:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/27 21:31:35 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include "colours.h"
#include <vector>
#include "utils.hpp"

int main(void)
{
	test_name("Testing the default constructor");
	ft::vector<int> test;
	assert(0 == test.capacity());
	assert(0 == test.size());
	
	test_name("Testing the fill constructor");
	ft::vector<int> test1(4, 69);
	assert(4 == test1.capacity());
	assert(4 == test1.size());
	for (int i = 0; i < test1.size(); i++)
		assert(69 == *(test1.begin()));
	
	{
		test_name("Testing the range constructor");
		ft::vector<int>::iterator it;
		ft::vector<int>::iterator it2;
		ft::vector<int> numbers(6, 33);
		numbers[0] = 23;
		numbers[1] = 14;
		numbers[2] = 51;
		it = numbers.begin();
		it2 = numbers.end();
		ft::vector<int> numbers2(it, it2);
		assert(6 == numbers2.capacity());
		assert(23 == *(numbers2.begin()));
		assert(14 == *(numbers2.begin() + 1));
		assert(51 == *(numbers2.begin() + 2));
		assert(33 == *(numbers2.begin() + 3));
		assert(33 == *(numbers2.begin() + 4));
		assert(33 == *(numbers2.begin() + 5));
	}

	{
		test_name("Testing the copy constructor");
		ft::vector<int> my_numbers(6, 33);
		std::vector<int> og_numbers(6, 33);
		og_numbers.reserve(17);
		my_numbers.reserve(17);
		ft::vector<int> new_vec(my_numbers);
		std::vector<int> new_vec_og(og_numbers);
		
		for (int i = 0; i < new_vec.size(); i++)
			assert((new_vec[i] == og_numbers[i]) == (my_numbers[i] == new_vec_og[i]));
		assert(my_numbers.size() == new_vec.capacity());
		assert(og_numbers.size() == new_vec_og.capacity());
		assert(my_numbers.size() == new_vec_og.capacity());
	}
	
	return (0);
}