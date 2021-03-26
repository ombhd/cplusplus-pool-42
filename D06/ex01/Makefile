# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 15:20:08 by obouykou          #+#    #+#              #
#    Updated: 2021/03/26 18:22:28 by obouykou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serDeser

MAIN = main.cpp

HEADERS = includes/Conv.hpp

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJECT) $(FILES) $(HEADERS) $(MAIN)
	@clang++ $(FLAGS) $(MAIN) $(OBJECT) -o $(NAME)
	@echo "\n\033[32m------- convert has been created successfully -------\033[0m\n"

%.o:%.cpp					
	@clang++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECT)
	@echo "\n\033[36mCleaning objects Done!\033[0m\n"

fclean: clean
	@rm -rf $(NAME)

re : fclean all
