/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/12 15:02:59 by kmilchev         ###   ########.fr       */
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
	ft::map<int, std::string> my_map;
	std::map<int, std::string> og_map;
	ft::map<int, std::string>::iterator my_iter;
	std::map<int, std::string>::iterator og_iter;
	std::string months[12] = {	
								"January",
								"February",
								"March",
								"April",
								"May",
								"June",
								"July",
								"August",
								"September",
								"October",
								"November",
								"December"
							};
		

	for(size_t i = 1; i <= 12; i++)
	{
		my_map.insert(ft::make_pair(i, months[i - 1]));
		og_map.insert(std::make_pair(i, months[i - 1]));
	}
	
	{
		test_name("Testing the method .begin()");
		my_iter = my_map.begin();
		og_iter = og_map.begin();
		assert(og_iter->first == my_iter->first);
		my_iter++;
		og_iter++;
		assert(og_iter->first == my_iter->first);
	}
	
	{
		test_name("Testing the method .end()");
		my_iter = my_map.end();
		og_iter = og_map.end();
		my_iter--;
		og_iter--;
		assert(og_iter->first == my_iter->first);
		my_iter--;
		og_iter--;
		my_iter--;
		og_iter--;
		my_iter++;
		og_iter++;
		assert(og_iter->first == my_iter->first);
	}
	return (0);
}