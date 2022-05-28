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

B_NAME:= pipex_bonus

CC:= gcc

CFLAGS:= -Wall -Wextra -Werror

LIBFT_A:= libft.a

LIBF_DIR:= libft/


LIBFT:= $(addprefix $(LIBF_DIR), $(LIBFT_A))

SRCS:= 	pipex.c\
		ft_check_and_error_and_pars.c

BONUS_SRCS:= pipex_bonus.c\
			ft_parsing_bonus.c\
			ft_parrent_proc_bonus.c

OBJ := $(SRCS:%.c=%.o)

BONUS_OBJ:= $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJ)
		@make -C $(LIBF_DIR)
		$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) $(LIB) -o $(NAME)

$(B_NAME) : $(BONUS_OBJ)
		@make -C $(LIBF_DIR)
		$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(LIB) -o $(B_NAME)

clean:
	@make -C $(LIBF_DIR) clean
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	@make -C $(LIBF_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(B_NAME)

re: fclean all

.PHONY	:	all claen fclean re bonus