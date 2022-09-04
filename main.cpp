/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/04 14:38:02 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "ft_map.hpp"
#include <string>
#include "ft_tree.hpp"

int main(void)
{

	// ft::RBTree<int, double> tree = ft::RBTree<int, double>();

	// std::cout << std::boolalpha << tree.nil_node->colour << std::endl;

	// tree.insert(ft::make_pair(1, 1.1));
	// tree.insert(ft::make_pair(2, 2.1));
	// tree.insert(ft::make_pair(0, 7.1));
	// tree.insert(ft::make_pair(8, 7.1));
	// tree.insert(ft::make_pair(9, 7.1));
	// tree.insert(ft::make_pair(4, 7.1));

	// std::cout << tree.root->right->data.first << std::endl;
	// std::cout << tree.root->right->data.second << std::endl;
	// std::cout << tree.root->left->data.second << std::endl;
	// tree.print_tree();
	// std::map<int, int> mappy;
	// Test::g = 10;
	ft::map<int, int> mappy;
	// std::cout << &mappy << std::endl;
	int a = 1;
	int b = 2;
	ft::pair<int, int> test1 = ft::make_pair(1, 1);
	ft::pair<int, int> test2 = ft::make_pair(2, 1);
	ft::pair<int, int> test3 = ft::make_pair(3, 1);
	ft::pair<int, int> test4 = ft::make_pair(4, 1);
	ft::pair<int, int> test5 = ft::make_pair(5, 1);
	// ft::pair<int, int> test = ft::make_pair(5, 1);
	
	mappy.tree.insert(test1);
	mappy.tree.print_tree();
	mappy.tree.insert(test2);
	mappy.tree.print_tree();
	mappy.tree.insert(test3);
	mappy.tree.print_tree();
	mappy.tree.insert(test4);
	mappy.tree.print_tree();
	mappy.tree.insert(test5);
	mappy.tree.print_tree();
	mappy.tree.erase(test1);
	mappy.tree.print_tree();
	mappy.tree.erase(test2);
	mappy.tree.print_tree();
	mappy.tree.erase(test3);
	mappy.tree.erase(test4);
	mappy.tree.erase(test5);
	// mappy.tree.print_tree();



	std::map<int, int> mappty;
	mappty.insert(std::make_pair(1, 9));
	mappty.insert(std::make_pair(2, 10));
	mappty.insert(std::make_pair(3, 11));

	mappty.erase(3);
	// mappty.
	return (0);
}

// /*
// 	Red-Black trees maintain O(Log n) height by making sure 
// 	that the number of Black nodes on every root to leaf paths is the same 
// 	and there are no adjacent red nodes. 
// */


