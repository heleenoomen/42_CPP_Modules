# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 20:00:04 by hoomen            #+#    #+#              #
#    Updated: 2022/11/28 16:56:02 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	unnecessaryViolence

CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98

DEPFLAGS	=	-MT @ -MMD -MP -MF $(DDIR)/$*.d

SRC			=	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

ODIR		=	obj
OBJ			=	$(SRC:%.cpp=$(ODIR)/%.o)

DDIR		=	$(ODIR)/.deps
DEP			=	$(SRC:%.cpp=$(DDIR)/%.d)


.PHONY : all clean fclean re

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(ODIR)/%.o : %.cpp $(DDIR)/%.d | $(ODIR) $(DDIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(ODIR) :
	mkdir $@

$(DDIR) :
	mkdir $@

all : $(NAME)

clean :
	$(RM) -r $(DDIR) $(ODIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(DEP):
-include $(DEP)