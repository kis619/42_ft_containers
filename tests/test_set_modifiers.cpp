/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:39:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 13:29:57 by kmilchev         ###   ########.fr       */
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
		test_name("Testing the method .clear()");
		my_set.clear();
		og_set.clear();
		assert(og_set.empty() == my_set.empty());
	}

	{
		test_name("Testing the method .insert()");
		ft::set<float> my_set;
		std::set<float> og_set;
		for (size_t i = 0; i < 10; i++)
		{
			assert(my_set.insert(i + 0.9).second == og_set.insert(i + 0.9).second);
			assert(*(my_set.insert(i + 0.9).first) == *(og_set.insert(i + 0.9).first));
		}
		assert(og_set.size() == my_set.size());
	}
	
	{
		test_name("Testing the method .insert() with a hint");
		ft::set<float> my_set;
		std::set<float> og_set;
		ft::set<float>::iterator my_it;
		std::set<float>::iterator og_it;
		for (size_t i = 0; i < 10; i++)
		{
			my_it = my_set.insert(my_set.begin() , i);
			og_it = og_set.insert(og_set.begin() , i);
			assert(*my_it == *og_it);
		}
		assert(og_set.size() == my_set.size());
	}
	
	{
		test_name("Testing the method .insert() range");
		ft::set<float> my_set;
		std::set<float> og_set;
		ft::set<float>::iterator my_it;
		std::set<float>::iterator og_it;
		for (size_t i = 0; i < 10; i++)
		{
			my_it = my_set.insert(my_set.begin() , i);
			og_it = og_set.insert(og_set.begin() , i);
		}
		ft::set<float> my_second_set;
		std::set<float> og_second_set;

		my_second_set.insert(my_set.begin(), my_set.end());
		og_second_set.insert(og_set.begin(), og_set.end());
		assert(og_second_set.size() == my_second_set.size());
		assert(my_set == my_second_set);
	}

	{
		test_name("Testing the method .erase() iterator");
		ft::set<float> my_set;
		std::set<float> og_set;
		ft::set<float>::iterator my_it;
		std::set<float>::iterator og_it;
		for (size_t i = 0; i < 10; i++)
		{
			my_set.insert(i + 0.9);
			og_set.insert(i + 0.9);
		}
		
		my_set.erase(my_set.begin());
		og_set.erase(og_set.begin());
		assert(og_set.size() == my_set.size());
		
		my_it = my_set.begin();
		og_it = og_set.begin();
		for(; og_it != og_set.end(); og_it++, my_it++)
			assert(*og_it == *my_it);
	}

	{
		test_name("Testing the method .erase() range");
		ft::set<float> my_set;
		std::set<float> og_set;
		ft::set<float>::iterator my_it;
		std::set<float>::iterator og_it;
		for (size_t i = 0; i < 10; i++)
		{
			my_set.insert(i + 0.9);
			og_set.insert(i + 0.9);
		}
		
		my_set.erase(my_set.begin(), my_set.end());
		og_set.erase(og_set.begin(), og_set.end());
		assert(og_set.size() == my_set.size());
		assert(my_set.empty() == og_set.empty());
	}

	{
		test_name("Testing the method .erase() key");
		ft::set<float> my_set;
		std::set<float> og_set;
		ft::set<float>::iterator my_it;
		std::set<float>::iterator og_it;
		for (size_t i = 0; i < 10; i++)
		{
			my_set.insert(i + 0.9);
			og_set.insert(i + 0.9);
		}
		
		my_set.erase(1.9);
		og_set.erase(1.9);
		assert(og_set.size() == my_set.size());
		my_set.erase(1245);
		og_set.erase(1245);
		assert(og_set.size() == my_set.size());
		
		my_it = my_set.begin();
		og_it = og_set.begin();
		for(; og_it != og_set.end(); og_it++, my_it++)
			assert(*og_it == *my_it);
	}
	
	{
		test_name("Testing the method .swap()");
		ft::set<float> my_initial_set;
		ft::set<float> my_second_set;
		ft::set<float> my_check_set;

		for (size_t i = 0; i < 10; i++)
			my_initial_set.insert(i + 0.9);

		my_check_set = my_initial_set;
		assert(my_check_set == my_initial_set);
		assert(true == my_second_set.empty());

		my_initial_set.swap(my_second_set);
		assert(true == my_initial_set.empty());
		assert(my_check_set == my_second_set);
	}
	
	std::cout << COLOUR_DEFAULT;
	return (0);
}