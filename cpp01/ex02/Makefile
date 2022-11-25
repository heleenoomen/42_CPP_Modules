# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 19:09:34 by hoomen            #+#    #+#              #
#    Updated: 2022/11/25 19:22:54 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		brain

SRC			=		main.cpp

OBJ			=		$(addprefix obj/,$(SRC:.cpp=.o))

CPP			=		c++

CPPFLAGS	=		-Wall -Werror -Wextra


all : $(NAME)

$(NAME) : $(OBJ)
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
	@./brain

.PHONY : all clean fclean re run
