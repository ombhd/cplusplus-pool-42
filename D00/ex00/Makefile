# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 15:20:08 by obouykou          #+#    #+#              #
#    Updated: 2021/01/09 15:38:47 by obouykou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

FILE = ./megaphone.cpp

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(FILE)
	@clang++ $(FLAGS) $(FILE) -o $(NAME)
	@echo "Done !"

clean:
	@rm -rf $(NAME)
	@echo "Deleting object file Done !"
	
fclean: clean

re: fclean all