/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair_construction.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/01 10:49:00 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_utils.hpp"
#include <iostream>
#include "colours.h"
#include <assert.h>
#include "utils.hpp"
#include <string.h>

int main(void)
{
	test_name("Testing the initialisation constructor");
	ft::pair<int, int> my_pair(1, 2);
	std::pair<int, int> og_pair(1, 2);
	assert(og_pair.first == my_pair.first);
	assert(og_pair.second == my_pair.second);
	
	test_name("Testing the copy constructor");
	ft::pair<int, int> my_copy(my_pair);
	assert(my_pair == my_copy);
	
	test_name("Testing the default constructor");
	ft::pair<std::string, int> my_default;
	std::pair<std::string, int> og_default;
	assert(og_default.first == my_default.first);
	assert(og_default.second == my_default.second);

	test_name("Testing the assignment operator");
	ft::pair<int, int> my_pair_for_assignment;
	my_pair_for_assignment = my_pair;
	assert(my_pair_for_assignment == my_pair);
	
	return(0);
}