/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_begin.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:20:18 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/21 23:27:12 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_vector.hpp"
#include "colours.h"
#include <iostream>
#include <vector>
#include <iterator>

int main(void)
{
	ft::vector<int>						my_v(4, 44);
	std::vector<int>					og_v;
	for (int i = 1; i < 5; i++){
		og_v.push_back(i);
		my_v[i - 1] = i;	
	}
	ft::vector<int>::iterator			my_it;
	std::vector<int>::iterator			og_it;
	
	const ft::vector<int>				my_v_const(3, 33);
	const std::vector<int>				og_v_const(3, 33);
	ft::vector<int>::const_iterator		my_const_it;
	std::vector<int>::const_iterator	og_const_it;
	
	my_it = my_v.begin();
	og_it = og_v.begin();
	std::cout << COLOUR_YELLOW << "vector.begin()\n" << COLOUR_DEFAULT;
	std::cout << "Mine:     " << COLOUR_GREEN << *(my_it) << COLOUR_DEFAULT << std::endl;
	std::cout << "Original: " << COLOUR_GREEN << *(og_it) << COLOUR_DEFAULT << std::endl;
	
	my_const_it = my_v_const.begin();
	og_const_it = og_v_const.begin();
	std::cout << COLOUR_YELLOW << "const_vector.begin()\n" << COLOUR_DEFAULT;
	std::cout << "Mine:     " << COLOUR_GREEN << *(my_const_it) << COLOUR_DEFAULT << std::endl;
	std::cout << "Original: " << COLOUR_GREEN << *(og_const_it) << COLOUR_DEFAULT << std::endl;
	
	my_it = my_v.end() - 1;
	og_it = og_v.end() - 1;
	std::cout << COLOUR_YELLOW << "vector.end()\n" << COLOUR_DEFAULT;
	std::cout << "Mine:     " << COLOUR_GREEN << *(my_it) << COLOUR_DEFAULT << std::endl;
	std::cout << "Original: " << COLOUR_GREEN << *(og_it) << COLOUR_DEFAULT << std::endl;
	
	my_const_it = my_v_const.end() - 1;
	og_const_it = og_v_const.end() - 1; 
	std::cout << COLOUR_YELLOW << "const_vector.end()\n" << COLOUR_DEFAULT;
	std::cout << "Mine:     " << COLOUR_GREEN << *(my_const_it) << COLOUR_DEFAULT << std::endl;
	std::cout << "Original: " << COLOUR_GREEN << *(og_const_it) << COLOUR_DEFAULT << std::endl;
	
	ft::vector<int>::reverse_iterator	my_r_it(my_v.rbegin());
	std::vector<int>::reverse_iterator	og_r_it(og_v.rbegin());
	std::cout << COLOUR_YELLOW << "rev_it(vector.rbegin())\n" << COLOUR_DEFAULT;
	std::cout << "Mine:     " << COLOUR_GREEN << *(my_r_it) << COLOUR_DEFAULT << std::endl;
	std::cout << "Original: " << COLOUR_GREEN << *(og_r_it) << COLOUR_DEFAULT << std::endl;
	
	ft::vector<int>::const_reverse_iterator		my_r_it_const(my_v_const.rbegin());
	std::vector<int>::const_reverse_iterator	og_r_it_const(og_v_const.rbegin());
	std::cout << COLOUR_YELLOW << "const_rev_it(vector.rbegin())\n" << COLOUR_DEFAULT;
	std::cout << "Mine:     " << COLOUR_GREEN << *(my_r_it_const) << COLOUR_DEFAULT << std::endl;
	std::cout << "Original: " << COLOUR_GREEN << *(og_r_it_const) << COLOUR_DEFAULT << std::endl;
	
	my_r_it = my_v.rend() - 1;
	og_r_it = og_v.rend() - 1;
	std::cout << COLOUR_YELLOW << "rev_it(vector.rend())\n" << COLOUR_DEFAULT;
	std::cout << "Mine:     " << COLOUR_GREEN << *(my_r_it) << COLOUR_DEFAULT << std::endl;
	std::cout << "Original: " << COLOUR_GREEN << *(og_r_it) << COLOUR_DEFAULT << std::endl;
	return (0);
}