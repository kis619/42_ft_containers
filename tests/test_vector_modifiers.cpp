/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_modifiers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:49:56 by kmilchev          #+#    #+#             */
/*   Updated: 2022/10/01 16:22:17 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include "colours.h"
#include <vector>
#include "utils.hpp"
#include <iterator>
#include <iostream>
#include <assert.h>

void test_capacity_size_values(ft::vector<int> &mine, std::vector<int> &original)
{

	assert(original.capacity() == mine.capacity());
	assert(original.size() == mine.size());
	for (int i = 0; i < original.size(); i++)
	{
		assert(original[i] == mine[i]);
	}
}

int main(void)
{
	ft::vector<int>			my_v(3, 3);
	std::vector<int>		og_v(3, 3);
	const ft::vector<int>	my_v_const(3, 4);
	const std::vector<int>	og_v_const(3, 4);

	{
		test_name("Testing method .pop_back()");
		og_v.pop_back();
		my_v.pop_back();
		assert(og_v.size() == my_v.size());
	}
	
	{
		test_name("Testing method .clear()");
		og_v.clear();
		my_v.clear();
		assert(og_v.size() == my_v.size());
	}
	
	{
		test_name("Testing method .push_back() with enough capacity");
		for (int i = 0; i < my_v.capacity(); i++)
		{
			og_v.push_back(i + 1);
			my_v.push_back(i + 1);
			assert(og_v[i] == my_v[i]);
		}
	}
	
	{
		test_name("Testing method .push_back() with insufficient capacity");
		for (int i = 0; i < 45; i++)
		{
			my_v.push_back(78 + i);
			og_v.push_back(78 + i);
		}
		test_capacity_size_values(my_v, og_v);
	}

	std::vector<int> og_new_v(1, 1);
	ft::vector<int> my_new_v(1, 1);
	std::vector<int>::iterator	og_it(og_v.begin());
	std::vector<int>::iterator	og_it2(og_v.begin() + 10);
	std::vector<int>::iterator	og_it3(og_v.begin() + 2);
	ft::vector<int>::iterator	my_it(my_v.begin());
	ft::vector<int>::iterator	my_it2(my_v.begin() + 10);
	ft::vector<int>::iterator	my_it3(my_v.begin() + 2);
	
	{
		test_name("Testing method .assign() range version with iterators");
		og_new_v.assign(og_it, og_it2);
		my_new_v.assign(my_it, my_it2);
		test_capacity_size_values(my_new_v, og_new_v);
	}

	{
		test_name("Testing method .assign() fill verison");
		og_new_v.assign(4, 0);
		my_new_v.assign(4, 0);
		test_capacity_size_values(my_new_v, og_new_v);
	}
	
	{
		test_name("Testing method .insert() single element sufficient capacity");
		og_new_v.insert(og_new_v.begin(), 7);
		my_new_v.insert(my_new_v.begin(), 7);
		test_capacity_size_values(my_new_v, og_new_v);
	}
	
	{
		test_name("Testing method .insert() single element insufficient capacity");
		for (int i = 0; i < 56; i++)
		{
			og_new_v.insert(og_new_v.begin() + 2, 69);
			my_new_v.insert(my_new_v.begin() + 2, 69);
		}
		test_capacity_size_values(my_new_v, og_new_v);
		
		std::vector<int>::iterator og_it_insert_return = og_new_v.insert(og_new_v.end(), 77);
		ft::vector<int>::iterator my_it_insert_return = my_new_v.insert(my_new_v.end(), 77);
		assert(*(og_it_insert_return) == *(my_it_insert_return));
	}
	
	{
		test_name("Testing method .insert() fill with insufficient capacity");
		og_new_v.assign(0, 0);
		my_new_v.assign(0, 0);
		og_new_v.insert(og_new_v.begin(), 1, 5);
		my_new_v.insert(my_new_v.begin(), 1, 5);
		og_new_v.insert(og_new_v.end(), 44, 5);
		my_new_v.insert(my_new_v.end(), 44, 5);
		og_new_v.insert(og_new_v.begin(), 3, 6);
		my_new_v.insert(my_new_v.begin(), 3, 6);
		test_capacity_size_values(my_new_v, og_new_v);
		og_new_v.insert(og_new_v.begin(), 1, 7);
		my_new_v.insert(my_new_v.begin(), 1, 7);
		og_new_v.insert(og_new_v.begin(), 6, 8);
		my_new_v.insert(my_new_v.begin(), 6, 8);
		og_new_v.insert(og_new_v.begin(), 1, 9);
		my_new_v.insert(my_new_v.begin(), 1, 9);
		og_new_v.insert(og_new_v.begin(), 20, 321);
		my_new_v.insert(my_new_v.begin(), 20, 321);
		test_capacity_size_values(my_new_v, og_new_v);
	}
	
	std::vector<int> og_vec;
	ft::vector<int> my_vec;
	
	{
		test_name("Testing method .insert() range");
		std::vector<int> og_new_v;
		ft::vector<int> my_new_v;
		for (int i = 0; i < 6; i++)
		{
			og_new_v.push_back(i);
			my_new_v.push_back(i);
			og_vec.push_back(7);
			my_vec.push_back(7);
		}
		og_vec.insert(og_vec.begin(), og_new_v.begin(), og_new_v.end());
		my_vec.insert(my_vec.begin(), my_new_v.begin(), my_new_v.end());
		og_vec.insert(og_vec.end(), og_new_v.begin(), og_new_v.end());
		my_vec.insert(my_vec.end(), my_new_v.begin(), my_new_v.end());
		og_vec.insert(og_vec.end(), og_new_v.begin(), og_new_v.end());
		my_vec.insert(my_vec.end(), my_new_v.begin(), my_new_v.end());
		og_vec.insert(og_vec.end(), og_new_v.begin(), og_new_v.end());
		my_vec.insert(my_vec.end(), my_new_v.begin(), my_new_v.end());
		test_capacity_size_values(my_vec, og_vec);
	}
	
	{
		test_name("Testing method .erase() single");
		og_it = og_vec.erase(og_vec.end() - 1);
		my_it = my_vec.erase(my_vec.end() - 1);
		assert(*og_it == *my_it);
		og_vec.erase(og_vec.end() - 1);
		my_vec.erase(my_vec.end() - 1);
		og_vec.erase(og_vec.end() - 1);
		my_vec.erase(my_vec.end() - 1);
		og_vec.erase(og_vec.end() - 1);
		my_vec.erase(my_vec.end() - 1);
		og_vec.erase(og_vec.begin());
		my_vec.erase(my_vec.begin());
		og_vec.erase(og_vec.begin());
		my_vec.erase(my_vec.begin());
		test_capacity_size_values(my_vec, og_vec);
	}
	
	{
		test_name("Testing method .erase() range");
		og_vec.assign(0, 0);
		my_vec.assign(0, 0);
		for (int i = 0; i < 10; i++)
		{
			og_vec.push_back(i + 1);
			my_vec.push_back(i + 1);
		}
		og_vec.erase(og_vec.begin(), og_vec.begin() + 2);
		my_vec.erase(my_vec.begin(), my_vec.begin() + 2);
		test_capacity_size_values(my_vec, og_vec);
		
		og_vec.erase(og_vec.begin(), og_vec.begin() + 2);
		my_vec.erase(my_vec.begin(), my_vec.begin() + 2);
		test_capacity_size_values(my_vec, og_vec);
		
		og_vec.erase(og_vec.end() - 5, og_vec.end());
		my_vec.erase(my_vec.end() - 5, my_vec.end());
		test_capacity_size_values(my_vec, og_vec);
	}

	{
		test_name("Testing method .swap()");
		ft::vector<int> v1(2, 2);
		ft::vector<int> v2(3, 3);
		ft::vector<int> v1_copy(v1);
		ft::vector<int> v2_copy(v2);

		//befor swap
		for (int i = 0; i < v1.size(); i++)
			assert(v1_copy[i] == v1[i]);
		v1.swap(v2);
		//after swap
		for (int i = 0; i < v1_copy.size(); i++)
			assert(v1_copy[i] == v2[i]);
		assert(v1_copy.capacity() == v2.capacity());
		assert(v1_copy.size() == v2.size());
		
		for (int i = 0; i < v1.size(); i++)
			assert(v2_copy[i] == v1[i]);
		assert(v2_copy.capacity() == v1.capacity());
		assert(v2_copy.size() == v1.size());
	}
	
	std::cout << COLOUR_DEFAULT;
	return (0);
}
