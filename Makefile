# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 12:57:50 by madamou           #+#    #+#              #
#    Updated: 2024/07/13 01:02:39 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

C_FLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/

PARSING = $(addprefix parsing/, parsing_args.c)

SOLVER = $(addprefix solver/, solver.c backtrack.c possibilities.c possibilities2.c)

UTILS = $(addprefix utils/, print_sudoku.c)

OBJS_DIR = .objets/

SRCS = main.c $(PARSING) $(SOLVER) $(UTILS)

SRCS := $(SRCS:%=$(SRCS_DIR)/%)

LIBFT = libft.a

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

DIR_DUP = mkdir -p $(@D)

NAME = ./sudoku_solver 

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C ./libft

$(NAME) : $(OBJS)
	$(CC) $(C_FLAGS) $^ -L ./libft -lft -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(DIR_DUP)
	$(CC) $(C_FLAGS) -c  $< -o $@

bonus :  $(BONUS)

clean : 
	make clean -C ./libft
	rm -rf $(OBJS_DIR)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME) 

re : fclean all

.PHONY : all clean fclean re 
