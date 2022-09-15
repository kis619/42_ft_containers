# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 13:21:52 by kmilchev          #+#    #+#              #
#    Updated: 2022/09/15 22:15:45 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++


test_iterator_class:
	$(CC) -g tests/utils.cpp tests/test_iterator_class.cpp && ./a.out

test_reverse_iterator:
	$(CC) -g tests/utils.cpp tests/test_reverse_iterator.cpp && ./a.out

test_vector_capacity:
	$(CC) -g tests/utils.cpp tests/test_vector_capacity.cpp && ./a.out

test_vector_construction:
	$(CC) -g tests/utils.cpp tests/test_vector_construction.cpp && ./a.out

test_vector_element_access:
	$(CC) -g tests/utils.cpp tests/test_vector_element_access.cpp && ./a.out

test_vector_iter_methods:
	$(CC) -g tests/utils.cpp tests/test_vector_iter_methods.cpp && ./a.out

test_vector_modifiers:
	$(CC) -g tests/utils.cpp tests/test_vector_modifiers.cpp && ./a.out

test_vector_non_member_swap:
	$(CC) -g tests/utils.cpp tests/test_vector_non_member_swap.cpp && ./a.out

test_vector_logical_operators:
	$(CC) -g tests/utils.cpp tests/test_vector_logical_operators.cpp && ./a.out

test_pair_construction:
	$(CC) -g tests/utils.cpp tests/test_pair_construction.cpp && ./a.out

test_tree_methods:
	$(CC) -g tests/utils.cpp tests/test_tree_methods.cpp && ./a.out

test_tree_iterator:
	$(CC) -g tests/utils.cpp tests/test_tree_iterator.cpp && ./a.out

test_map_iterators:
	$(CC) -g tests/utils.cpp tests/test_map_iterators.cpp && ./a.out

test_map_element_access:
	$(CC) -g tests/utils.cpp tests/test_map_element_access.cpp && ./a.out

test_map_capacity:
	$(CC) -g tests/utils.cpp tests/test_map_capacity.cpp && ./a.out

test_map_modifiers:
	$(CC) -g tests/utils.cpp tests/test_map_modifiers.cpp -g && ./a.out

test_map_observers:
	$(CC) -g tests/utils.cpp tests/test_map_observers.cpp -g && ./a.out

test_map_lookup:
	$(CC) -g tests/utils.cpp tests/test_map_lookup.cpp -g && ./a.out
	
test_map_construction:
	$(CC) -g tests/utils.cpp tests/test_map_construction.cpp -g && ./a.out
	
test:
	sh run_tests.sh

tests:	test_iterator_class test_reverse_iterator test_vector_capacity test_vector_construction test_vector_element_access \
		test_vector_iter_methods test_vector_modifiers test_vector_non_member_swap test_vector_logical_operators \
		test_pair_construction test_tree_methods test_tree_iterator test_map_element_access test_map_capacity test_map_modifiers \
		test_map_observers test_map_lookup

map_tests: test_map_element_access test_map_capacity test_map_modifiers test_map_observers test_map_lookup test_map_construction