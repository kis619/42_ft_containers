/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/13 01:06:05 by kmilchev         ###   ########.fr       */
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
	
	{
		test_name("Testing method single-element insert()");
		for (size_t i = 1; i <= 12; i++)
		{
			assert(true == my_map.insert(ft::make_pair(i, months[i - 1])).second);
			og_map.insert(std::make_pair(i, months[i - 1]));
			assert(og_map.at(i) == my_map.at(i));
		}
	}

	{
		test_name("Testing method range insert()");
		std::string imaginary_months[4] ={	"Confusion",
											"More Confusion",
											"Endless Confusion",
											"Confusion Ended"};
		ft::map<int, std::string>::iterator my_it;
		ft::map<int, std::string>::iterator my_end_it;
		std::map<int, std::string>::iterator og_it;
		std::map<int, std::string>::iterator og_end_it;
		ft::map<int, std::string> my_second_map;
		std::map<int, std::string> og_second_map;
		int i = 13;
		for(std::string month : imaginary_months)
		{
			og_second_map.insert(std::make_pair(i, month));
			my_second_map.insert(ft::make_pair(i, month));
			i++;
		}
		my_it = my_second_map.begin();
		og_it = og_second_map.begin();
		my_end_it = my_second_map.end();
		og_end_it = og_second_map.end();
		
		my_map.insert(my_it, my_end_it);
		og_map.insert(og_it, og_end_it);

		for (size_t i = 1; i <= 16; i++)
			assert(og_map.at(i) == my_map.at(i));
	}

	{
		test_name("Testing method hint insert()");
		std::map<int, std::string> og_map;
		ft::map<int, std::string> my_map;
		std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		ft::map<int, std::string>::iterator my_iter;
		std::map<int, std::string>::iterator og_iter;
		{
			test_name("Testing method single-element insert()");
			for (size_t i = 1; i <= 11; i++)
			{
				assert(true == my_map.insert(ft::make_pair(i, months[i - 1])).second);
				og_map.insert(std::make_pair(i, months[i - 1]));
				assert(og_map.at(i) == my_map.at(i));
			}
			my_iter = my_map.end();
			og_iter = og_map.end();
			
			my_map.insert(my_iter, ft::make_pair(12, months[11]));
			og_map.insert(og_iter, std::make_pair(12, months[11]));
			assert(og_map.size() == my_map.size());
			assert(og_map.at(12) == my_map.at(12));
		}
	}
}