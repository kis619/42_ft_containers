/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_construction.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:43:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 11:13:27 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_set.hpp"
#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "colours.h"
#include <stack>
#include <vector>
#include <set>
#include "utils.hpp"

int main(void)
{
	test_name("Testing the default constructor");
		ft::set<int>	my_set;

	test_name("Testing the default compare constructor");
		ft::set<int>	my_comp_set(std::less<int> comp);

	test_name("Testing the copy constructor");
		ft::set<int>	my_copied_set(my_set);

	test_name("Testing the range constructor");
		ft::set<int>	my_range_set(my_set.begin(), my_set.end());
		assert(my_range_set == my_set);
		for(size_t i = 0; i < 10; i++)
			my_set.insert(i);
		ft::set<int>	my_second_range_set(my_set.begin(), my_set.end());
		assert(my_second_range_set == my_set);

	test_name("Testing the assignment operator");
		my_second_range_set = my_copied_set;
		assert(my_second_range_set == my_copied_set);

	std::cout << COLOUR_DEFAULT;
	return (0);
}
