# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 15:52:14 by hoomen            #+#    #+#              #
#    Updated: 2022/11/26 20:30:41 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		tests

SRC			=		Account.cpp tests.cpp

OBJ			=		$(addprefix obj/,$(SRC:%.cpp=%.o))

HDR			=		Account.hpp

CPP			=		c++

CPPFLAGS	=		-Wall -Werror -Wextra


all: $(NAME)


$(NAME) : $(OBJ) $(HDR)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)


obj/%.o : %.cpp | obj
	$(CPP) -c $(CPPFLAGS) $< -o $@


obj :
	mkdir obj


clean :
	rm -drf obj


fclean : clean
	rm -f $(NAME)


re : fclean all


.PHONY : all obj clean fclean re

