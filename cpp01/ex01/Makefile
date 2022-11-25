# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:24:38 by hoomen            #+#    #+#              #
#    Updated: 2022/11/25 17:49:27 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		zombie

SRC			=		main.cpp Zombie.cpp zombieHorde.cpp 

HDR			=		Zombie.hpp

OBJ			=		$(addprefix obj/,$(SRC:.cpp=.o))

CPP			=		c++

CPPFLAGS	=		-Wall -Werror -Wextra



all : $(NAME)


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


.PHONY : all clean fclean re