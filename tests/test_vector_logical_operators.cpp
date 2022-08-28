/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_logical_operators.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/28 21:58:48 by kmilchev         ###   ########.fr       */
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
	ft::vector<int> nums2(nums);

	test_name("Testing logical operator ==");
	assert(true == (nums == nums2));
	
	test_name("Testing logical operator !=");
	assert(false == (nums != nums2));

	test_name("Testing logical operator <");
	assert(false == (nums < nums2));

	test_name("Testing logical operator <=");
	assert(true == (nums <= nums2));

	test_name("Testing logical operator >");
	assert(false == (nums > nums2));

	test_name("Testing logical operator >=");
	assert(true == (nums >= nums2));
	
}