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
		// std::cout << og_v.at(i) << std::endl;
		// std::cout << my_v.at(i) << std::endl;
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

	std::cout << COLOUR_BLUE << "\nTesting method .resize() with sufficient capacity" << COLOUR_DEFAULT << std::endl;
	og_new_v.resize(3);
	my_new_v.resize(3);
	std::cout << "OG:   Size should be 3: " << COLOUR_GREEN << og_new_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Size should be 3: " << COLOUR_GREEN << my_new_v.size() << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "\nTesting method .resize() with insufficient capacity" << COLOUR_DEFAULT << std::endl;
	std::vector<int> og_newer_v;
	ft::vector<int> my_newer_v;
	og_newer_v.resize(0, 0);
	my_newer_v.resize(0, 0);
	std::cout << "OG:     Capacity should be 0: " << COLOUR_GREEN << og_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine:   Capacity should be 0: " << COLOUR_GREEN << my_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	og_newer_v.resize(36, 2);
	my_newer_v.resize(36, 2);
	std::cout << "OG:     Resize(36, 0) Capacity should be 36: " << COLOUR_GREEN << og_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine:   Resize(36, 0) Capacity should be 36: " << COLOUR_GREEN << my_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine:   Resize(36, 0) Size     should be 36: " << COLOUR_GREEN << my_newer_v.size() << COLOUR_DEFAULT << std::endl;
	og_newer_v.resize(77, 1);
	my_newer_v.resize(77, 1);
	std::cout << "OG:     Resize(77, 0) Capacity should be 77: " << COLOUR_GREEN << og_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine:   Resize(77, 0) Capacity should be 77: " << COLOUR_GREEN << my_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	og_newer_v.resize(78, 1);
	my_newer_v.resize(78, 1);
	std::cout << "OG:     Resize(78, 0) Capacity should be 154: " << COLOUR_GREEN << og_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine:   Resize(78, 0) Capacity should be 154: " << COLOUR_GREEN << my_newer_v.capacity() << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < og_newer_v.size(); i++)
	{
		std::cout << COLOUR_YELLOW << og_newer_v[i] << " ";
	}
	std::cout<< std::endl;
	for (int i = 0; i < my_newer_v.size(); i++)
	{
		std::cout << COLOUR_GREEN << my_newer_v[i] << " ";
	}
	std::vector<int> og_vec(2, 2);
	ft::vector<int> my_vec(2, 2);
	std::cout << COLOUR_DEFAULT << std::endl;
	std::cout << COLOUR_BLUE << "\nTesting method .reserve()" << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   Capacity should be 2: " << COLOUR_GREEN << og_vec.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Capacity should be 2: " << COLOUR_GREEN << my_vec.capacity() << COLOUR_DEFAULT << std::endl;
	og_vec.reserve(70);
	my_vec.reserve(70);
	std::cout << "OG:   .reserve(70)Capacity should be 70: " << COLOUR_GREEN << og_vec.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: .reserve(70)Capacity should be 70: " << COLOUR_GREEN << my_vec.capacity() << COLOUR_DEFAULT << std::endl;
	og_vec.reserve(1);
	my_vec.reserve(1);
	std::cout << "OG:   .reserve(1)Capacity should be 70: " << COLOUR_GREEN << og_vec.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: .reserve(1)Capacity should be 70: " << COLOUR_GREEN << my_vec.capacity() << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < og_vec.size(); i++)
	{
		std::cout << COLOUR_YELLOW << og_vec[i] << " ";
	}
	std::cout<< std::endl;
	for (int i = 0; i < my_vec.size(); i++)
	{
		std::cout << COLOUR_GREEN << my_vec[i] << " ";
	}

	std::cout<< std::endl;
}