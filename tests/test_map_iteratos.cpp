/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_iteratos.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/09 14:23:39 by kmilchev         ###   ########.fr       */
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

int main(void)
{
	ft::map<int, int> mappy;
	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator it2;

	// it = mappy.begin();
	// std::cout << it->value->first << std::endl;
	// std::cout << it.operator++() << std::endl;
	
	// std::map<int, int> mapty;
	// std::map<int, int>::iterator it_m;

	// mapty.insert(std::make_pair(1, 10));
	// mapty.insert(std::make_pair(2, 20));
	// mapty.insert(std::make_pair(3, 30));
	// mapty.insert(std::make_pair(4, 40));
	// std::cout << mapty.begin()->first << std::endl;

	// it_m = mapty.begin();
	// it_m->
	// std::cout << it_m->first << std::endl;
	return (0);
}