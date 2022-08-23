# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 23:30:29 by kmilchev          #+#    #+#              #
#    Updated: 2022/08/22 17:43:44 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED='\033[1;35m'
NC='\033[0m'


echo "${RED}test_default_constructor\n${NC}"
c++ ./tests/test_default_constructor.cpp && ./a.out

echo "${RED}test_fill_constructor.cpp\n${NC}"
c++ ./tests/test_fill_constructor.cpp && ./a.out

echo "${RED}test_vector_iter_methods.cpp\n${NC}"
c++ ./tests/test_vector_iter_methods.cpp && ./a.out

echo "${RED}\ntest_iterator_class.cpp\n${NC}"
c++ ./tests/test_iterator_class.cpp && ./a.out

echo "${RED}test_range_constructor.cpp\n${NC}"
c++ ./tests/test_range_constructor.cpp && ./a.out

echo "${RED}test_reverse_iterator.cpp\n${NC}"
c++ ./tests/test_reverse_iterator.cpp && ./a.out

echo "${RED}test_vector_functions.cpp\n${NC}"
c++ ./tests/test_vector_functions.cpp && ./a.out