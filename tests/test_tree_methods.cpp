/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree_methods.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/18 16:20:06 by kmilchev         ###   ########.fr       */
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

typedef ft::RBTree< ft::pair<int, int> , ft::map<int, int>::value_compare, ft::map<int, int>::allocator_type > tree_type;

void fill_array(ft::vector<ft::pair<int, int> > &arr)
{
	for (size_t i = 1; i < 14; i++)
		arr.push_back(ft::make_pair(i, i + 10));
}

void fill_tree(tree_type &tree, ft::vector<ft::pair<int, int> > &arr)
{
	for (size_t i = 0; i < 13; i++)
			tree.insert_test(arr[i]);	
}
int main(void)
{
	////////////////////Building blocks for the tree
	std::allocator<ft::pair<const int, int> > alloc;
	std::less<int> comp = std::less<int>();
	ft::vector<ft::pair<int, int> > pair_arr;
	tree_type tree(comp, alloc);
	
	
	fill_array(pair_arr);
	////////////////////Tests
	{
		test_name("Testing the method insert");
		for (size_t i = 0; i < 13; i++)
		{
			tree.insert(pair_arr.at(i));
			// assert(pair_arr[i].first == tree.insert(pair_arr.at(i))->first);
		}
		std::cout << COLOUR_GREEN;
		tree.print_tree();
	}
	
	{
		test_name("Testing the method size");
		assert(pair_arr.size() == tree.size());
	}
	
	{
		test_name("Testing the method erase | existing nodes");
		for (size_t i = 0; i < 13; i++)
		{
			assert(1 == tree.erase(pair_arr.at(i)));
			assert(13 - i - 1 == tree.size());
			if (i == 4)
			{
				std::cout << COLOUR_GREEN << "After 5 nodes were removed\n";
				tree.print_tree();
				std::cout << COLOUR_RED;
			}
			tree.erase(pair_arr.at(i));
		}
		std::cout << COLOUR_GREEN << "After all nodes were removed\n" << COLOUR_RED;
		tree.print_tree();
	}

	{
		test_name("Testing the method erase | non-existing nodes");
		assert(tree.size() == tree.erase(ft::make_pair(14, 14)));
	}

	{
		test_name("Testing the method erase_unique | existing nodes");
		fill_array(pair_arr);
		fill_tree(tree, pair_arr);
		for (size_t i = 0; i < 13; i++)
		{
			assert(1 == tree.erase_unique(i + 1));
			assert(13 - i - 1 == tree.size());
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
		test_name("Testing the method erase_unique | non-existing nodes");
		tree.erase_unique(1);
		assert(tree.size() == tree.erase_unique(1));
	}

	{
		test_name("Testing the method empty");
		assert(true == tree.empty());
	}

	{
		fill_array(pair_arr);
		fill_tree(tree, pair_arr);
		test_name("Testing the method min");
		assert(1 == tree.min(tree.getRoot())->value->first);
		test_name("Testing the method max");
		assert(13 == tree.max(tree.getRoot())->value->first);


		tree_type::iterator it_begin = tree.begin();
		tree_type::iterator it_end = tree.end();
		int i  = 0;
		while(it_begin != it_end)
		{
			
			tree.erase(pair_arr[i]);
			it_begin++;
			i++;
		}
	}

	tree.deallocateNil();
	std::cout << COLOUR_DEFAULT;
}
