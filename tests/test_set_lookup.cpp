/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_lookup.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 12:38:04 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "../ft_set.hpp"
#include "colours.h"
#include "utils.hpp"
#include <set>

int main(void)
{
	ft::set<float> my_set;
	std::set<float> og_set;
	ft::set<float>::iterator my_it;
	std::set<float>::iterator og_it;
	for (size_t i = 0; i < 10; i++)
	{
		my_set.insert(i + 0.9);
		og_set.insert(i + 0.9);
	}

	{
		test_name("Testing method .count()");
		for (float i = 0; i < 10; (i += 0.1))
			assert(og_set.count(i) == my_set.count(i));
	}

	{
		test_name("Testing method .find()");
		for (float i = 0; i < 10; (i += 0.1))
		{
			my_it = my_set.find(i);
			og_it = og_set.find(i);
			my_it--;
			og_it--;
			assert(*og_it == *my_it);
		}
	}

	{
		test_name("Testing the method .lower_bound()");
		for (float i = 0; i < 9; (i += 0.1))
		{
			my_it = my_set.lower_bound(i);
			og_it = og_set.lower_bound(i);
			assert(*og_it == *my_it);
		}
		og_it = og_set.lower_bound(10);
		my_it = my_set.lower_bound(10);
		og_it--;
		my_it--;
		assert(*og_it == *my_it);
	}

	{
		test_name("Testing the method .upper_bound()");
		for (float i = 0; i < 10; (i += 0.1))
		{
			og_it = og_set.upper_bound(i - 0.2);
			my_it = my_set.upper_bound(i - 0.2);
			assert(*og_it == *my_it);
		}
		og_it = og_set.upper_bound(13241324);
		my_it = my_set.upper_bound(13241324);
		og_it--;
		my_it--;
		assert(*og_it == *my_it);
	}

	{
		test_name("Testing the method .equal_range()");
		std::pair<std::set<float>::iterator, std::set<float>::iterator> og_range;
		ft::pair<ft::set<float>::iterator, ft::set<float>::iterator> my_range;

		for (float i = 0; i < 9; (i += 0.1))
		{
			og_range = og_set.equal_range(i);
			my_range = my_set.equal_range(i);
			assert(*(og_range.first) == *(my_range.first));
			assert(*(og_range.second) == *(my_range.second));
			
		}
		og_range = og_set.equal_range(10);
		my_range = my_set.equal_range(10);
		og_range.first--;
		my_range.first--;
		og_range.second--;
		my_range.second--;
		assert(*(og_range.first) == *(my_range.first));
		assert(*(og_range.second) == *(my_range.second));
	}
	
	std::cout << COLOUR_DEFAULT;
	return (0);
}