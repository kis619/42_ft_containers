# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zangelis <zangelis@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 13:21:52 by kmilchev          #+#    #+#              #
#    Updated: 2022/10/03 00:51:55 by zangelis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = c++

FLAGS = -Wall -Werror -Wextra -g

run:
	sh run_tests.sh

all:	test_iterator_class test_reverse_iterator test_pair_construction \
		map_tests \
		vector_tests \
		set_tests \
		test_stack


map_tests:		test_map_element_access \
				test_map_capacity \
				test_map_modifiers \
				test_map_observers \
				test_map_lookup \
				test_map_construction \
				test_map_reverse_iterators \
				test_map_logical_operators \
				test_map_iterators

vector_tests:	test_vector_capacity \
				test_vector_construction \
				test_vector_element_access \
				test_vector_iter_methods \
				test_vector_modifiers \
				test_vector_non_member_swap \
				test_vector_logical_operators

set_tests:		test_set_construction \
				test_set_iterators \
				test_set_capacity \
				test_set_lookup \
				test_set_modifiers \
				test_set_observers \
				test_set_logical_operators

stack_tests:		test_stack

test_iterator_class:
	$(CC) -g tests/utils.cpp tests/test_iterator_class.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_reverse_iterator:
	$(CC) -g tests/utils.cpp tests/test_reverse_iterator.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_vector_capacity:
	$(CC) -g tests/utils.cpp tests/test_vector_capacity.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_vector_construction:
	$(CC) -g tests/utils.cpp tests/test_vector_construction.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_vector_element_access:
	$(CC) -g tests/utils.cpp tests/test_vector_element_access.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_vector_iter_methods:
	$(CC) -g tests/utils.cpp tests/test_vector_iter_methods.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_vector_modifiers:
	$(CC) -g tests/utils.cpp tests/test_vector_modifiers.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_vector_non_member_swap:
	$(CC) -g tests/utils.cpp tests/test_vector_non_member_swap.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_vector_logical_operators:
	$(CC) -g tests/utils.cpp tests/test_vector_logical_operators.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_pair_construction:
	$(CC) -g tests/utils.cpp tests/test_pair_construction.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_map_iterators:
	$(CC) -g tests/utils.cpp tests/test_map_iterators.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_map_element_access:
	$(CC) -g tests/utils.cpp tests/test_map_element_access.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_map_capacity:
	$(CC) -g tests/utils.cpp tests/test_map_capacity.cpp -o $(NAME) $(FLAGS) && ./$(NAME)

test_map_modifiers:
	$(CC) -g tests/utils.cpp tests/test_map_modifiers.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)

test_map_observers:
	$(CC) -g tests/utils.cpp tests/test_map_observers.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)

test_map_lookup:
	$(CC) -g tests/utils.cpp tests/test_map_lookup.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_map_construction:
	$(CC) -g tests/utils.cpp tests/test_map_construction.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_map_reverse_iterators:
	$(CC) -g tests/utils.cpp tests/test_map_reverse_iterators.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_map_logical_operators:
	$(CC) -g tests/utils.cpp tests/test_map_logical_operators.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_stack:
	$(CC) -g tests/utils.cpp tests/test_stack_constructor.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_set_construction:
	$(CC) -g tests/utils.cpp tests/test_set_construction.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)

test_set_iterators:
	$(CC) -g tests/utils.cpp tests/test_set_iterators.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)

test_set_capacity:
	$(CC) -g tests/utils.cpp tests/test_set_capacity.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_set_lookup:
	$(CC) -g tests/utils.cpp tests/test_set_lookup.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_set_modifiers:
	$(CC) -g tests/utils.cpp tests/test_set_modifiers.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_set_observers:
	$(CC) -g tests/utils.cpp tests/test_set_observers.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)
	
test_set_logical_operators:
	$(CC) -g tests/utils.cpp tests/test_set_logical_operators.cpp -g -o $(NAME) $(FLAGS) && ./$(NAME)

clean:
	@rm -rf $(NAME) a.out

fclean: clean

re: clean