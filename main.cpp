/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/18 15:59:12 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "ft_map.hpp"
#include <string>
// #include "ft_tree.hpp"
#include "ft_rbt_iterator.hpp"

int main(void)
{

	ft::map<int, int> mappy;
	// std::cout << &mappy << std::endl;
	ft::map<int, int>::iterator it;
	
	// it = mappy.insert(ft::make_pair(1, 2));
	// std::cout << it->first << std::endl;
	// it = mappy.insert(ft::make_pair(2, 3));
	// std::cout << it->first << std::endl;
	// it = mappy.insert(ft::make_pair(3, 4));
	// std::cout << it->first << std::endl;
	// it = mappy.insert(ft::make_pair(4, 5));
	// std::cout << it->first << std::endl;
	// it = mappy.insert(ft::make_pair(5, 6));
	// std::cout << it->first << std::endl;
	// it = mappy.insert(ft::make_pair(6, 7));
	// std::cout << it->first << std::endl;
	// it = mappy.insert(ft::make_pair(7, 8));
	// std::cout << it->first << std::endl;
	// it = mappy.insert(ft::make_pair(8, 9));
	// std::cout << it->first << std::endl;




	return (0);
}

// /*
// 	Red-Black trees maintain O(Log n) height by making sure 
// 	that the number of Black nodes on every root to leaf paths is the same 
// 	and there are no adjacent red nodes. 
// */


