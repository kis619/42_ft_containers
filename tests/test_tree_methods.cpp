/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree_methods.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/05 14:00:15 by kmilchev         ###   ########.fr       */
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

void fill_array(ft::vector<ft::pair<int, int> > &arr)
{
	for (size_t i = 1; i < 11; i++)
		arr.push_back(ft::make_pair(i, i + 10));
}

void fill_tree(ft::RBTree< ft::pair<int, int> , ft::map<int, int>::value_compare, ft::map<int, int>::allocator_type > &tree, ft::vector<ft::pair<int, int> > &arr)
{
	for (size_t i = 0; i < 10; i++)
			tree.insert(arr[i]);	
}
int main(void)
{
	////////////////////Typedefs
	typedef ft::pair<int, int> pair;
	typedef ft::map<int, int>::value_compare value_compare;
	typedef ft::map<int, int>::allocator_type allocator_type;
	typedef ft::RBTree< ft::pair<int, int> , ft::map<int, int>::value_compare, ft::map<int, int>::allocator_type > tree_type;

	
	////////////////////Building blocks for the tree
	std::allocator<ft::pair<const int, int> > alloc;
	std::less<int> comp = std::less<int>();
	ft::vector<ft::pair<int, int> > pair_arr;
	fill_array(pair_arr);
	//1 - 11, 2 - 12, 3 - 13, 4 - 14, 5 - 15, 6 - 16, 7 - 17, 8 - 18, 9 - 19, 10 -20
	
	////////////////////Tree initialisation
	tree_type tree(comp, alloc);

	
	////////////////////Tests
	{
		test_name("Testing the insert method");
		for (size_t i = 0; i < 10; i++)
		{
			assert(pair_arr[i].first == tree.insert(pair_arr.at(i))->value.first);
			assert(pair_arr[i].second == tree.insert(pair_arr.at(i))->value.second);
		}
		std::cout << COLOUR_GREEN;
		tree.print_tree();
	}
	
	{
		test_name("Testing the find method");
		assert(pair_arr.size() == tree.size());
	}
	
	{
		test_name("Testing the erase method | existing nodes");
		for (size_t i = 0; i < 10; i++)
		{
			assert((10 - i - 1) == tree.erase(pair_arr.at(i)));
			assert(10 - i - 1 == tree.size());
			if (i == 4)
			{
				std::cout << COLOUR_GREEN << "After 5 nodes were removed\n";
				tree.print_tree();
				std::cout << COLOUR_RED;
			}
			// std::cout << tree.erase(pair_arr.at(i));
			// assert(pair_arr[i].second == tree.erase(pair_arr.at(i))->value.second);
		}
		std::cout << COLOUR_GREEN << "After all nodes were removed\n" << COLOUR_RED;
		tree.print_tree();
	}

	{
		test_name("Testing the erase method | non-existing nodes");
		assert(tree.size() == tree.erase(ft::make_pair(14, 14)));
	}

	{
		test_name("Testing the erase_unique method | existing nodes");
		fill_array(pair_arr);
		fill_tree(tree, pair_arr);
		for (size_t i = 0; i < 10; i++)
		{
			assert((10 - i - 1) == tree.erase_unique(i + 1));
			assert(10 - i - 1 == tree.size());
			if (i == 4)
			{
				std::cout << COLOUR_GREEN << "After 5 nodes were removed\n";
				tree.print_tree();
				std::cout << COLOUR_RED;
			}	
		}
		std::cout << COLOUR_GREEN << "After all nodes were removed\n" << COLOUR_RED;
		tree.print_tree();
	}

	{
		test_name("Testing the erase_unique method | non-existing nodes");
		assert(tree.size() == tree.erase_unique(1));
	}
}
