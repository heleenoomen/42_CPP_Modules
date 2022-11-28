# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:24:38 by hoomen            #+#    #+#              #
#    Updated: 2022/11/27 16:18:50 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		zombie

SRC			=		main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

HDR			=		Zombie.hpp

DEP			=		$(addprefix obj/,$(SRC:.cpp=.d))

OBJ			=		$(addprefix obj/,$(SRC:.cpp=.o))

CPP			=		c++

CPPFLAGS	=		-Wall -Werror -Wextra



all : $(NAME)


$(NAME) : $(OBJ) $(HDR)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

# .cpp.o:
obj/%.o : %.cpp | obj
	${CPP} ${CPPFLAGS} -MMD -MP -c $< -o $(addprefix obj/${<:.cpp=.o})

#obj/%.o : %.cpp | obj
#$(CPP) -c $(CPPFLAGS) -M -MD $< -o $@

obj :
	mkdir obj

clean :
	rm -drf obj

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEP)

.PHONY : all clean fclean re