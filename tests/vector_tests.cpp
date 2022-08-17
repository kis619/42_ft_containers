/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:59:04 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/16 18:26:30 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <memory>

using std::cout;
using std::endl;

namespace test
{
	int a = 180;
	void add_seven(int *i)
	{
		(*i) += 7;
	}
}

class Explicit_thingy
{
	
	public:
	explicit Explicit_thingy(int a) {};
};

void do_nothing(const Explicit_thingy& item)
{
	printf("Told you to do nothing...\n");
}

int main(void)
{

	// cout << "Capacity: " << numbers.capacity() << endl;
	// cout << "Size: " << numbers.size() << endl;
	// cout << numbers.capacity() << endl;
	// cout << numbers.capacity() << endl;
	// cout << numbers.capacity() << endl;

	std::allocator<int> obfuscating;
	std::vector<int, std::allocator<int> > numbers;

	int a = 7;
	cout << obfuscating.max_size() << endl;
	// cout << obfuscating.address(&a) << endl;
	return (0);
}