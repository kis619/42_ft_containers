/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:57:04 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/24 17:23:51 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "colours.h"

int main(void)
{
	std::vector<int> numbers;
	
	for(int i = 0; i < 10; i++)
		numbers.push_back(i);

	std::vector<int>::iterator it(numbers.begin());
	std::cout << *it <<std::endl;
	std::vector<int>::reverse_iterator rev_it(numbers.rbegin());
	
	std::cout << *rev_it <<std::endl;
	// std::cout << *(numbers.begin()) <<std::endl;
	// std::cout << *(numbers.rbegin()) <<std::endl;

	for (; (*rev_it != *(numbers.begin())); rev_it++)
		std::cout << *rev_it <<std::endl;
	
	// ft::vector<int> nums(7, 77);
	// ft::vector<int>::reverse_iterator rewe(nums.begin() + 1);
	// std::cout << *(rewe) << std::endl;
	
	// rewe[0] = 0;
	// rewe[1] = 1;
	// rewe[2] = 2;
	// rewe[0] = 0;
	// rewe[1] = 1;
	// rewe[2] = 2;
	
	// std::cout << *(rewe);
	// std::vector<int>::reverse_iterator sth;
	// std::vector<int>::iterator sth1;
	// // std::cout << *sth;
	// std::cout << *sth1;
	// std::cout << numbers[0] <<std::endl;
	// std::cout << numbers[1] <<std::endl;
	// std::cout << numbers[2] <<std::endl;
	// std::cout << numbers[3] <<std::endl;
	// std::cout << numbers[4] <<std::endl;
	// std::cout << numbers[5] <<std::endl;
	// std::cout << numbers[6] <<std::endl;
	// std::cout << numbers[7] <<std::endl;
	// std::cout << numbers[8] <<std::endl;
	// std::cout << numbers[9] <<std::endl;
	// std::cout << numbers[10] <<std::endl;
}