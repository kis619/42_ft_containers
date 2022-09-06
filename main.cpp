/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/07 00:44:09 by kmilchev         ###   ########.fr       */
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

	// ft::map<int, int> mappy;
	// // std::cout << &mappy << std::endl;
	// int a = 1;
	// int b = 2;
	// ft::pair<int, int> test1 = ft::make_pair(1, 1);
	// ft::pair<int, int> test2 = ft::make_pair(2, 1);
	// ft::pair<int, int> test3 = ft::make_pair(3, 1);
	// ft::pair<int, int> test4 = ft::make_pair(4, 1);
	// ft::pair<int, int> test5 = ft::make_pair(5, 1);
	// ft::pair<int, int> test6 = ft::make_pair(6, 1);
	// ft::pair<int, int> test7 = ft::make_pair(7, 1);
	// ft::pair<int, int> test8 = ft::make_pair(8, 1);
	// ft::pair<int, int> test9 = ft::make_pair(9, 1);
	// ft::pair<int, int> test91 = ft::make_pair(91, 1);
	// ft::pair<int, int> test92 = ft::make_pair(92, 1);
	// ft::pair<int, int> test93 = ft::make_pair(93, 1);
	// ft::pair<int, int> test94 = ft::make_pair(94, 1);
	// mappy.tree.insert(test1);
	// mappy.tree.insert(test2);
	// mappy.tree.insert(test3);
	// mappy.tree.insert(test4);
	// mappy.tree.insert(test5);
	// mappy.tree.insert(test6);
	// mappy.tree.insert(test7);
	// mappy.tree.insert(test8);
	// mappy.tree.insert(test9);
	// mappy.tree.insert(test91);
	// mappy.tree.insert(test92);
	// mappy.tree.insert(test93);
	// mappy.tree.print_tree();
	// std::cout << "Size: " << mappy.tree.size() << std::endl;
	// std::cout << "Value at should be 3: " << mappy.at(3) << std::endl;
	// try
	// {
	// 	std::cout << "Value at should be 3: " << mappy.at(16) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << COLOUR_RED << e.what() << '\n' << COLOUR_DEFAULT;
	// }
	
	// std::cout << mappy.erase(1) << std::endl;
	// mappy.tree.erase(test2);
	// mappy.tree.erase(test3);
	// mappy.tree.erase(test4);
	// mappy.tree.erase(test5);
	// mappy.tree.erase(test6);
	// mappy.tree.erase(test7);
	// mappy.tree.erase(test8);
	// mappy.tree.erase(test9);
	// mappy.tree.erase(test91);
	// std::cout << mappy.erase(92) << std::endl;
	// std::cout << "Size after everything nut one is erased: " << mappy.tree.size() << std::endl;
	// mappy.tree.erase(test93);
	// mappy.tree.print_tree();
	// // std::cout << "\nConfusion\n";
	// std::cout << "Size after everything is erased: " << mappy.tree.size() << std::endl;
	


	// std::map<int, int> mappty;
	// std::pair<int, int> one = std::make_pair(1, 9);
	// std::pair<int, int> two = std::make_pair(2, 10);
	// std::pair<int, int> three = std::make_pair(3, 11);
	// mappty.insert(one);
	// mappty.insert(two);
	// mappty.insert(three);
	// std::map<int, int>::iterator it = mappty.begin();
	// try
	// {
	// 	std::cout << mappty.at(0);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout<< "Iterator at begin, first: " << (*it).first << std::endl;
	// std::cout<< "Iterator at begin, second: " << (*it).second << std::endl;
	// std::cout<< "Iterator at begin +1 , first: " << (*(++it)).first << std::endl;
	// std::cout<< "Iterator at begin +1, second: " << (*it++).second << std::endl;
	// std::cout<< "Iterator at begin +2, first: " << (*it).first << std::endl;
	// std::cout<< "Iterator at begin +2, second: " << (*(it)).second << std::endl;
	// (*it) = *(mappty.end());
	// std::cout << *it << std::endl;
	
	std::map<int, int> mappy;
	std::map<int, int>::iterator it;
	for (int i = 0; i < 10; i ++)
	{
		mappy.insert(std::make_pair(i + 1, i + 10));
	}
	it = mappy.begin();
	std::cout << (*(++it)).first << std::endl;
	std::cout << (*it).second << std::endl;
	for (; it != mappy.end(); it++)
	{
		std::cout << (*it).first << std::endl;
	}
		std::cout << (*it).first << std::endl;
		++it;
		std::cout << (*it).first << std::endl;
	// it.
	return (0);
}

// /*
// 	Red-Black trees maintain O(Log n) height by making sure 
// 	that the number of Black nodes on every root to leaf paths is the same 
// 	and there are no adjacent red nodes. 
// */


