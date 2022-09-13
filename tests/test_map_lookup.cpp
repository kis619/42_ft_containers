/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_lookup.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/13 19:45:05 by kmilchev         ###   ########.fr       */
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
	return (0);
}