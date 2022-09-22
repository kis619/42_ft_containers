/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/22 14:43:38 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "ft_map.hpp"
#include <string>
#include "ft_tree.hpp"
#include "ft_rbt_iterator.hpp"

int main(void)
{
	ft::map<int, int> my_map;
	int i = 0;
	i = 15;

	ft::map<int, int>::iterator it_less;
	ft::map<int, int, std::greater<int> >::iterator it_greater;

	my_map.insert(ft::make_pair(1, 1));
	my_map.insert(ft::make_pair(2, 1));
	it_less = it_greater;
	it_greater = my_map.begin();
	it_greater++;
	it_greater--;
	std::cout << it_greater->first << std::endl;
	it_less = my_map.end();
	it_less--;
	std::cout << it_less->first << std::endl;
	
	
	return (0);
}

// /*
// 	Red-Black trees maintain O(Log n) height by making sure 
// 	that the number of Black nodes on every root to leaf paths is the same 
// 	and there are no adjacent red nodes. 
// */


