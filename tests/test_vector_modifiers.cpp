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


}