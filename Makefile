# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 16:38:15 by dheredat          #+#    #+#              #
#    Updated: 2019/12/23 16:38:42 by dheredat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FDF_H = $(INC_DIR)/fdf.h \
		$(INC_DIR)/keys.h

LIBFT_DIR	=	./ft_printf
SRC_DIR		=	./src
INC_DIR		=	./inc
OBJ_DIR		=	./obj

FLAGS	=	-Wall -Wextra -Werror

MLXFLAGS = 	-I /usr/local/include \
			-L /usr/local/lib -lmlx \
			-framework OpenGL \
			-framework AppKit

SRC	=	check_map.c check_n_get_map.c count_map.check_map \
		get_colour.c key_event.c main.c paint.c test.c

SRC_T		=	$(addprefix $(SRC_DIR)/,$(SRC))

OBJS			=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LIBFT			=	$(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C ft_printf

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(FDF_H)
	@echo "\033[35mCompiling ./push_swap\033[0m"
	@gcc $(LIBFT) $F $(OBJS) $(PUSH_SWAP_OBJ) -o $(NAME_PS)
	@echo "\033[35mCompiling ./checker\033[0m"
	@gcc $(LIBFT) $F $(OBJS) $(CHECKER_OBJ) -o $(NAME_CH)
	@echo "\033[1;32mProject was built\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ft_printf clean

fclean: clean
	@rm -rf $(NAME_PS)
	@rm -rf $(NAME_CH)
	@make -C ft_printf fclean
	@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all