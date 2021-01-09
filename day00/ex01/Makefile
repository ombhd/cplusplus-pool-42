# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 15:20:08 by obouykou          #+#    #+#              #
#    Updated: 2021/01/09 19:07:43 by obouykou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MyContacts

LIB = libminishell.a

MAIN = my_contacts.cpp 

FILES = my_contacts.cpp \
        sources/add_contact.cpp \
        sources/contact.cpp \
        sources/contacts.cpp \
        sources/get_command.cpp \
        sources/search_contact.cpp

HEADER = ./includes/my_contacts.h ./includes

OBJECT = $(FILES:.c=.o)

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJECT) $(HEADER) $(FILES)
	@ar -rcs $(LIB) $(OBJECT)
	@clang++ $(FLAGS) $(MAIN) $(LIB) -o $(NAME)
	@echo "\n\033[32m------- MyContacts has been created successfully -------\033[0m\n"

%.o:%.c $(HEADER)								
	@clang++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECT) $(LIB)
	@echo "\n\033[36mCleaning objects Done!\033[0m\n"

fclean: clean
	@rm -rf $(NAME)

re : fclean all
