# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:52:14 by hoomen            #+#    #+#              #
#    Updated: 2022/11/28 11:51:53 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		tests

SRC			=		Account.cpp tests.cpp

OBJ			=		$(addprefix obj/,$(SRC:%.cpp=%.o))

HDR			=		Account.hpp

CXX			=		c++

CXXFLAGS	=		-Wall -Werror -Wextra -std=c++98


all: $(NAME)


$(NAME) : $(OBJ) $(HDR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


obj/%.o : %.cpp | obj
	$(CXX) -c $(CXXFLAGS) $< -o $@


obj :
	mkdir obj


clean :
	rm -drf obj


fclean : clean
	rm -f $(NAME)


re : fclean all


.PHONY : all obj clean fclean re

