# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:24:38 by hoomen            #+#    #+#              #
#    Updated: 2022/11/28 12:42:36 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= zombies

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98


DEPFLAGS	 = -MT $@ -MMD -MP -MF $(DDIR)/$*.d

SRCS		:= main.cpp Zombie.cpp zombieHorde.cpp

ODIR		:= obj
OBJ			:= $(SRCS:%.cpp=$(ODIR)/%.o)

DDIR		:= $(ODIR)/.deps
DEP			:= $(SRCS:%.cpp=$(DDIR)/%.d)

# **************************************************************************** #
#   RULES                                                                      #
# **************************************************************************** #

.PHONY: all clean fclean re run

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(ODIR)/%.o: %.cpp $(DDIR)/%.d | $(ODIR) $(DDIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(ODIR):
	mkdir $@

$(DDIR):
	mkdir $@

all: $(NAME)

clean:
	$(RM) -r $(DDIR) $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

$(DEP):
-include $(DEP)