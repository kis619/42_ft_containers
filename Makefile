# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 13:21:52 by kmilchev          #+#    #+#              #
#    Updated: 2022/09/01 09:58:24 by kmilchev         ###   ########.fr        #
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

test:
	sh run_tests.sh