/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/01 09:48:59 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include <map>
// #include <stack>

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <ft_map.hpp>
// 	#include <ft_stack.hpp>
// 	#include <ft_vector.hpp>
// #endif

#include <stdlib.h>
class Node
{
	public:
		int i;	
		Node *left;
		Node *right;
	
	Node(int val) : i(val), left(NULL), right(NULL) {};
};

#include "ft_map.hpp"
// int main(void)
// {
// 	Node *root = new Node(1);
	
// 	root->left = new Node(2);
// 	root->left = new Node(3);
	
// 	root->left->left = new Node(4);
	

	
// 	return (0);
// }


#include <iostream>
#include <map>
#include <functional>
#include "ft_vector.hpp"
#include <string.h>

template <class T, class U>
class Test_Functor : public std::binary_function<T, U, bool>
{
	// int i = int();
	
	public:
		typedef	std::binary_function<T, U, bool> 						templ;
		typedef typename templ::first_argument_type						word;
		typedef typename templ::second_argument_type					word2;
		void operator()(void) {std::cout << "Whatevs\n";}
		
		word do_nothing(){return (27.8);};
		word2 do_nothing_still(){return (43.3);};

		
		
};

int main ()
{

	ft::pair<int, int> my_pair;
	
	std::cout << my_pair.first << "\n";
	std::cout << my_pair.second << "\n";
	
	return 0;
}