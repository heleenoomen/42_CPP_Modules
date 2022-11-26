# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 20:00:04 by hoomen            #+#    #+#              #
#    Updated: 2022/11/26 12:07:40 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	unnecessary_violence

SRC			=	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJ			=	$(addprefix obj/,$(SRC:.cpp=.o))

HDR			=	HumanA.hpp HumanB.hpp Weapon.hpp

CPP			=	c++

CPPFLAGS	=	-Wall -Werror -Wextra


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

run : $(NAME)
	@./unnecessary_violence

.PHONY : all clean fclean re run
