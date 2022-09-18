/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_logical_operators.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/18 18:41:56 by kmilchev         ###   ########.fr       */
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
	ft::map<int, int> my_map;
	ft::map<int, int> my_empty_map;
	std::map<int, int> og_map;
	std::map<int, int> og_empty_map;
	
	for (size_t i = 0; i < 5; i++)
	{
		my_map.insert(ft::make_pair(i, i + 10));
		og_map.insert(std::make_pair(i, i + 10));
	}
	test_name("Testing operator!=");
		assert(my_map != my_empty_map);

	return (0);
}