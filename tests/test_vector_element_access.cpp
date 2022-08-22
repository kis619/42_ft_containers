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

	std::cout << COLOUR_BLUE << "Testing operator[]" << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < 3; i++)
	{
		my_v[i] = i + 1;
		og_v.at(i) = i + 1;
	}
	std::cout << "Mine: Num at idx 0 should be 1: " << COLOUR_GREEN << my_v[0] << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Num at idx 1 should be 2: " << COLOUR_GREEN << my_v[1] << COLOUR_DEFAULT << std::endl;
	std::cout << "OG: Num at idx 0 should be 1:   " << COLOUR_GREEN << og_v[0] << COLOUR_DEFAULT << std::endl;
	std::cout << "OG: Num at idx 1 should be 2:   " << COLOUR_GREEN << og_v[1] << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing const operator[]" << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Num at idx 0 should be 4: " << COLOUR_GREEN << my_v_const[0] << COLOUR_DEFAULT << std::endl;
	std::cout << "OG: Num at idx 1 should be 4:   " << COLOUR_GREEN << og_v_const[0] << COLOUR_DEFAULT << std::endl;
	
	std::cout << COLOUR_BLUE << "Testing method .at() " << COLOUR_DEFAULT << std::endl;
	std::cout << "Mine: Num at idx 0 should be 1: " << COLOUR_GREEN << my_v.at(0) << COLOUR_DEFAULT << std::endl;
	std::cout << "OG:   Num at idx 0 should be 1: " << COLOUR_GREEN << og_v.at(0) << COLOUR_DEFAULT << std::endl;


	std::cout << COLOUR_BLUE << "Testing method .at() when out_of_range" << COLOUR_DEFAULT << std::endl;
	try{
		og_v.at(3);}
	catch(std::exception & error){
		std::cout << "OG:   " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
	try{
		my_v.at(3);}
	catch(std::exception & error){
		std::cout << "Mine: " << COLOUR_RED << "Exception caught: " << error.what() << COLOUR_DEFAULT << std::endl;}
	return (0);
}