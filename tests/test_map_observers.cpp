/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_observers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/13 18:44:52 by kmilchev         ###   ########.fr       */
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
	
	std::cout << COLOUR_GREEN <<typeid(my_map.value_comp()).name() << std::endl;
	std::cout << typeid(og_map.value_comp()).name() << COLOUR_DEFAULT << std::endl;
	assert(typeid(my_map.key_comp()).name() == typeid(og_map.key_comp()).name());
	return (0);
}