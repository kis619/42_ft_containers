/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/03 22:26:57 by kmilchev         ###   ########.fr       */
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
	mappy.tree.insert(ft::make_pair(a, b));
	// mappy.tree.insert(ft::make_pair(2, b));
	// mappy.tree.insert(ft::make_pair(3, b));
	// mappy.tree.insert(ft::make_pair(4, b));
	// mappy.tree.insert(ft::make_pair(5, b));

	mappy.tree.print_tree();
	return (0);
}

// /*
// 	Red-Black trees maintain O(Log n) height by making sure 
// 	that the number of Black nodes on every root to leaf paths is the same 
// 	and there are no adjacent red nodes. 
// */


