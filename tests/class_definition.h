/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_definition.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:56:37 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/15 15:16:36 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CLASS_DEF
# define TEST_CLASS_DEF

#include <iostream>

using std::cout;

class Test
{
	private: 
	public:
		int* test_integer_pointer;
		Test(void);
		Test(int);
		Test(float);
		~Test(void);
		Test(const Test &rhs);
		Test & operator=(const Test &other);
};

#endif