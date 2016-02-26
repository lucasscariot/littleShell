# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscariot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 09:44:59 by lscariot          #+#    #+#              #
#    Updated: 2016/02/26 21:30:23 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

CC		= clang

S_DIR	=

O_DIR	=

I_DIR	=

FLAGS	= -Wall -Wextra -Werror $(I_DIR) $(LIBS_DIR)

FILES	= main.c \

LIBS_F	= ft

SRC		= $(addprefix $(S_DIR),$(FILES))

OBJS	= $(addprefix $(O_DIR),$(FILES:.c=.o))

LIBS	= $(addprefix -L. -l,$(LIBS_F))

RM		= rm -f

all: 		$(NAME)

$(NAME): 	$(OBJS)
	@echo ""
	@make -C libft
	@$(CC) $(FLAGS) $(LIBS) $^ -o $@
	@echo "\033[32m$(NAME) created.\033[0m"

$(O_DIR)%.o:		$(S_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[33m.\033[0m\c"

clean:
	@$(RM) $(OBJS)
	@make -C libft clean

fclean: 	clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo "\033[31m$(NAME) cleaned.\033[0m"

re:			fclean all
	@make clean

.PHONY: re clean fclean all
