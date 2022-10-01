/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 11:33:17 by kmilchev         ###   ########.fr       */
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
	
	for (int i = 0; i < 10; i++)
	{
		og_set.insert(i + 1);
		my_set.insert(i + 1);
	}
	
	{
		test_name("Testing the method .begin()");
		std::set<int>::iterator og_it = og_set.begin();
		ft::set<int>::iterator my_it = my_set.begin();
		for (int i = 0; i < 10; i++)
			assert(*(my_it++) == *(og_it++));
	}
	
	{
		test_name("Testing the method .end()");
		std::set<int>::iterator og_it = og_set.end();
		ft::set<int>::iterator my_it = my_set.end();
		og_it--;
		my_it--;
		for (int i = 0; i < 10; i++)
			assert(*(my_it--) == *(og_it--));
	}
	
	{
		test_name("Testing the method .rend()");
		std::set<int>::reverse_iterator og_rev_it = og_set.rend();
		ft::set<int>::reverse_iterator my_rev_it = my_set.rend();
		og_rev_it--;
		my_rev_it--;
		for (int i = 0; i < 9; i++)
			assert(*(og_rev_it--) == *(my_rev_it--));
	}
	
	{
		test_name("Testing the method .rbegin()");
		std::set<int>::reverse_iterator og_rev_it = og_set.rbegin();
		ft::set<int>::reverse_iterator my_rev_it = my_set.rbegin();
		for (int i = 0; i < 10; i++)
			assert(*(og_rev_it++) == *(my_rev_it++));
	}
	
	std::cout << COLOUR_DEFAULT;
	return (0);
}