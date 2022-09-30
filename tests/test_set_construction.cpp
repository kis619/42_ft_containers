/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_construction.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:43:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/30 15:14:13 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_set.hpp"
#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "colours.h"
#include <stack>
#include <vector>
#include <set>
#include "utils.hpp"

int main(void)
{
	std::set<int>	og_set;
	test_name("Testing the default constructor");
		ft::set<int>	my_set;
	test_name("Testing the default comapre constructor");
		ft::set<int>	my_comp_set(std::less<int> comp);
	test_name("Testing the copy constructor");
		ft::set<int>	my_copied_set(my_set);

	std::cout << COLOUR_DEFAULT;
	return (0);
}
