/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_lookup.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/16 18:18:48 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "../ft_map.hpp"
#include "../ft_vector.hpp"
#include "../ft_tree.hpp"
#include "colours.h"
#include "utils.hpp"
#include <map>
#include <typeinfo>

int main(void)
{
	ft::map<int, std::string> my_map;
	std::map<int, std::string> og_map;
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	for (size_t i = 1; i <= 12; i++)
	{
		og_map.insert(std::make_pair(i, months[i - 1]));
		my_map.insert(ft::make_pair(i, months[i - 1]));
	}
	
	{
	test_name("Testing method .count()");
		for (size_t i = 5; i <= 20; i++)
		{
			assert(og_map.count(i) == my_map.count(i));
		}
	}

	{	
	test_name("Testing method .find()");
		
		ft::map<int, std::string>::iterator my_iter;
		std::map<int, std::string>::iterator og_iter;

		assert(og_map.find(3)->second == my_map.find(3)->second);
		my_iter = my_map.find(245);
		og_iter = og_map.find(245);
		my_iter--;
		og_iter--;
		assert(og_iter->second == my_iter->second);
	}
	
	{
	test_name("Testing method .lower_bound()");

		ft::map<int, std::string>::iterator my_iter;
		std::map<int, std::string>::iterator og_iter;
		
		og_iter = og_map.lower_bound(13);
		my_iter = my_map.lower_bound(13);
		og_iter--;
		my_iter--;
		assert(og_iter->second == my_iter->second);
		og_map.insert(std::make_pair(17, "Confusion"));
		og_map.insert(std::make_pair(16, "16Confusion"));
		my_map.insert(ft::make_pair(17, "Confusion"));
		my_map.insert(ft::make_pair(16, "16Confusion"));
		og_iter = og_map.lower_bound(13);
		my_iter = my_map.lower_bound(13);
		assert(og_iter->second == my_iter->second);
	}
	
	{
	test_name("Testing method .upper_bound()");

		ft::map<int, std::string>::iterator my_iter;
		std::map<int, std::string>::iterator og_iter;
		
		og_iter = og_map.upper_bound(0);
		my_iter = my_map.upper_bound(0);
		assert(og_iter->second == my_iter->second);
		og_map.insert(std::make_pair(17, "Confusion"));
		og_map.insert(std::make_pair(16, "16Confusion"));
		my_map.insert(ft::make_pair(17, "Confusion"));
		my_map.insert(ft::make_pair(16, "16Confusion"));
		og_iter = og_map.upper_bound(13);
		my_iter = my_map.upper_bound(13);
		assert(og_iter->second == my_iter->second);
	}
	
	{
	test_name("Testing method .equal_range()");

		ft::map<int, std::string>::iterator my_iter;
		std::map<int, std::string>::iterator og_iter;
		
		std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator > og_range;
		ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator > my_range;
		og_range = og_map.equal_range(3);
		my_range = my_map.equal_range(3);
		assert(og_range.first->first == my_range.first->first);
		assert(og_range.first->second == my_range.first->second);
		assert(og_range.second->first == my_range.second->first);
		assert(og_range.second->second == my_range.second->second);
		og_range = og_map.equal_range(18);
		my_range = my_map.equal_range(18);
		og_range.first--;
		og_range.second--;
		my_range.first--;
		my_range.second--;
		assert(og_range.first->first == my_range.first->first);
		assert(og_range.first->second == my_range.first->second);
		assert(og_range.second->first == my_range.second->first);
		assert(og_range.second->second == my_range.second->second);
	}
	std::cout << COLOUR_DEFAULT;
	return (0);
}