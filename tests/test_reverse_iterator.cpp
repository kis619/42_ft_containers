/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zangelis <zangelis@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:57:04 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/03 00:45:49 by zangelis         ###   ########.fr       */
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
	ft::vector<int> nums;
	for(int i = 0; i < 10; i++)
		nums.push_back(i);
	ft::vector<int>::reverse_iterator rewe(nums.rbegin());
	ft::vector<int>::reverse_iterator rewe_1(nums.rend() - 1);
	ft::vector<int>::reverse_iterator r;
	
	test_name("Testing the reverse_iterator method .rbegin()");
	assert(9 == *rewe);
	
	test_name("Testing the reverse_iterator method .rend()");
	assert(0 == *rewe_1);
	r = nums.rbegin();

	test_name("Testing the reverse_iterator. Checking if values are in reverse order");
	for(size_t i = 0; i < nums.size(); i++)
		assert(int(nums.size() - i - 1) == *(r  + i));// 9 8 7 6 5 4 3 2 1 0
	std::cout << COLOUR_DEFAULT;
}