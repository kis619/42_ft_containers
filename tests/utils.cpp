/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:33:13 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/27 18:36:59 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "colours.h"


void test_name(std::string name)
{
	std::cout << COLOUR_BLUE << name << COLOUR_RED << std::endl;
}