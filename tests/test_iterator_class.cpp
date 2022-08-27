/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/27 17:32:46 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "colours.h"
#include <assert.h>

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

	std::cout << COLOUR_BLUE << "Testing the equals operator" << COLOUR_RED << std::endl;
	it = it2;
	assert(33 == *(it.base()));
	
	std::cout << COLOUR_BLUE << "Testing the equals operator with a const" << COLOUR_RED << std::endl;
	it4 = it2;
	assert(33 == *(it4.base()));
	
	std::cout << COLOUR_BLUE << "Testing method base()" << COLOUR_RED << std::endl;
	assert(33 == *(it4.base()));
	
	std::cout << COLOUR_BLUE << "Testing operator*" << COLOUR_RED << std::endl;
	assert(33 == *it);
	
	std::cout << COLOUR_BLUE << "Testing the operator->" << COLOUR_RED << std::endl;
	assert(it.base() == it.operator->());
	
	std::cout << COLOUR_BLUE << "Testing the operator[]" << COLOUR_RED << std::endl;
	it[0] = 7; it[1] = 8; it[2] = 9;
	assert(7 == *it);
	assert(8 == it[1]);
	assert(9 == it[2]);

	std::cout << COLOUR_BLUE << "Testing the operator++(int) (post-increment)" << COLOUR_RED << std::endl;
	assert(7 == *(it++));
	assert(8 == *it);
	
	std::cout << COLOUR_BLUE << "Testing the operator++ (pre-increment)" << COLOUR_RED << std::endl;
	assert(9 == *(++it));
	
	std::cout << COLOUR_BLUE << "Testing the operator--(int) (post-decrement)" << COLOUR_RED << std::endl;
	assert(9 == *(it--));
	assert(8 == *it);
	
	std::cout << COLOUR_BLUE << "Testing the operator-- (pre-decrement)" << COLOUR_RED << std::endl;
	assert(7 == *(--it));
	
	std::cout << COLOUR_BLUE << "Testing the operator+" << COLOUR_RED << std::endl;
	assert(9 == *(it + 2));
	
	std::cout << COLOUR_BLUE << "Testing the operator+=" << COLOUR_RED << std::endl;
	it += 2;
	assert(9 == *it);
	
	std::cout << COLOUR_BLUE << "Testing the operator-" << COLOUR_RED << std::endl;
	assert(7 == *(it - 2));
	
	std::cout << COLOUR_BLUE << "Testing the operator-=" << COLOUR_RED << std::endl;
	it -= 2;
	assert(7 == *it);

	std::cout << COLOUR_BLUE << "Testing the operator==" << COLOUR_RED << std::endl;
	ft::vector<int>::iterator new_it;
	assert(true == (it == it2));
	assert(false == (it == new_it));
	
	std::cout << COLOUR_BLUE << "Testing the operator<" << COLOUR_RED << std::endl;
	assert(true == (it < (it + 1)));
	assert(false == (it < it2));
	
	std::cout << COLOUR_BLUE << "Testing the operator!=" << COLOUR_RED << std::endl;
	assert(true == (it != it2 + 1));
	assert(false == (it != it2));
	
	std::cout << COLOUR_BLUE << "Testing the operator>" << COLOUR_RED << std::endl;
	assert(true == (it + 1 > it2));
	assert(false == (it > it2));
	
	std::cout << COLOUR_BLUE << "Testing the operator>=" << COLOUR_RED << std::endl;
	assert(false == (it >= it2 + 1));
	assert(true == (it >= it2));
	
	std::cout << COLOUR_BLUE << "Testing the operator<=" << COLOUR_RED << std::endl;
	assert(true == (it <= it2));
	assert(false == (it + 1 <= it2));

	std::cout << COLOUR_BLUE << "Testing the operator+ with integer first" << COLOUR_RED << std::endl;
	assert(9 == *(2 + it));
	
	std::cout << COLOUR_BLUE << "Testing the operator-  with integer first" << COLOUR_RED << std::endl;
	// std::cout << COLOUR_YELLOW << "(it2 + 2).base() is: " << (it2 + 2).base() << std::endl << "it.base() is: " << it.base() << COLOUR_RED << std::endl;
	assert(2 == (it2 + 2) - it);
	
	std::cout << COLOUR_BLUE << "Testing the operators  with a const iterator" << COLOUR_RED << std::endl;
	assert(true == (it == it4));
	assert(false == (it < it4));
	assert(false == (it != it4));
	assert(false == (it > it4));
	assert(true == (it >= it4));
	assert(true == (it <= it4));
	
	std::cout << COLOUR_BLUE << "Testing the operators  with two const iterators" << COLOUR_RED << std::endl;
	assert(false == (it5 == it4));
	assert(true == (it5 < it4));
	assert(true == (it5 != it4));
	assert(false == (it5 > it4));
	assert(false == (it5 >= it4));
	assert(true == (it5 <= it4));

	std::cout << COLOUR_BLUE << "Testing the const operators  with a non-const iterator" << COLOUR_RED << std::endl;
	assert(false == (it5 == it));
	assert(true == (it5 < it));
	assert(true == (it5 != it));
	assert(false == (it5 > it));
	assert(false == (it5 >= it));
	assert(true == (it5 <= it));
	return (0);
}