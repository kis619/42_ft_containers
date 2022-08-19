/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/19 21:39:08 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "tests/colours.h"

int main(void)
{
	ft::vector<int> nums(3, 44);
	ft::vector<int> nums2(3, 33);

	std::cout << "Initialising an iterator " <<std::endl;
	ft::vector<int>::iterator it(nums.begin());
	ft::vector<int>::iterator it2 = nums2.begin();
	ft::vector<int>::iterator *it3 = &it2;
	
	std::cout << COLOUR_BLUE << "Testing operator* and method base()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 44: " << COLOUR_GREEN << *(it.base()) << COLOUR_DEFAULT << std::endl;
	std::cout << COLOUR_BLUE << "Testing the equals operator" << COLOUR_DEFAULT << std::endl;
	it = it2;
	std::cout << "Should be 33: " << COLOUR_GREEN <<  *(it.base()) << COLOUR_DEFAULT << std::endl;
	std::cout << COLOUR_BLUE << "Testing the operator->" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 33: " <<  COLOUR_GREEN << *(it3->base()) << COLOUR_DEFAULT << std::endl;
	std::cout << COLOUR_BLUE << "Testing the operator++(int)" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 33: " <<  COLOUR_GREEN << "hmm" << COLOUR_DEFAULT << std::endl;
	it3++;
	
	std::vector<int>::iterator og;
	std::vector<int>::iterator *gg = &og;
	std::vector<int> nummmm;
	nummmm.push_back(1);
	nummmm.push_back(2);
	nummmm.push_back(3);
	nummmm.push_back(4);
	(og) = nummmm.begin();
	// std::cout << (*og).base();
	std::cout<< gg->base() << std::endl;
	std::cout<< *(gg->base()) << std::endl;
	og++;
	std::cout<< *(gg->base()) << std::endl;
	return (0);
}