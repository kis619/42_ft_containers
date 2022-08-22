/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/22 12:40:04 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// comparing size, capacity and max_size
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  // set some content in the vector:
  // for (int i=0; i<100; i++) myvector.push_back(i);

  // std::cout << "size: " << myvector.size() << "\n";
  // std::cout << "capacity: " << myvector.capacity() << "\n";
  // std::cout << "max_size: " << myvector.max_size() << "\n";
 
  int *data = myvector.data();
  std::cout << "First element: " << (data) << std::endl;
  return 0;
}