/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:57:04 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/27 17:46:37 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "colours.h"

int main(void)
{
	ft::vector<int> nums;
	for(int i = 0; i < 10; i++)
		nums.push_back(i);
	ft::vector<int>::reverse_iterator rewe(nums.rbegin());
	ft::vector<int>::reverse_iterator rewe_1(nums.rend() - 1);
	ft::vector<int>::reverse_iterator r;
	
	std::cout << COLOUR_BLUE << "Testing the reverse_iterator method .rbegin()" << COLOUR_RED << std::endl;
	assert(9 == *rewe);
	
	std::cout << COLOUR_BLUE << "Testing the reverse_iterator method .rend()" << COLOUR_RED << std::endl;
	assert(0 == *rewe_1);
	r = nums.rbegin();

	std::cout << COLOUR_BLUE << "Testing the reverse_iterator. Checking if values are in reverse order" << COLOUR_RED << std::endl;
	for(int i = 0; i < nums.size(); i++)
		assert(nums.size() - i - 1 == *(r  + i));// 9 8 7 6 5 4 3 2 1 0
}