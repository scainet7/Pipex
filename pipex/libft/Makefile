	# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 16:23:18 by snino             #+#    #+#              #
#    Updated: 2022/05/29 13:37:23 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := libft.a

CC := gcc

CFLAGS := -Wall -Werror -Wextra

SRC	:=	ft_isalnum.c			ft_isprint.c		ft_memcmp.c\
		ft_putchar_fd.c			ft_split.c			ft_strlcat.c\
		ft_strncmp.c			ft_substr.c 		ft_atoi.c\
		ft_isalpha.c			ft_itoa.c			ft_memcpy.c\
		ft_putendl_fd.c			ft_strchr.c			ft_strlcpy.c\
		ft_strnstr.c			ft_tolower.c		ft_bzero.c\
		ft_isascii.c			ft_striteri.c		ft_memmove.c\
		ft_putnbr_fd.c			ft_strdup.c			ft_strlen.c\
		ft_strrchr.c			ft_toupper.c		ft_calloc.c\
		ft_isdigit.c			ft_memchr.c			ft_memset.c\
		ft_putstr_fd.c  		ft_strjoin.c		ft_strstr.c\
		ft_strmapi.c			ft_strtrim.c		ft_free_split.c\
		ft_strcpy.c

BONUS_SRC	:=	ft_lstnew.c				ft_lstadd_front.c	ft_lstsize.c\
			 	ft_lstlast.c			ft_lstadd_back.c	ft_lstdelone.c\
			 	ft_lstclear.c			ft_lstiter.c		ft_lstmap.c

OBJ	:=	$(SRC:%.c=%.o)

BONUS_OBJ	:=	$(BONUS_SRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			rm -f $(NAME)
			ar -rcs $(NAME) $(OBJ)

bonus:
		$(CC) $(CFLAGS) -c $(BONUS_SRC)
		ar -rcs $(NAME) $(BONUS_OBJ)

clean:
		rm -rf ./a.out
		rm -rf *.o

fclean: clean
		rm -rf $(NAME)

re:     fclean all

.PHONY	:	all claen fclean re bonus
