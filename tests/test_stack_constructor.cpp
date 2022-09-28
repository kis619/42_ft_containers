/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_constructor.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:43:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/28 10:10:57 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_stack.hpp"
#include <iostream>
#include <assert.h>
#include <string.h>
#include "../ft_utils.hpp"
#include "colours.h"
#include <stack>
#include <vector>

#include "utils.hpp"
int main(void)
{
	std::stack<int, std::vector<int> > og_stack;
	ft::stack<int, ft::vector<int> > my_stack;

	test_name("Testing .size()");
		assert(og_stack.size() == my_stack.size());
	test_name("Testing .empty()");
		assert(og_stack.empty() == my_stack.empty());
		og_stack.push(0);
		my_stack.push(0);
		assert(og_stack.size() == my_stack.size());
		assert(og_stack.empty() == my_stack.empty());
	
	test_name("Testing .push()");
		for (int i = 1; i <= 10; i++)
		{
			og_stack.push(i);
			my_stack.push(i);
			assert(og_stack.size() == my_stack.size());
			assert(og_stack.empty() == my_stack.empty());
		}
	
	test_name("Testing .top()");
		assert(og_stack.top() == my_stack.top());
		
	test_name("Testing .pop()");
		for (int i = 1; i <= 11; i++)
		{
			og_stack.pop();
			my_stack.pop();
			assert(og_stack.size() == my_stack.size());
			assert(og_stack.empty() == my_stack.empty());
		}
	
	return (0);
}
