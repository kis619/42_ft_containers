/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_logical_operators.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:40:42 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 13:48:06 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_set.hpp"
#include "colours.h"
#include "utils.hpp"
#include <set>

int main(void)
{
	ft::set<int> first_empty_set;
	ft::set<int> second_empty_set;
	ft::set<int> non_empty_set;

	non_empty_set.insert(69);

	test_name("Testing the operator==");
		assert(first_empty_set == second_empty_set);
		
	test_name("Testing the operator!=");
		assert(first_empty_set != non_empty_set);
		
	test_name("Testing the operator>=");
		assert(first_empty_set >= second_empty_set);
		assert(non_empty_set >= second_empty_set);
		
	test_name("Testing the operator<=");
		assert(first_empty_set <= second_empty_set);
		assert(first_empty_set <= non_empty_set);
		
	test_name("Testing the operator>");
		assert(non_empty_set > second_empty_set);
		
	test_name("Testing the operator<");
		assert(first_empty_set < non_empty_set);

	
	std::cout << COLOUR_DEFAULT;
	return (0);
}