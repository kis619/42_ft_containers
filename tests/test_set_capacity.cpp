/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 11:43:47 by kmilchev         ###   ########.fr       */
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

int main (void)
{
	ft::set<double> my_set;
	std::set<double> og_set;

	test_name("Testing the method .empty()");
		assert(og_set.empty() == my_set.empty());

	test_name("Testing the method .size()");
		assert(og_set.size() == my_set.size());

	test_name("Testing the method .max_size()");
		assert(og_set.max_size() == my_set.max_size());


	return (0);
}
