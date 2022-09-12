/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_element_access.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/12 15:03:44 by kmilchev         ###   ########.fr       */
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

int main(void)
{
	std::map<int, std::string> og_map;
	ft::map<int, std::string> my_map;
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		

	for(size_t i = 1; i <= 12; i++)
	{
		my_map.insert(ft::make_pair(i, months[i - 1]));
		og_map.insert(std::make_pair(i, months[i - 1]));
	}
	
	{
		test_name("Testing the method .at()");
		for (size_t i = 1; i <=13; i++)
			assert(og_map[i] == my_map[i]);
	}

	{
		test_name("Testing the method .at() non-existent key");
		try
		{
			std::cerr << "Expecting an error: ";
			my_map.at(13);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	{
		test_name("testing the operator[]");
		for (size_t i = 1; i <=13; i++)
			assert(og_map[i] == my_map[i]);
		
	}

	return (0);
}