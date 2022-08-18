/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_begin.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:20:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/18 17:56:11 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	ft::vector<int> mine(4, 44);
	std::cout << *(mine.begin()) << std::endl;
	std::cout << mine.begin() << std::endl;
	std::cout << "++++++++++++++" << std::endl;
	
	std::vector<int> og;

	// og.begin();
	// std::cout << "Calling begin on an empty vector" << og.begin() << std::endl;
	og.push_back(1);
	og.push_back(2);
	og.push_back(3);
	og.push_back(4);
	// std::cout << "*(og.begin()): " << og.begin() << std::endl;
	// std::cout << "*(og.rbegin()): " << *(og.rbegin()) << std::endl;
	// std::cout << "*(og.rbegin() + 1): " << *(og.rbegin() + 1) << std::endl;
	// std::cout << "*(og.rbegin() + 2): " << *(og.rbegin() + 2) << std::endl;
	// std::cout << "*(og.rbegin() + 3): " << *(og.rbegin() + 3) << std::endl;
	
	return (0);
}