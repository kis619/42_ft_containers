/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/12 18:20:10 by kmilchev         ###   ########.fr       */
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
#include <limits>

int main(void)
{
	std::map<int, std::string> og_map;
	ft::map<int, std::string> my_map;
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	test_name("Testing the method .empty()");
	assert(og_map.empty() == my_map.empty());

	{
	test_name("Testing the method .size()");
		assert(og_map.size() == og_map.size());
		my_map.insert(ft::make_pair(1, months[0]));
		og_map.insert(std::make_pair(1, months[0]));
		assert(og_map.size() == og_map.size());
		for (size_t i = 1; i <=12; i++)
		{
			my_map.insert(ft::make_pair(i, months[i - 1]));
			og_map.insert(std::make_pair(i, months[i - 1]));
		}
		assert(og_map.size() == og_map.size());
	}
	
	test_name("Testing the method .max_size()");
	std::cout << COLOUR_GREEN << my_map.max_size() << COLOUR_DEFAULT << std::endl;


	
	return(0);		
}