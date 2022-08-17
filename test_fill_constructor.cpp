/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fill_constructor.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:00:01 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/17 19:37:40 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <iostream>

class Whatever
{
	public:
		int *_array;
		std::allocator<int> john;
		
	Whatever(int size, int value)
	{
		int i = 0;
		_array = new int(size);
		// _array = john.allocate(size);
		while (size)
		{
			// john.construct(_array, value + i);
			*(_array) = value + i;
			size--;
			i++;
			_array+=1;
		}
	}
};

int main(void)
{
	ft::vector<int> test(4, 69);

	std::cout << "Size: " << test._capacity << std::endl;
	std::cout << "Element 0: " << *(test._begin) << std::endl;
	std::cout << "Element 1: " << *(test._begin + 1) << std::endl;
	std::cout << "Element 2: " << *(test._begin + 2) << std::endl;
	std::cout << "Element 3: " << *(test._begin + 3) << std::endl;
	
	// Whatever test(4, 69);
	// std::cout << "Element 0: " << *(test._array - 4) << std::endl;
	// std::cout << "Element 1: " << *(test._array - 3) << std::endl;
	// std::cout << "Element 2: " << *(test._array - 2) << std::endl;
	// std::cout << "Element 3: " << *(test._array - 1) << std::endl;
	

	return (0);
}