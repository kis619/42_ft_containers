/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_range_constructor.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:34:12 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/20 19:49:03 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	std::vector<int> numbers;

	numbers.push_back(23);
	numbers.push_back(14);
	numbers.push_back(51);
	it = numbers.begin();
	it2 = numbers.end();
	// std::cout << *it << std::endl;
	// std::cout << *(it2 - 1) << std::endl;
	ft::vector<int> numbers2(it, it2);
	std::cout << "Capacity: " << numbers2._capacity << std::endl;
	std::cout << *(numbers2._begin) << std::endl;
	std::cout << *(numbers2._begin + 1) << std::endl;
	std::cout << *(numbers2._begin + 2) << std::endl;
	return (0);
}
