# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 16:05:34 by obouykou          #+#    #+#              #
#    Updated: 2021/02/01 17:50:50 by obouykou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MySed

MAIN = my_sed.cpp

FILES = 

HEADERS = 

OBJECT = $(FILES:.cpp=.o)

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJECT) $(FILES) $(HEADERS) $(MAIN)
	@clang++ $(FLAGS) $(MAIN) $(OBJECT) -o $(NAME)
	@echo "\n\033[32m------- MySed has been created successfully -------\033[0m\n"

%.o:%.cpp					
	@clang++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECT)
	@echo "\n\033[36mCleaning objects Done!\033[0m\n"

fclean: clean
	@rm -rf $(NAME)

re:	fclean all