# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 23:28:55 by hoomen            #+#    #+#              #
#    Updated: 2022/11/27 15:48:39 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	harlFilter

SRC			=	Harl.cpp main.cpp

OBJ			=	$(addprefix obj/,$(SRC:.cpp=.o))

HDR			=	Harl.hpp

CPP			=	c++

CPPFLAGS	=	-Wall -Werror -Wextra


all : $(NAME)

$(NAME) : $(OBJ) $(HDR)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

obj/%.o : %.cpp | obj
	$(CPP) $(CPPFLAGS) -c $< -o $@

obj :
	mkdir obj

clean :
	rm -drf obj

fclean : clean
	rm -f $(NAME)

re : fclean all

run : $(NAME)
	./$(NAME)

.PHONY : all clean fclean re run
