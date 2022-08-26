/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_non_member_swap.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:08:48 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/26 15:43:22 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "colours.h"

int main(void)
{
	ft::vector<int> v1(2, 2);
	ft::vector<int> v2(3, 3);

	std::cout << COLOUR_PURPLE << "Before swap: " << std::endl;
	for (int i = 0; i < v1.size(); i++)
		std::cout << COLOUR_YELLOW << v1[i] << " ";
	std::cout << COLOUR_DEFAULT << std::endl;
	
	for (int i = 0; i < v2.size(); i++)
		std::cout << COLOUR_GREEN << v2[i] << " ";
	std::cout << COLOUR_DEFAULT << std::endl;
	
	ft::swap(v1, v2);
	std::cout << COLOUR_PURPLE << "After swap: " << std::endl;
	for (int i = 0; i < v1.size(); i++)
		std::cout << COLOUR_GREEN << v1[i] << " ";
	std::cout << COLOUR_DEFAULT << std::endl;
	
	for (int i = 0; i < v2.size(); i++)
		std::cout << COLOUR_YELLOW << v2[i] << " ";
	std::cout << COLOUR_DEFAULT << std::endl;
}