#include "../ft_vector.hpp"
#include "colours.h"
#include <vector>
#include <iterator>
#include <iostream>

int main(void)
{
	ft::vector<int> my_v(3, 3);
	std::vector<int> og_v(3, 3);
	const ft::vector<int> my_v_const(3, 4);
	const std::vector<int> og_v_const(3, 4);

	std::cout << COLOUR_BLUE << "Testing method .size()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be 3: " << COLOUR_GREEN << my_v.size() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG: should be 3:   " << COLOUR_GREEN << og_v.size() << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing method .max_size()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be equal to OG: " << COLOUR_GREEN << my_v.max_size() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:                          " << COLOUR_GREEN << og_v.max_size() << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing method .capacity()" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: should be 3: " << COLOUR_GREEN << my_v.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   should be 3: " << COLOUR_GREEN << og_v.capacity() << COLOUR_DEFAULT << std::endl;


}