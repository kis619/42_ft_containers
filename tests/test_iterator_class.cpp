/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/21 15:06:46 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "colours.h"

int main(void)
{
	ft::vector<int> nums(10, 44);
	ft::vector<int> nums2(3, 33);

	std::cout << "Initialising an iterator " <<std::endl;
	ft::vector<int>::iterator it0;
	ft::vector<int>::iterator it(nums.begin());
	ft::vector<int>::iterator it2 = nums2.begin();
	ft::vector<int>::iterator *it3 = &it2;

	
	std::cout << COLOUR_BLUE << "Testing the equals operator" << COLOUR_DEFAULT << std::endl;
	it = it2;
	std::cout << "Should be 33: " << COLOUR_GREEN <<  *(it.base()) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing method base()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 44: " << COLOUR_GREEN << *(it.base()) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing operator*" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 44: " << COLOUR_GREEN << *it << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator->" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be an address: " <<  COLOUR_GREEN << it.operator->() << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator[]" << COLOUR_DEFAULT << std::endl;
	it[0] = 7;
	it[1] = 8;
	it[2] = 9;
	std::cout << "Should be 7: " <<  COLOUR_GREEN << *it << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 8: " <<  COLOUR_GREEN << it[1] << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 9: " <<  COLOUR_GREEN << it[2] << COLOUR_DEFAULT << std::endl;

	std::cout << COLOUR_BLUE << "Testing the operator++(int) (post-increment)" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 7: " <<  COLOUR_GREEN << *(it++) << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 8: " <<  COLOUR_GREEN << *it<< COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator++ (pre-increment)" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 9: " <<  COLOUR_GREEN << *(++it) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator--(int) (post-decrement)" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 9: " <<  COLOUR_GREEN << *(it--) << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 8: " <<  COLOUR_GREEN << *it<< COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator-- (pre-decrement)" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 7: " <<  COLOUR_GREEN << *(--it) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator+" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 9: " <<  COLOUR_GREEN << *(it + 2) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator+=" << COLOUR_DEFAULT << std::endl;
	it += 2;
	std::cout << "Should be 9: " <<  COLOUR_GREEN << *it << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator-" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 7: " <<  COLOUR_GREEN << *(it - 2) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator-=" << COLOUR_DEFAULT << std::endl;
	it -= 2;
	std::cout << "Should be 7: " <<  COLOUR_GREEN << *it << COLOUR_DEFAULT << std::endl;

	std::cout << COLOUR_BLUE << "Testing the operator==" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be true: " << COLOUR_GREEN << std::boolalpha << (it == it2) << COLOUR_DEFAULT << std::endl;
	ft::vector<int>::iterator new_it;
	std::cout << "Should be false: " << COLOUR_GREEN << std::boolalpha << (it == new_it) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator<" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be false: " << COLOUR_GREEN << std::boolalpha << (it < it2) << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be true: " << COLOUR_GREEN << std::boolalpha << (it < (it2 + 1)) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator!=" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be false: " << COLOUR_GREEN << std::boolalpha << (it != it2) << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be true: " << COLOUR_GREEN << std::boolalpha << (it != (it2 + 1)) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator>" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be false: " << COLOUR_GREEN << std::boolalpha << (it > it2) << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be true: " << COLOUR_GREEN << std::boolalpha << (it + 1 > it2) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator>=" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be true: " << COLOUR_GREEN << std::boolalpha << (it >= it2) << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be false: " << COLOUR_GREEN << std::boolalpha << (it >= (it2 + 1)) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator<=" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be true: " << COLOUR_GREEN << std::boolalpha << (it <= it2) << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be false: " << COLOUR_GREEN << std::boolalpha << (it + 1 <= it2) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator+ with integer first" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 9: " << COLOUR_GREEN << *(2 + it) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operator-  with integer first" << COLOUR_DEFAULT << std::endl;
	std::cout << COLOUR_YELLOW << "*(it2) is: " << *(it2) << std::endl << "*(it) is: " << *(it) << COLOUR_DEFAULT << std::endl;
	std::cout << "(it2 + 2) - (it) should be 2: " << COLOUR_GREEN << (it2 + 2) - (it) << COLOUR_DEFAULT << std::endl;


	// std::vector<int>::iterator og;
	// std::vector<int>::iterator nog;
	// std::vector<int> nummmm;
	// nummmm.push_back(1);
	// nummmm.push_back(2);
	// nummmm.push_back(3);
	// nummmm.push_back(4);
	// (og) = nummmm.begin();
	// nog = nummmm.begin();
	// std::cout << *(og.base()) << std::endl;
	// 1 + og;

	// std::cout << 	nog - og << std::endl;
	// nog = og;
	// og[0] = 2341234;
	// std::cout << nog[0] << std::endl;
	// if (og == nog)
	// 	std::cout << COLOUR_GREEN << "Equal\n";
	return (0);
}