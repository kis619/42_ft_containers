/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_reverse_iterators.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/18 16:24:10 by kmilchev         ###   ########.fr       */
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
#define number_of_elements 10
int main(void)
{
	std::map<int, int> og_map;
	// std::map<int, int>::reverse_iterator og_rev_end_it;
	// std::map<int, int>::reverse_iterator og_rev_begin_it;
	for (size_t i = 0; i < number_of_elements; i++)
	{
		std::cout << og_map.insert(std::make_pair(i, i + 10)).first->first;
	}

	// og_rev_end_it = og_map.rend();
	// og_rev_begin_it = og_map.rbegin();
	// // og_rev_begin_it++;
	// for(size_t i = 0; i < number_of_elements; i++)
	// {
	// 	og_rev_begin_it++;
	// 	assert(number_of_elements - 1 - i == og_rev_begin_it.base()->first);
	// 	assert(i == og_rev_end_it.base()->first);
	// 	og_rev_end_it--;
	// }

	ft::map<int, int>					my_map;
	// ft::map<int, int>::reverse_iterator my_rev_end_it;
	ft::map<int, int>::reverse_iterator my_rev_begin_it;

	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator it3;
	std::map<int, int>::iterator it2;
	
	// it->
	for (size_t i = 0; i < number_of_elements; i++)
	{
		std::cout << my_map.insert(ft::make_pair(i, i + 10)).first->first;
	}
	my_rev_begin_it = my_map.rbegin();
	it = my_map.begin();
	std::cout << it->first << std::endl;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	std::cout << it->first << std::endl;
	it3 = it;
	// it3->
	std::cout << it3->first << std::endl;
	for(size_t i = 0; i < number_of_elements; i++)
	{
		my_rev_begin_it++;
	}
	return (0);
}