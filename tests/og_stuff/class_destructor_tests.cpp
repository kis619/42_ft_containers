/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_destructor_tests.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:57:43 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/15 15:10:55 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class_definition.h"
#include "colours.h"

int main(void)
{
	Test default_constr;
	Test int_constructor(8);
	Test copy_of_a(int_constructor);
	cout << COLOUR_BLUE << *(default_constr.test_integer_pointer) << "\n" << COLOUR_DEFAULT;
	cout << COLOUR_BLUE << *(int_constructor.test_integer_pointer) << "\n" << COLOUR_DEFAULT;
	cout << COLOUR_BLUE << *(copy_of_a.test_integer_pointer) << "\n" << COLOUR_DEFAULT;
	
	Test og_object(42);
	Test new_object(420);
	cout << COLOUR_BLUE << "OG OBJECT: " << *(og_object.test_integer_pointer) << "\n" << COLOUR_DEFAULT;
	cout << COLOUR_BLUE << "NEW OBJECT: " << *(new_object.test_integer_pointer) << "\n" << COLOUR_DEFAULT;

	og_object = new_object;
	cout << COLOUR_BLUE << "OG OBJECT after assignment: " << *(og_object.test_integer_pointer) << "\n" << COLOUR_DEFAULT;
	cout << COLOUR_BLUE << "OG OBJECT address after assignment: " << (og_object.test_integer_pointer) << "\n" << COLOUR_DEFAULT;
	cout << COLOUR_BLUE << "NEW OBJECT address after assignment: " << (new_object.test_integer_pointer) << "\n" << COLOUR_DEFAULT;

	Test *pointer_object = new Test(22);
	Test *pointer_object_copy_constructor = new Test(*pointer_object);
	cout << COLOUR_YELLOW << pointer_object->test_integer_pointer << '\n';
	cout << COLOUR_BLUE << *(pointer_object->test_integer_pointer) << '\n';
	cout << COLOUR_YELLOW << pointer_object_copy_constructor->test_integer_pointer << '\n';
	cout << COLOUR_BLUE << *(pointer_object_copy_constructor->test_integer_pointer) << '\n';
	delete pointer_object;
	delete pointer_object_copy_constructor;
	return (0);
}