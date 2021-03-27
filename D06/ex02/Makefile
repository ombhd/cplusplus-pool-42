# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 15:20:08 by obouykou          #+#    #+#              #
#    Updated: 2021/03/27 13:13:04 by obouykou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identifier

MAIN = main.cpp

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(MAIN)
	@clang++ $(FLAGS) $(MAIN) -o $(NAME)
	@echo "\n\033[32m------- $(NAME) has been created successfully -------\033[0m\n"

clean:
	@rm -rf $(NAME)
	@echo "\n\033[36mCleaning objects Done!\033[0m\n"

fclean: clean
	@rm -rf $(NAME)

re : fclean all
