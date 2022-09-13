/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/13 20:42:56 by kmilchev         ###   ########.fr       */
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
		for(int i = 13; i < 17; i++)
		{
			og_second_map.insert(std::make_pair(i, imaginary_months[16 - i]));
			my_second_map.insert(ft::make_pair(i, imaginary_months[16 - i]));
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
	
	{
		test_name("Testing method single-element erase(key)");
		std::map<int, std::string> og_map;
		ft::map<int, std::string> my_map;
		std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		
		for (size_t i = 1; i <= 12; i++)
		{
			my_map.insert(ft::make_pair(i, months[i - 1]));
			og_map.insert(std::make_pair(i, months[i - 1]));
		}
		assert(og_map.size() == my_map.size());
		assert(og_map.erase(7) == my_map.erase(7));
		for (size_t i = 1; i <= 12; i++)
		{
			if (i != 7)
				assert(og_map.at(i) == my_map.at(i));
			assert(og_map.size() == my_map.size());
			
		}
	}
	
	{
		test_name("Testing method single-element erase(iterator)");
		og_map.erase(og_map.begin());
		my_map.erase(my_map.begin());
		for (size_t i = 1; i <= 12; i++)
		{
			if (i != 7 && i != 1)
				assert(og_map.at(i) == my_map.at(i));
			assert(og_map.size() == my_map.size());
			
		}
	}

	{
		test_name("Testing method range erase");
		ft::map<int, std::string>::iterator my_start_it = my_map.begin();
		ft::map<int, std::string>::iterator my_end_it = my_map.end();
		std::map<int, std::string>::iterator og_start_it = og_map.begin();
		std::map<int, std::string>::iterator og_end_it = og_map.end();
		
		my_map.erase(my_start_it, my_end_it);
		og_map.erase(og_start_it, og_end_it);
		assert(og_map.size() == my_map.size());
	}

	{
		test_name("Testing method single-element erase(key) - no element");
		my_map.erase(22);
		og_map.erase(22);
	}

	{
		test_name("Testing method clear()");
		for (size_t i = 1; i <= 12; i++)
		{
			my_map.insert(ft::make_pair(i, months[i - 1]));
			og_map.insert(std::make_pair(i, months[i - 1]));
		}
		og_map.clear();
		my_map.clear();
		assert(og_map.size() == my_map.size());
	}

	{
		test_name("Testing method swap()");
		std::string imaginary_months[4] ={	"Confusion",
											"More Confusion",
											"Endless Confusion",
											"Confusion Ended"};
		ft::map<int, std::string> my_second_map;
		std::map<int, std::string> og_second_map;
		
		for(int i = 1; i < 5; i++)
		{
			og_second_map.insert(std::make_pair(i, imaginary_months[i - 1]));
			my_second_map.insert(ft::make_pair(i, imaginary_months[i - 1]));
		}
		for (size_t i = 1; i <= 12; i++)
		{
			my_map.insert(ft::make_pair(i, months[i - 1]));
			og_map.insert(std::make_pair(i, months[i - 1]));
		}
		og_map.swap(og_second_map);
		my_map.swap(my_second_map);
		assert(og_map.at(1) == my_map.at(1));
		assert(og_map.at(4) == my_map.at(4));
		assert(og_second_map.at(1) == my_second_map.at(1));
		assert(og_second_map.at(8) == my_second_map.at(8));
	}
}