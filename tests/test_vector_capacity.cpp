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

	std::cout << COLOUR_BLUE << "Testing method .size()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be 3: " << COLOUR_GREEN << my_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG: should be 3:   " << COLOUR_GREEN << og_v.size() << COLOUR_DEFAULT << std::endl;

	std::cout << COLOUR_BLUE << "Testing method .max_size()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be equal to OG: " << COLOUR_GREEN << my_v.max_size() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:                          " << COLOUR_GREEN << og_v.max_size() << COLOUR_DEFAULT << std::endl;

	std::cout << COLOUR_BLUE << "Testing method .capacity()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be 3: " << COLOUR_GREEN << my_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   should be 3: " << COLOUR_GREEN << og_v.capacity() << COLOUR_DEFAULT << std::endl;

	ft::vector<int> my_2nd_v;
	std::cout << COLOUR_BLUE << "Testing method .empty()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine2: should be true: " << COLOUR_GREEN << std::boolalpha << my_2nd_v.empty() << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be false: " << COLOUR_GREEN << std::boolalpha << my_v.empty() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   should be false: " << COLOUR_GREEN << std::boolalpha << og_v.empty() << COLOUR_DEFAULT << std::endl;

	std::vector<int> og_new_v(1, 1);
	ft::vector<int> my_new_v(1, 1);
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