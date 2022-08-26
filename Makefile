# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 13:21:52 by kmilchev          #+#    #+#              #
#    Updated: 2022/08/26 14:42:49 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

test_iterator_class:
	$(CC) -g tests/test_iterator_class.cpp && ./a.out

test_reverse_iterator:
	$(CC) -g tests/test_reverse_iterator.cpp && ./a.out

test_vector_capacity:
	$(CC) -g tests/test_vector_capacity.cpp && ./a.out

test_vector_construction:
	$(CC) -g tests/test_vector_construction.cpp && ./a.out

test_vector_element_access:
	$(CC) -g tests/test_vector_element_access.cpp && ./a.out

test_vector_iter_methods:
	$(CC) -g tests/test_vector_iter_methods.cpp && ./a.out

test_vector_modifiers:
	$(CC) -g tests/test_vector_modifiers.cpp && ./a.out