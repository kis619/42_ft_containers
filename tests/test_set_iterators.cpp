/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/30 16:15:37 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "../ft_set.hpp"
#include "../ft_vector.hpp"
#include "../ft_tree.hpp"
#include "colours.h"
#include "utils.hpp"
#include <set>
#include <vector>
#include "string"

int main(void)
{
	ft::set<int> my_set;
	std::set<int> og_set;
	
	og_set.insert(og_set.begin(), 6);
	std::set<int>::iterator it = og_set.find(234);
	std::cout << it.operator->() << std::endl;
	std::cout << *(it) << std::endl;
	
	my_set.insert(0, 19);
	// ft::set<int>::iterator my_it = my_set.find(6);
	std::cout << my_set.count(19);
	std::cout << my_set.count(33);
	std::cout << COLOUR_DEFAULT;
	return (0);
}