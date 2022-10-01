# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 13:21:52 by kmilchev          #+#    #+#              #
#    Updated: 2022/10/01 13:42:51 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

# FLAGS = -fsanitize=address -g

test_iterator_class:
	$(CC) -g tests/utils.cpp tests/test_iterator_class.cpp $(FLAGS) && ./a.out

test_reverse_iterator:
	$(CC) -g tests/utils.cpp tests/test_reverse_iterator.cpp $(FLAGS) && ./a.out

test_vector_capacity:
	$(CC) -g tests/utils.cpp tests/test_vector_capacity.cpp $(FLAGS) && ./a.out

test_vector_construction:
	$(CC) -g tests/utils.cpp tests/test_vector_construction.cpp $(FLAGS) && ./a.out

test_vector_element_access:
	$(CC) -g tests/utils.cpp tests/test_vector_element_access.cpp $(FLAGS) && ./a.out

test_vector_iter_methods:
	$(CC) -g tests/utils.cpp tests/test_vector_iter_methods.cpp $(FLAGS) && ./a.out

test_vector_modifiers:
	$(CC) -g tests/utils.cpp tests/test_vector_modifiers.cpp $(FLAGS) && ./a.out

test_vector_non_member_swap:
	$(CC) -g tests/utils.cpp tests/test_vector_non_member_swap.cpp $(FLAGS) && ./a.out

test_vector_logical_operators:
	$(CC) -g tests/utils.cpp tests/test_vector_logical_operators.cpp $(FLAGS) && ./a.out

test_pair_construction:
	$(CC) -g tests/utils.cpp tests/test_pair_construction.cpp $(FLAGS) && ./a.out

test_tree_methods:
	$(CC) -g tests/utils.cpp tests/test_tree_methods.cpp $(FLAGS) && ./a.out

test_tree_iterator:
	$(CC) -g tests/utils.cpp tests/test_tree_iterator.cpp $(FLAGS) && ./a.out

test_map_iterators:
	$(CC) -g tests/utils.cpp tests/test_map_iterators.cpp $(FLAGS) && ./a.out

test_map_element_access:
	$(CC) -g tests/utils.cpp tests/test_map_element_access.cpp $(FLAGS) && ./a.out

test_map_capacity:
	$(CC) -g tests/utils.cpp tests/test_map_capacity.cpp $(FLAGS) && ./a.out

test_map_modifiers:
	$(CC) -g tests/utils.cpp tests/test_map_modifiers.cpp -g $(FLAGS) && ./a.out

test_map_observers:
	$(CC) -g tests/utils.cpp tests/test_map_observers.cpp -g $(FLAGS) && ./a.out

test_map_lookup:
	$(CC) -g tests/utils.cpp tests/test_map_lookup.cpp -g $(FLAGS) && ./a.out
	
test_map_construction:
	$(CC) -g tests/utils.cpp tests/test_map_construction.cpp -g $(FLAGS) && ./a.out
	
test_map_reverse_iterators:
	$(CC) -g tests/utils.cpp tests/test_map_reverse_iterators.cpp -g $(FLAGS) && ./a.out
	
test_map_logical_operators:
	$(CC) -g tests/utils.cpp tests/test_map_logical_operators.cpp -g $(FLAGS) && ./a.out
	
test_stack:
	$(CC) -g tests/utils.cpp tests/test_stack_constructor.cpp -g $(FLAGS) && ./a.out
	
test_set_construction:
	$(CC) -g tests/utils.cpp tests/test_set_construction.cpp -g $(FLAGS) && ./a.out

test_set_iterators:
	$(CC) -g tests/utils.cpp tests/test_set_iterators.cpp -g $(FLAGS) && ./a.out

test_set_capacity:
	$(CC) -g tests/utils.cpp tests/test_set_capacity.cpp -g $(FLAGS) && ./a.out
	
test_set_lookup:
	$(CC) -g tests/utils.cpp tests/test_set_lookup.cpp -g $(FLAGS) && ./a.out
	
test_set_modifiers:
	$(CC) -g tests/utils.cpp tests/test_set_modifiers.cpp -g $(FLAGS) && ./a.out
	
test_set_observers:
	$(CC) -g tests/utils.cpp tests/test_set_observers.cpp -g $(FLAGS) && ./a.out
	
test_set_logical_operators:
	$(CC) -g tests/utils.cpp tests/test_set_logical_operators.cpp -g $(FLAGS) && ./a.out
	
test:
	sh run_tests.sh

tests:	test_iterator_class test_reverse_iterator test_vector_capacity test_vector_construction test_vector_element_access \
		test_vector_iter_methods test_vector_modifiers test_vector_non_member_swap test_vector_logical_operators \
		test_pair_construction test_tree_methods test_tree_iterator test_map_element_access test_map_capacity test_map_modifiers \
		test_map_observers test_map_lookup test_map_reverse_iterators test_map_logical_operators \
		test_stack \
		test_set_construction test_set_iterators test_set_capacity test_set_lookup test_set_modifiers test_set_observers test_set_logical_operators

map_tests: test_map_element_access test_map_capacity test_map_modifiers test_map_observers test_map_lookup test_map_construction test_map_reverse_iterators \
			test_map_logical_operators

set_tests: test_set_construction test_set_iterators test_set_capacity test_set_lookup test_set_modifiers test_set_observers test_set_logical_operators