/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/12 14:45:24 by kmilchev         ###   ########.fr       */
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
	ft::map<int, int> mappy;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator it2;

	{
		test_name("Testing the method .insert(). Return is pair<iterator, bool>");
		for (size_t i = 1; i <= 10; i++)
		{
			assert(true == mappy.insert(ft::make_pair(i, i + 10)).second);
			assert(false == mappy.insert(ft::make_pair(i, i + 10)).second);
		};
	}

	{
		test_name("Testing the method .at() non-existent key");
		try
		{
			std::cerr << "Expecting an error: ";
			mappy.at(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		test_name("Testing the method .at()");
		assert(11 == mappy.at(1));
	}

	{
		test_name("testing the operator[]");
		std::map<int, std::string> og_map;
		ft::map<int, std::string> my_map;
		std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		for(size_t i = 1; i <= 12; i++)
		{
			my_map.insert(ft::make_pair(i, months[i - 1]));
			og_map.insert(std::make_pair(i, months[i - 1]));
		}
		for (size_t i = 1; i <=13; i++)
			assert(og_map[i] == my_map[i]);
		
	}

	// test_name("Testing the method .insert(): inserting at existing key");
	// {
	// 	std::cout << mappy.insert(ft::make_pair(1, 200))->second;
	// 	assert(11 == mappy.at(1));
	// }
	// it = mappy.begin();
	// std::cout << it->first << std::endl;
	// it = mappy.end();
	// std::cout << it->first << std::endl;
	// std::cout << it->first << std::endl;
	
	// std::map<int, int> mapty;
	// std::map<int, int>::iterator it_m;

	// mapty.insert(std::make_pair(1, 10));
	// // std::cout << mapty.insert(std::make_pair(1, 1097813661364691)).first->second;
	// // // mapty.insert(std::make_pair(2, 20));
	// // // mapty.insert(std::make_pair(3, 30));
	// // // mapty.insert(std::make_pair(4, 40));
	// // std::cout << mapty.at(1) << std::endl;
	// // std::cout << mapty.begin()->second << std::endl;

	// it_m = mapty.begin();
	// it_m++;
	// std::cout << it_m->first << std::endl;
	return (0);
}