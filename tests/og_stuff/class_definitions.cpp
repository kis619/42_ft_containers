/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_definitions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:00:26 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/15 15:16:33 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class_definition.h"
#include "colours.h"

Test::Test(void)
{
	cout << COLOUR_GREEN << "Default Constructor called\n" << COLOUR_DEFAULT;
	this->test_integer_pointer = new int(0);
}

Test::Test(int i)
{
	cout << COLOUR_GREEN << "Integer Constructor called\n" << COLOUR_DEFAULT;
	this->test_integer_pointer = new int (i);
}

Test::Test(const Test& copy)
{
	cout << COLOUR_YELLOW << "Copy Constructor called\n" << COLOUR_DEFAULT;
	*this = copy;
}

Test::~Test(void)
{
	cout << COLOUR_RED << "Destructor called\n" << COLOUR_DEFAULT;
	delete test_integer_pointer;
}

Test & Test::operator=(const Test& other)
{
	delete this->test_integer_pointer;
	cout << COLOUR_YELLOW << "Assignemnt op called\n" << COLOUR_DEFAULT;
	this->test_integer_pointer = new int (*(other.test_integer_pointer));
	return (*this);
}