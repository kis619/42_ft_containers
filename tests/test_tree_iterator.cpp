/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree_iterator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/16 18:18:24 by kmilchev         ###   ########.fr       */
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
#include <vector>
#include "string"

typedef ft::RBTree< ft::pair<int, std::string> , ft::map<int, std::string>::value_compare, ft::map<int, std::string>::allocator_type > tree_type;

int main(void)
{
	///////////////////Setting up///////////////////
	std::allocator<ft::pair<const int, std::string> > alloc;
	std::less<int> comp = std::less<int>();
	tree_type tree(comp, alloc);
	ft::map<int, std::string> mappy;
	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	for(size_t i = 1; i <= 12; i++)
		tree.insert(ft::make_pair(i, months[i - 1]));
	///////////////////////////////////////////////

	test_name("Testing the default constructor");
	tree_type::iterator it;
	tree_type::iterator it3;
	test_name("Testing the copy constructor");
	tree_type::iterator it2(it);
	test_name("Testing the assignment operator");
	it3 = it;
	test_name("Testing the assignment operator with const");
	tree_type::const_iterator const_it;
	const_it = tree.begin();
	test_name("Testing the two-node constructor");
	tree_type::iterator it4(tree.insert_test(ft::make_pair(13, "Confusion")),	tree.insert_test(ft::make_pair(2, "Feb")));
	
	{
		test_name("Testing .begin()");
		assert("January" == tree.begin()->second);
	}
	
	{
		test_name("Testing .end()");
		it = tree.end();
		for(size_t i = 1; i <= 13; i++)
		{
			it--;
			assert(14 - i == it->first);
		}
	}
	
	{
		test_name("Testing operator++() pre-increment");
		it = tree.begin();
		for(size_t i = 1; i <= 12; i++)
		{
			++it;
			assert(i + 1 == it->first);
		}
	}

	{
		test_name("Testing operator++(int) post-increment");
		it = tree.begin();
		for(size_t i = 1; i <= 12; i++)
		{
			assert(i == it->first);
			it++;
		}
	}

	{
		test_name("Testing operator--() pre-decrement");
		it = tree.begin();
		for(size_t i = 1; i <= 11; i++)
			it++;
		for(size_t i = 1; i <= 11; i++)
		{
			assert(13 - i == it->first);
			--it;
		}
	}

	{
		test_name("Testing operator--(int) post-decrement");
		it = tree.begin();
		for(size_t i = 1; i <= 11; i++)
			it++;
		for(size_t i = 1; i <= 11; i++)
		{
			assert(13 - i == it->first);
			it--;
		}
	}

	{
		test_name("Testing operator==");
		it = tree.begin();
		it2 = tree.begin();
		assert(it == it2);
		
		test_name("Testing operator!=");
		it2++;
		assert(it != it2);
	}


	
	// std::map<int, float> mapty;
	// std::map<int, float>::iterator it_m;


	// mapty.insert(std::make_pair(1, 0.4));
	// mapty.insert(std::make_pair(2, 0.5));
	// mapty.insert(std::make_pair(3, 0.6));
	// mapty.insert(std::make_pair(4, 0.7));

	// it_m = mapty.begin();
	// // if (it_m >= it_m2)
	// // 	std::cout << "whatevs\n";
	// // it_m++;
	// // // it_m++;
	// // it_m--;
	// // it_m++;
	// // std::cout << it_m->first << std::endl;
	// // it_m--;
	// // std::cout << it_m->first << std::endl;
	// // it_m--;
	// it_m++;
	// it_m++;
	// it_m++;
	// it_m--;
	// // it_m++;
	// std::cout << it_m->first << std::endl;
	// std::cout << it_m->second << std::endl;
	
	std::cout << COLOUR_DEFAULT;
	return (0);
}
