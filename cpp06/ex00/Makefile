# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 23:28:55 by hoomen            #+#    #+#              #
#    Updated: 2023/01/10 21:48:10 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	conversion

CXX			:=	c++
CXXFLAGS	:=	-Wall -Werror -Wextra #-std=c++98

DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DDIR)/$*.d

SRC			=	Conversion.cpp main.cpp IntConverter.cpp Tools.cpp

ODIR		=	obj
OBJ			=	$(SRC:%.cpp=$(ODIR)/%.o)

DDIR		=	$(ODIR)/.deps
DEP			=	$(SRC:%.cpp=$(DDIR)/%.d)


.PHONY : all clean fclean re run

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

run : $(NAME)
	./$(NAME)

$(DEP):
-include $(DEP)

