#include "../ft_vector.hpp"
#include "colours.h"
#include <vector>
#include <iterator>
#include <iostream>

int main(void)
{
	ft::vector<int>			my_v(3, 3);
	std::vector<int>		og_v(3, 3);
	const ft::vector<int>	my_v_const(3, 4);
	const std::vector<int>	og_v_const(3, 4);

	std::cout << COLOUR_BLUE << "Testing method .pop_back()" << COLOUR_DEFAULT << std::endl;
	og_v.pop_back();
	my_v.pop_back();
	std::cout << "OG:   should be 2: " << COLOUR_GREEN << og_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be 2: " << COLOUR_GREEN << my_v.size() << COLOUR_DEFAULT << std::endl;

	for (int i = 0; i < og_v.size(); i++)
	{
		og_v[i] = i + 1;
		my_v[i] = i + 1;
	}
	og_v.clear();
	my_v.clear();
	for (int i = 0; i < my_v.size(); i++)
	{
		std::cout << my_v.at(i) << std::endl;
		std::cout << og_v.at(i) << std::endl;
	}
	std::cout << COLOUR_BLUE << "Testing method .clear()" << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   should be 0: " << COLOUR_GREEN << og_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be 0: " << COLOUR_GREEN << my_v.size() << COLOUR_DEFAULT << std::endl;

	std::cout << COLOUR_BLUE << "Testing method .push_back()  with enough capacity" << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < my_v.capacity(); i++)
	{
		og_v.push_back(i + 1);
		my_v.push_back(i + 1);
		std::cout << "OG:   should be " << i + 1  << ": "<< COLOUR_GREEN << og_v[i] << COLOUR_DEFAULT << std::endl;
		std::cout << "Mine: should be " << i + 1  << ": "<< COLOUR_GREEN << my_v[i] << COLOUR_DEFAULT << std::endl;
	}
	std::cout << COLOUR_BLUE << "Testing method .push_back() with insufficient capacity" << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < 9; i ++)
	{
		my_v.push_back(78 + i);
		og_v.push_back(78 + i);
	}
	for (int i = 0; i < 9; i ++)
	{
		my_v.push_back(78 + i);
		og_v.push_back(78 + i);
	}
	for (int i = 0; i < 9; i ++)
	{
		my_v.push_back(78 + i);
		og_v.push_back(78 + i);
	}
	for (int i = 0; i < 9; i ++)
	{
		my_v.push_back(78 + i);
		og_v.push_back(78 + i);
	}
	for (int i = 0; i < 9; i ++)
	{
		my_v.push_back(78 + i);
		og_v.push_back(78 + i);
	}
	std::cout << "OG:   size should be 48: " << COLOUR_GREEN << og_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: size should be 48: " << COLOUR_GREEN << my_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   capacity should be 48: " << COLOUR_GREEN << og_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: capacity should be 48: " << COLOUR_GREEN << my_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   size should be 81: " << COLOUR_GREEN << og_v[6] << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: size should be 81: " << COLOUR_GREEN << my_v[6] << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   size should be 82: " << COLOUR_GREEN << og_v.at(7) << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: size should be 82: " << COLOUR_GREEN << my_v.at(7) << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < 9; i ++)
	{
		my_v.push_back(78 + i);
		og_v.push_back(78 + i);
	}
	std::cout << "OG:   capacity should be 96: " << COLOUR_GREEN << og_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: capacity should be 96: " << COLOUR_GREEN << my_v.capacity() << COLOUR_DEFAULT << std::endl;

	std::cout << COLOUR_BLUE << "Testing method .assign() range version with iterators" << COLOUR_DEFAULT << std::endl;

	std::vector<int> og_new_v(1, 1);
	ft::vector<int> my_new_v(1, 1);
	std::vector<int>::iterator	og_it(og_v.begin());
	std::vector<int>::iterator	og_it2(og_v.begin() + 10);
	std::vector<int>::iterator	og_it3(og_v.begin() + 1);
	ft::vector<int>::iterator	my_it(my_v.begin());
	ft::vector<int>::iterator	my_it2(my_v.begin() + 10);
	ft::vector<int>::iterator	my_it3(my_v.begin() + 1);
	std::cout << "OG:   Capacity before assign: " << COLOUR_RED << og_new_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Capacity before assign: " << COLOUR_RED << my_new_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   Size: " << COLOUR_RED << og_new_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Size: " << COLOUR_RED << my_new_v.size() << COLOUR_DEFAULT << std::endl;
	og_new_v.assign(og_it, og_it2);
	my_new_v.assign(my_it, my_it2);
	std::cout << "OG:   New Capacity: " << COLOUR_RED << og_new_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: New Capacity: " << COLOUR_RED << my_new_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   Size: " << COLOUR_RED << og_new_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Size: " << COLOUR_RED << my_new_v.size() << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < my_new_v.size(); i++)
	{
		std::cout << COLOUR_YELLOW << og_new_v[i] << " ";
	}
	std::cout<< std::endl;
	for (int i = 0; i < my_new_v.size(); i++)
	{
		std::cout << COLOUR_GREEN << my_new_v[i] << " ";
	}
	std::cout << COLOUR_DEFAULT;
	std::cout << COLOUR_BLUE << "\nTesting method .assign() fill verison" << COLOUR_DEFAULT << std::endl;
	og_new_v.assign(4, 0);
	my_new_v.assign(4, 0);
	std::cout << "OG:   New Capacity: " << COLOUR_RED << og_new_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: New Capacity: " << COLOUR_RED << my_new_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   Size: " << COLOUR_RED << og_new_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Size: " << COLOUR_RED << my_new_v.size() << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < og_new_v.size(); i++)
	{
		std::cout << COLOUR_YELLOW << og_new_v[i] << " ";
	}
	std::cout<< std::endl;
	for (int i = 0; i < my_new_v.size(); i++)
	{
		std::cout << COLOUR_GREEN << my_new_v[i] << " ";
	}
	std::cout << COLOUR_DEFAULT << std::endl;

	
}