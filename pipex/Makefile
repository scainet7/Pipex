# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 18:12:47 by snino             #+#    #+#              #
#    Updated: 2022/05/15 18:12:57 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= pipex

CC:= gcc

CFLAGS:= -Wall -Wextra -Werror

LIBFT_A:= libft.a

LIBF_DIR:= libft/

LIBFT:= $(addprefix $(LIBF_DIR), $(LIBFT_A))

SRCS:= 	pipex.c ft_check_and_error.c

HEADER:= pipex.h

OBJ := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBF_DIR)
	$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) $(LIB) -o $(NAME)

clean:
	@make -C $(LIBF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBF_DIR) fclean
	rm -rf $(NAME)

re: fclean all
