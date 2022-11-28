# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 19:09:34 by hoomen            #+#    #+#              #
#    Updated: 2022/11/28 12:34:57 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=		brain

CXX			:=		c++
CXXFLAGS	:=		-Wall -Wextra -Werror -std=c++98

DEPFLAGS	=		-MT $@ -MMD -MP -MF $(DDIR)/$*.d

SRC			:=		main.cpp

ODIR		:=		obj
OBJ			:=		$(SRC:%.cpp=$(ODIR)/%.o)

DDIR		:=		$(ODIR)/.deps
DEP			:=		$(SRC:%.cpp=$(DDIR)/%.d)


# **************************************************************************** #
#   RULES                                                                      #
# **************************************************************************** #

.PHONY : all clean fclean re

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(ODIR)/%.o : %.cpp $(DDIR)/%.d | $(ODIR) $(DDIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(ODIR):
	mkdir $@

$(DDIR):
	mkdir $@

all : $(NAME)

clean :
	$(RM) -r $(DDIR) $(ODIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(DEP):
-include $(DEP)
