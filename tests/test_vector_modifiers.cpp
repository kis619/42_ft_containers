/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_modifiers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:49:56 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/27 21:40:30 by kmilchev         ###   ########.fr       */
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
		assert(original[i] == mine[i]);
}

int main(void)
{
	ft::vector<int>			my_v(3, 3);
	std::vector<int>		og_v(3, 3);
	const ft::vector<int>	my_v_const(3, 4);
	const std::vector<int>	og_v_const(3, 4);

	{
		std::cout << COLOUR_BLUE << "Testing method .pop_back()" << COLOUR_DEFAULT << std::endl;
		og_v.pop_back();
		my_v.pop_back();
		assert(og_v.size() == my_v.size());
	}
	
	{
		std::cout << COLOUR_BLUE << "Testing method .clear()" << COLOUR_DEFAULT << std::endl;
		og_v.clear();
		my_v.clear();
		assert(og_v.size() == my_v.size());
	}
	
	{
		std::cout << COLOUR_BLUE << "Testing method .push_back() with enough capacity" << COLOUR_DEFAULT << std::endl;
		for (int i = 0; i < my_v.capacity(); i++)
		{
			og_v.push_back(i + 1);
			my_v.push_back(i + 1);
			assert(og_v[i] == my_v[i]);
		}
	}
	
	{
		std::cout << COLOUR_BLUE << "Testing method .push_back() with insufficient capacity" << COLOUR_DEFAULT << std::endl;
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
		std::cout << COLOUR_BLUE << "Testing method .assign() range version with iterators" << COLOUR_DEFAULT << std::endl;
		og_new_v.assign(og_it, og_it2);
		my_new_v.assign(my_it, my_it2);
		test_capacity_size_values(my_new_v, og_new_v);
	}

	{
		std::cout << COLOUR_BLUE << "Testing method .assign() fill verison" << COLOUR_DEFAULT << std::endl;
		og_new_v.assign(4, 0);
		my_new_v.assign(4, 0);
		test_capacity_size_values(my_new_v, og_new_v);
	}
	
	{
		std::cout << COLOUR_BLUE << "Testing method .insert() single element sufficient capacity" << COLOUR_DEFAULT << std::endl;
		og_new_v.insert(og_new_v.begin(), 7);
		my_new_v.insert(my_new_v.begin(), 7);
		test_capacity_size_values(my_new_v, og_new_v);
	}
	
	{
		std::cout << COLOUR_BLUE << "Testing method .insert() single element insufficient capacity" << COLOUR_DEFAULT << std::endl;
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
		std::cout << COLOUR_BLUE << "Testing method .insert() fill with insufficient capacity" << COLOUR_DEFAULT << std::endl;
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
	
	// std::cout << COLOUR_BLUE << "\n\nTesting method .insert() range" << COLOUR_DEFAULT << std::endl;
	// og_new_v.assign(6, 0);
	// my_new_v.assign(6, 0);
	// for (int i = 0; i < og_new_v.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_new_v[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_new_v.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_new_v[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// std::vector<int> og_vec(2, 2);
	// ft::vector<int> my_vec(2, 2);
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;

	// og_vec.insert(og_vec.begin(), og_new_v.begin(), og_new_v.end());
	// my_vec.insert(my_vec.begin(), my_new_v.begin(), my_new_v.end());
	// og_vec.insert(og_vec.end(), og_new_v.begin(), og_new_v.end());
	// my_vec.insert(my_vec.end(), my_new_v.begin(), my_new_v.end());
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;

	// std::cout << COLOUR_BLUE << "\n\nTesting method .erase() single" << COLOUR_DEFAULT << std::endl;
	// og_it = og_vec.erase(og_vec.end() - 1);
	// my_it = my_vec.erase(my_vec.end() - 1);
	// std::cout << "OG:   Iterator value: " << COLOUR_RED << *og_it << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Iterator value: " << COLOUR_RED << *my_it << COLOUR_DEFAULT << std::endl;
	// og_vec.erase(og_vec.end() - 1);
	// my_vec.erase(my_vec.end() - 1);
	// og_vec.erase(og_vec.end() - 1);
	// my_vec.erase(my_vec.end() - 1);
	// og_vec.erase(og_vec.end() - 1);
	// my_vec.erase(my_vec.end() - 1);
	// og_vec.erase(og_vec.begin());
	// my_vec.erase(my_vec.begin());
	// og_vec.erase(og_vec.begin());
	// my_vec.erase(my_vec.begin());
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;

	// std::cout << "OG:   Size:     " << COLOUR_RED << og_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Size:     " << COLOUR_RED << my_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "OG:   Capacity: " << COLOUR_RED << og_vec.capacity() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Capacity: " << COLOUR_RED << my_vec.capacity() << COLOUR_DEFAULT << std::endl;

	// std::cout << COLOUR_BLUE << "\n\nTesting method .erase() range" << COLOUR_DEFAULT << std::endl;
	// og_vec.assign(0, 0);
	// my_vec.assign(0, 0);
	// for (int i = 0; i < 10; i++)
	// {
	// 	og_vec.push_back(i + 1);
	// 	my_vec.push_back(i + 1);
	// }
	// og_vec.erase(og_vec.begin(), og_vec.begin() + 2);
	// my_vec.erase(my_vec.begin(), my_vec.begin() + 2);
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// std::cout << "OG:   Size:     " << COLOUR_RED << og_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Size:     " << COLOUR_RED << my_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "OG:   Capacity: " << COLOUR_RED << og_vec.capacity() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Capacity: " << COLOUR_RED << my_vec.capacity() << COLOUR_DEFAULT << std::endl;
	// og_vec.erase(og_vec.begin(), og_vec.begin() + 2);
	// my_vec.erase(my_vec.begin(), my_vec.begin() + 2);
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// std::cout << "OG:   Size:     " << COLOUR_RED << og_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Size:     " << COLOUR_RED << my_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "OG:   Capacity: " << COLOUR_RED << og_vec.capacity() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Capacity: " << COLOUR_RED << my_vec.capacity() << COLOUR_DEFAULT << std::endl;
	// og_vec.erase(og_vec.end() - 5, og_vec.end());
	// my_vec.erase(my_vec.end() - 5, my_vec.end());
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// std::cout << "OG:   Size:     " << COLOUR_RED << og_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Size:     " << COLOUR_RED << my_vec.size() << COLOUR_DEFAULT << std::endl;
	// std::cout << "OG:   Capacity: " << COLOUR_RED << og_vec.capacity() << COLOUR_DEFAULT << std::endl;
	// std::cout << "Mine: Capacity: " << COLOUR_RED << my_vec.capacity() << COLOUR_DEFAULT << std::endl;

	// std::cout << COLOUR_BLUE << "\n\nTesting method .swap()" << COLOUR_DEFAULT << std::endl;
	// std::vector<int> og_vec_new(7, 7);
	// ft::vector<int> my_vec_new(7, 7);
	// std::cout << COLOUR_PURPLE << "\nOG before .swap()" << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < og_vec_new.size(); i++)
	// 	std::cout << COLOUR_GREEN << og_vec_new[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// og_vec.swap(og_vec_new);
	// std::cout << COLOUR_PURPLE << "\nOG after .swap()" << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < og_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << og_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < og_vec_new.size(); i++)
	// 	std::cout << COLOUR_YELLOW << og_vec_new[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;

	// std::cout << COLOUR_PURPLE << "\nMINE before .swap()" << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_YELLOW << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec_new.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec_new[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// my_vec.swap(my_vec_new);
	// std::cout << COLOUR_PURPLE << "\nMINE after .swap()" << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec.size(); i++)
	// 	std::cout << COLOUR_GREEN << my_vec[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
	// for (int i = 0; i < my_vec_new.size(); i++)
	// 	std::cout << COLOUR_YELLOW << my_vec_new[i] << " ";
	// std::cout << COLOUR_DEFAULT << std::endl;
}