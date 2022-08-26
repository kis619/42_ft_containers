# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 23:30:29 by kmilchev          #+#    #+#              #
#    Updated: 2022/08/26 15:31:59 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE='\033[1;35m'
NC='\033[0m'


echo "${PURPLE}test_vector_construction.cpp\n${NC}"
c++ ./tests/test_vector_construction.cpp && ./a.out

echo "${PURPLE}test_vector_iter_methods.cpp\n${NC}"
c++ ./tests/test_vector_iter_methods.cpp && ./a.out

echo "${PURPLE}\ntest_iterator_class.cpp\n${NC}"
c++ ./tests/test_iterator_class.cpp && ./a.out

echo "${PURPLE}test_reverse_iterator.cpp\n${NC}"
c++ ./tests/test_reverse_iterator.cpp && ./a.out

echo "${PURPLE}test_vector_modifiers.cpp\n${NC}"
c++ ./tests/test_vector_modifiers.cpp && ./a.out