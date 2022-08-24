/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_construction.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:20:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/24 17:24:04 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include "colours.h"
#include <vector>

int main(void)
{
	std::cout << COLOUR_BLUE << "Testing the default constructor " << COLOUR_DEFAULT << std::endl;
	ft::vector<int> test;
	std::cout << "Capcity should be 0: " << COLOUR_GREEN << test.capacity() << COLOUR_DEFAULT << std::endl;

	
	std::cout << COLOUR_BLUE << "Testing the fill constructor " << COLOUR_DEFAULT << std::endl;
	ft::vector<int> test1(4, 69);
	std::cout << "Size should be 4: " << COLOUR_GREEN << test1.capacity() << COLOUR_DEFAULT << std::endl;
	for (int i = 0; i < test1.size(); i++)
		std::cout << "Element " << i << " should be 69: " << COLOUR_GREEN << *(test1.begin()) << COLOUR_DEFAULT << std::endl;
		
	
	std::cout << COLOUR_BLUE << "Testing the range constructor " << COLOUR_DEFAULT << std::endl;
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator it2;
	ft::vector<int> numbers(3, 33);
	numbers[0] = 23;
	numbers[1] = 14;
	numbers[2] = 51;
	it = numbers.begin();
	it2 = numbers.end();
	ft::vector<int> numbers2(it, it2);
	std::cout << "Capacity should be 3: " << COLOUR_GREEN << numbers2.capacity() << COLOUR_DEFAULT << std::endl;
	std::cout << "Element 0 should be 23: " << COLOUR_GREEN << *(numbers2.begin()) << COLOUR_DEFAULT << std::endl;
	std::cout << "Element 0 should be 14: " << COLOUR_GREEN << *(numbers2.begin() + 1) << COLOUR_DEFAULT << std::endl;
	std::cout << "Element 0 should be 51: " << COLOUR_GREEN << *(numbers2.begin() + 2) << COLOUR_DEFAULT << std::endl;
	return (0);
}