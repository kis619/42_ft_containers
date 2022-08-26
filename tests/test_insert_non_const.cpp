/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert_non_const.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:50:40 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/26 19:33:47 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include "colours.h"
#include <vector>
#include <iterator>
#include <iostream>


int main(void)
{
	const ft::vector<int> const_nums(5, 5);
	const std::vector<int> og_const_nums(5, 5);
	std::vector<int> og_nums;
	ft::vector<int> my_nums;

	for(int i = 0; i < 5; i++)
	{
		og_nums.push_back(i);
		my_nums.push_back(i);
	}

	// og_const_nums.insert(og_nums.begin(), og_nums.begin(), og_nums.end());
	// const_nums.insert(my_nums.begin(), my_nums.begin(), my_nums.end());
	og_nums.insert(og_const_nums.begin(), og_const_nums.begin(), og_const_nums.end());
	// my_nums.insert(const_nums.begin(), const_nums.begin(), const_nums.end());
	my_nums.insert(const_nums.begin(), const_nums.begin(), const_nums.end());
	og_nums.shrink_to_fit();
	
}