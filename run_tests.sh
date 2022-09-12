# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 23:30:29 by kmilchev          #+#    #+#              #
#    Updated: 2022/09/12 14:56:06 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE='\033[1;35m'
NC='\033[0m'

echo "${PURPLE}\ntest_iterator_class.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_iterator_class.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_reverse_iterator.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_reverse_iterator.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_vector_capacity.cpp${NC}"
c++ tests/utils.cpp tests/test_vector_capacity.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_vector_construction.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_vector_construction.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_vector_element_access.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_vector_element_access.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_vector_iter_methods.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_vector_iter_methods.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_vector_modifiers.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_vector_modifiers.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_vector_non_member_swap.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_vector_non_member_swap.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_vector_logical_operators.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_vector_logical_operators.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_pair_construction.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_pair_construction.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_tree_methods.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_tree_methods.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_map_iterators.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_map_iterators.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1

echo "${PURPLE}\ntest_map_element_access.cpp${NC}"
c++ ./tests/utils.cpp ./tests/test_map_element_access.cpp && leaks -atExit -- ./a.out  > file1; <file1 grep "leaks for"; rm file1
