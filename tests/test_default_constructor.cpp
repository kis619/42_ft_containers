/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_default_constructor.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:20:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/22 17:45:18 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include <iostream>

// using namespace ft;

int main(void)
{
	ft::vector<int> test;

	std::cout << test.capacity() << std::endl;
	return (0);
}