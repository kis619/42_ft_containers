/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_observers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:32:36 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 13:39:04 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "../ft_set.hpp"
#include "colours.h"
#include "utils.hpp"
#include <set>

#include <typeinfo>

int main(void)
{
	std::set<int> og_set;
	ft::set<int> my_set;
	
	test_name("Testing the method .key_comp()");
		assert(typeid(og_set.key_comp()).name() == typeid(my_set.key_comp()).name());
	test_name("Testing the method .value_comp()");
		assert(typeid(og_set.value_comp()).name() == typeid(my_set.value_comp()).name());
	test_name("Testing the method .get_allocator()");
		assert(typeid(og_set.get_allocator()).name() == typeid(my_set.get_allocator()).name());

	std::cout << COLOUR_DEFAULT;
	return (0);
}