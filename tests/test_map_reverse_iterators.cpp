/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_reverse_iterators.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/18 18:21:28 by kmilchev         ###   ########.fr       */
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
	std::map<int, int>							og_map;
	std::map<int, int>::reverse_iterator		og_rev_end_it;
	std::map<int, int>::reverse_iterator		og_rev_begin_it;

	ft::map<int, int>							my_map;
	ft::map<int, int>::reverse_iterator			my_rev_end_it;
	ft::map<int, int>::reverse_iterator			my_rev_begin_it;

	for (size_t i = 0; i < number_of_elements; i++)
	{
		my_map.insert(ft::make_pair(i, i + 10));
		og_map.insert(std::make_pair(i, i + 10));
	}
	og_rev_end_it	= og_map.rend();
	og_rev_begin_it	= og_map.rbegin();
	my_rev_begin_it	= my_map.rbegin();
	my_rev_end_it	= my_map.rend();
	test_name("Testing reverse_iterator rbegin");
	for(size_t i = 0; i < number_of_elements; i++)
	{
		assert(og_rev_begin_it->first == my_rev_begin_it->first);
		my_rev_begin_it++;
		og_rev_begin_it++;
	}
	test_name("Testing reverse_iterator rend");
	for(size_t i = 0; i < number_of_elements; i++)
	{
		my_rev_end_it--;
		og_rev_end_it--;
		assert(og_rev_end_it->first == my_rev_end_it->first);
	}
	return (0);
}