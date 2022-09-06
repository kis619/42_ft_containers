/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tree_iterator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/07 01:38:08 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "../ft_map.hpp"
#include "../ft_vector.hpp"
#include "../ft_tree.hpp"
#include "colours.h"
#include "utils.hpp"
#include <map>

typedef ft::RBTree< ft::pair<int, int> , ft::map<int, int>::value_compare, ft::map<int, int>::allocator_type > tree_type;

int main(void)
{
	std::allocator<ft::pair<const int, int> > alloc;
	std::less<int> comp = std::less<int>();
	tree_type tree(comp, alloc);
	tree_type::iterator *it;
	tree_type::iterator *it2;
	tree_type::iterator *it3(it2);

	{
		test_name("Testing the copy constructor");
		assert(it2 == it3);
	}

	test_name("Testing operator*");
	assert((it3->operator*()).value.first == (it2->operator*()).value.first);

	
	test_name("Testing operator->");
	assert(it3->operator->() == it2->operator->());
	// (it) = (it2);
	// std::cout << (*it) << std::endl;
	// std::cout << (it)->ptr << std::endl;
	// std::cout << it.ptr << std::endl;

	tree_type::iterator beginning;
	beginning = tree.begin();
	std::cout << tree.begin().operator*().value.first <<std::endl;
	
	
	
	return (0);
}
