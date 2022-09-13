/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_lookup.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/13 19:17:19 by kmilchev         ###   ########.fr       */
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
#include <typeinfo>

int main(void)
{
	ft::map<int, std::string> my_map;
	std::map<int, std::string> og_map;
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	{
		test_name("Testing method single-element insert()");
		for (size_t i = 1; i <= 12; i++)
		{
			og_map.insert(std::make_pair(i, months[i - 1]));
			my_map.insert(ft::make_pair(i, months[i - 1]));
		}
		for (size_t i = 5; i <= 20; i++)
		{
			assert(og_map.count(i) == my_map.count(i));
		}
	}
	return (0);
}