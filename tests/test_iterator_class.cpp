/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/26 14:37:13 by kmilchev         ###   ########.fr       */
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
	ft::vector<int>::const_iterator it4;
	ft::vector<int>::const_iterator it5;

	std::cout << COLOUR_BLUE << "Testing the equals operator" << COLOUR_DEFAULT << std::endl;
	it = it2;
	std::cout << "Should be 33: " << COLOUR_GREEN <<  *(it.base()) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the equals operator with a const" << COLOUR_DEFAULT << std::endl;
	it4 = it2;
	std::cout << "Should be 33: " << COLOUR_GREEN <<  *(it4.base()) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing method base()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 33: " << COLOUR_GREEN << *(it.base()) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing operator*" << COLOUR_DEFAULT << std::endl;
	std::cout << "Should be 33: " << COLOUR_GREEN << *it << COLOUR_DEFAULT << std::endl;
	
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
	std::cout << COLOUR_YELLOW << "(it2 + 2).base() is: " << (it2 + 2).base() << std::endl << "it.base() is: " << it.base() << COLOUR_DEFAULT << std::endl;
	std::cout << "(it2 + 2) - (it) should be 2: " << COLOUR_GREEN << (it2 + 2) - (it) << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operators  with a const iterator" << COLOUR_DEFAULT << std::endl;
	if ((it == it4) || (it < it4) || (it != it4) || (it > it4) || (it >= it4) || (it <= it4))
		std::cout << "Success: " << COLOUR_GREEN << "Works with const iterator as well" << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the operators  with two const iterators" << COLOUR_DEFAULT << std::endl;
	if ((it5 == it4) || (it5 < it4) || (it5 != it4) || (it5 > it4) || (it5 >= it4) || (it5 <= it4))
		std::cout << "Success: " << COLOUR_GREEN << "Works with two const iterators as well" << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing the const operators  with a non-const iterator" << COLOUR_DEFAULT << std::endl;
	if ((it5 == it) || (it5 < it) || (it5 != it) || (it5 > it) || (it5 >= it) || (it5 <= it))
		std::cout << "Success: " << COLOUR_GREEN << "Works with const and non-const as well" << COLOUR_DEFAULT << std::endl;
	return (0);
}