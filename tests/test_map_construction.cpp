/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_construction.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/18 18:30:07 by kmilchev         ###   ########.fr       */
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
#include <algorithm>
#include <map>

int main(void)
{
	test_name("Testing the default constructor");
		ft::map <int, int> my_mapty;

	test_name("Testing the copy constructor");
		ft::map <int, int> my_mapty2(my_mapty);

	test_name("Testing the iterator constructor");
	my_mapty.insert(ft::make_pair(1, 2));
	my_mapty.insert(ft::make_pair(2, 2));
	my_mapty.insert(ft::make_pair(3, 2));
	my_mapty.insert(ft::make_pair(4, 2));
	ft::map<int, int> my_iter_map(my_mapty.begin(), my_mapty.end());
	assert(my_mapty == my_iter_map);
	
	test_name("Testing the assignment operator");
	my_mapty2 = my_iter_map;
	assert(my_mapty == my_iter_map);
	
	std::cout << COLOUR_DEFAULT;
	return (0);
}