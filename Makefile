# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdedieu <amdedieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 22:38:41 by amdedieu          #+#    #+#              #
#    Updated: 2021/01/20 03:57:34 by amdedieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I$(INC_PATH)

SRC_PATH = ./srcs
INC_PATH = ./include
OBJ_PATH = ./obj

INC_NAME = ft_printf.h 

SRC_NAME =	ft_parse.c 		\
			ft_prec.c 		\
			ft_print_2.c 	\
			ft_print.c 		\
			ft_printf.c 	\
			ft_utils.c 		\
			ft_width.c 		\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIBFT_OBJS = ./libft/*.o
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJS)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf ./obj $(NAME)

re: fclean all

test: $(NAME)
	gcc srcs/ft_printf.c libft/libft.a libftprintf.a main.c -fsanitize=address -g3

norme:
	@norminette $(SRC) $(LIB) $(INC)

.PHONY: all clean fclean re norm
