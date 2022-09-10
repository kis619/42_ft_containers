/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree_iterator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/10 22:02:15 by kmilchev         ###   ########.fr       */
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
	test_name("Testing the two-node constructor");
	tree_type::iterator it4(tree.insert_test(ft::make_pair(13, "Confusion")), 	tree.insert_test(ft::make_pair(2, "Feb")));
	
	{
		test_name("Testing .begin()");
		assert("January" == tree.begin()->second);
	}
	
	{
		test_name("Testing operator++() pre-increment");
		it = tree.begin();
		for(size_t i = 1; i <= 12; i++)
		{
			assert(i == it->first);
			++it;
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
	// {
	// 	test_name("Testing .end()");
	// 	assert("December" == tree.end()->second);
	// }

	// std::map<int, int> mapty;
	// std::map<int, int>::iterator it_m;

	// mapty.insert(std::make_pair(1, 10));
	// // // std::cout << mapty.insert(std::make_pair(1, 1097813661364691)).first->second;
	// mapty.insert(std::make_pair(2, 20));
	// mapty.insert(std::make_pair(3, 30));
	// mapty.insert(std::make_pair(4, 40));
	// // // std::cout << mapty.at(1) << std::endl;
	// // // std::cout << mapty.begin()->second << std::endl;

	// it_m = mapty.begin();

	// it_m++;
	// // it_m++;
	// std::cout << it_m->first << std::endl;
	

	return (0);
}
