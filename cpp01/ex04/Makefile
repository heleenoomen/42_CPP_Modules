# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 20:02:20 by hoomen            #+#    #+#              #
#    Updated: 2022/11/26 20:29:41 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	main.cpp

OBJ			=	$(addprefix obj/,$(SRC:.cpp=.o))

CPP			=	c++

CPPFLAGS	=	-Wall -Werror -Wextra

NAME		=	sed_is_for_losers


all : $(NAME)

$(NAME) : $(OBJ)
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
	./$(NAME) main.cpp std Elephant

rmf :
	rm *.replace

.PHONY : all clean fclean re run rmf
