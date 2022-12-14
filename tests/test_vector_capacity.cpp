#include "../ft_vector.hpp"
#include "colours.h"
#include <vector>
#include <iterator>
#include <iostream>
#include "utils.hpp"

int main(void)
{
	ft::vector<int>			my_v(3, 3);
	std::vector<int>		og_v(3, 3);
	const ft::vector<int>	my_v_const(3, 4);
	const std::vector<int>	og_v_const(3, 4);

	test_name("Testing method .size()");
	assert(3 == my_v.size());

	test_name("Testing method .max_size()");
	assert(og_v.max_size() == my_v.max_size());

	test_name("Testing method .capacity()");
	assert(3 == my_v.capacity());

	test_name("Testing method .empty()");
	ft::vector<int> my_2nd_v;
	assert(true == my_2nd_v.empty());
	assert(false == my_v.empty());

	{
		test_name("Testing method .resize() with sufficient capacity");
		std::vector<int> og_new_v(1, 1);
		ft::vector<int> my_new_v(1, 1);
		og_new_v.resize(3);
		my_new_v.resize(3);
		assert(3 == my_new_v.size());
	}
	
	{
		test_name("Testing method .resize() with insufficient capacity");
		std::vector<int> og_newer_v;
		ft::vector<int> my_newer_v;
		og_newer_v.resize(0, 0);
		my_newer_v.resize(0, 0);
		assert(og_newer_v.capacity() == my_newer_v.capacity());
		og_newer_v.resize(36, 2);
		my_newer_v.resize(36, 2);
		assert(og_newer_v.capacity() == my_newer_v.capacity());
		assert(og_newer_v.size() == my_newer_v.size());
		og_newer_v.resize(77, 1);
		my_newer_v.resize(77, 1);
		assert(og_newer_v.capacity() == my_newer_v.capacity());
		assert(og_newer_v.size() == my_newer_v.size());
		og_newer_v.resize(78, 1);
		my_newer_v.resize(78, 1);
		assert(og_newer_v.capacity() == my_newer_v.capacity());
		assert(og_newer_v.size() == my_newer_v.size());
		for (size_t i = 0; i < og_newer_v.size(); i++)
			assert(og_newer_v[i] == my_newer_v[i]);
	}

	{
		test_name("Testing method .reserve()");
		std::vector<int> og_vec(2, 2);
		ft::vector<int> my_vec(2, 2);
		og_vec.reserve(70);
		my_vec.reserve(70);
		assert(og_vec.capacity() == my_vec.capacity());
		og_vec.reserve(1);
		my_vec.reserve(1);
		assert(og_vec.capacity() == my_vec.capacity());
		for (size_t i = 0; i < og_vec.size(); i++)
			assert(og_vec[i] == my_vec[i]);
	}
	std::cout << COLOUR_DEFAULT;
}