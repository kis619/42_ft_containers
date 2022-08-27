/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/27 20:44:19 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "colours.h"
#include <assert.h>
#include "utils.hpp"

int main(void)
{
	ft::vector<int> nums(10, 44);
	ft::vector<int> nums2(3, 33);

	test_name("Initialising an iterator");
	ft::vector<int>::iterator it0;
	ft::vector<int>::iterator it(nums.begin());
	ft::vector<int>::iterator it2 = nums2.begin();
	ft::vector<int>::iterator *it3 = &it2;
	ft::vector<int>::const_iterator it4;
	ft::vector<int>::const_iterator it5;

	test_name("Testing the equals operator");
	it = it2;
	assert(33 == *(it.base()));
	
	test_name("Testing the equals operator with a const");
	it4 = it2;
	assert(33 == *(it4.base()));
	
	test_name("Testing method base()");
	assert(33 == *(it4.base()));
	
	test_name("Testing operator*");
	assert(33 == *it);
	
	test_name("Testing the operator->" );
	assert(it.base() == it.operator->());
	
	test_name("Testing the operator[]" );
	it[0] = 7; it[1] = 8; it[2] = 9;
	assert(7 == *it);
	assert(8 == it[1]);
	assert(9 == it[2]);

	test_name("Testing the operator++(int) (post-increment)");
	assert(7 == *(it++));
	assert(8 == *it);
	
	test_name("Testing the operator++ (pre-increment)");
	assert(9 == *(++it));
	
	test_name("Testing the operator--(int) (post-decrement)");
	assert(9 == *(it--));
	assert(8 == *it);
	
	test_name("Testing the operator-- (pre-decrement)");
	assert(7 == *(--it));
	
	test_name("Testing the operator+");
	assert(9 == *(it + 2));
	
	test_name("Testing the operator+=");
	it += 2;
	assert(9 == *it);
	
	test_name("Testing the operator-");
	assert(7 == *(it - 2));
	
	test_name("Testing the operator-=");
	it -= 2;
	assert(7 == *it);

	test_name("Testing the operator==");
	ft::vector<int>::iterator new_it;
	assert(true == (it == it2));
	assert(false == (it == new_it));
	
	test_name("Testing the operator<");
	assert(true == (it < (it + 1)));
	assert(false == (it < it2));
	
	test_name("Testing the operator!=");
	assert(true == (it != it2 + 1));
	assert(false == (it != it2));
	
	test_name("Testing the operator>");
	assert(true == (it + 1 > it2));
	assert(false == (it > it2));
	
	test_name("Testing the operator>=");
	assert(false == (it >= it2 + 1));
	assert(true == (it >= it2));
	
	test_name("Testing the operator<=");
	assert(true == (it <= it2));
	assert(false == (it + 1 <= it2));

	test_name("Testing the operator+ with integer first");
	assert(9 == *(2 + it));
	
	test_name("Testing the operator- with integer first");
	// std::cout << COLOUR_YELLOW << "(it2 + 2).base() is: " << (it2 + 2).base() << std::endl << "it.base() is: " << it.base() << COLOUR_RED << std::endl;
	assert(2 == (it2 + 2) - it);
	
	{
		test_name("Testing the operators with a const iterator");
		assert(true == (it == it4));
		assert(false == (it < it4));
		assert(false == (it != it4));
		assert(false == (it > it4));
		assert(true == (it >= it4));
		assert(true == (it <= it4));
	}
	
	{
		test_name("Testing the operators with two const iterators");
		assert(false == (it5 == it4));
		assert(true == (it5 < it4));
		assert(true == (it5 != it4));
		assert(false == (it5 > it4));
		assert(false == (it5 >= it4));
		assert(true == (it5 <= it4));
	}

	{
		test_name("Testing the const operators with a non-const iterator");
		assert(false == (it5 == it));
		assert(true == (it5 < it));
		assert(true == (it5 != it));
		assert(false == (it5 > it));
		assert(false == (it5 >= it));
		assert(true == (it5 <= it));
	}
	return (0);
}