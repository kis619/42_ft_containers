/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/19 20:59:05 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iterator>
#include "ft_iterator.hpp"
#include "ft_vector.hpp"
#include <iostream>
// class MyIterator : ft::iterator<ft::random_access_iterator_tag, int>
// {
	
// }
int main(void)
{
	std::vector<float> numbers;
	numbers.push_back(1.0);
	numbers.push_back(2.0);
	numbers.push_back(3.0);
	numbers.push_back(4.0);

	std::vector<float>::iterator it;
	

	it = numbers.begin();
	std::iterator_traits<int> k;
	// std::iterator<ft::random_access_iterator_tag, int> ko;
	// #include <typeinfo>
	// if (typeid(ft::iterator_traits<float*>::iterator_category) == typeid(ft::input_iterator_tag))
	// 	std::cout << "Float is a random_access_iterator" << std::endl;

	std::vector<float>::iterator g;
	g = numbers.begin();
	std::cout<< *(g.base() + 1);
	g++;
	std::cout<< *(g.base());
	g--;
	std::cout<< *(g.base());
	g -= 2;
	std::cout<< *(g.base());
	
	ft::random_access_iterator<int> m;
	ft::random_access_iterator<int> n;
	ft::vector<int> nums(4, 44);
	m = nums.begin();
	std::cout << "\n" << *(nums.begin());
	return(0);
}