#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huweber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 16:26:44 by huweber           #+#    #+#              #
#    Updated: 2017/04/20 18:36:12 by huweber          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
	ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
	ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
	ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c\
	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
	ft_lstmap.c ft_btree_apply_infix.c ft_btree_apply_prefix.c\
	ft_btree_apply_suffix.c ft_btree_create_node.c ft_btree_level_count.c\
	ft_btree_search_item.c ft_max.c ft_swap.c ft_realloc.c get_next_line.c\
	ft_abs.c ft_strmerge.c ft_atof.c ft_htoi.c

SRCS_PRINTF = ft_printf/check_conv.c ft_printf/handler_hexa.c\
				ft_printf/handler_int.c ft_printf/handler_char_str.c\
				ft_printf/handler_long.c ft_printf/handler_octal.c\
				ft_printf/handler_w_str.c ft_printf/handler_wchar.c\
				ft_printf/init_env.c ft_printf/ft_printf.c\
				ft_printf/parse_buffer.c ft_printf/put_precision_padding.c\
				ft_printf/parse_handler.c ft_printf/misc.c

CC = gcc

OBJS = $(SRCS:.c=.o) $(SRCS_PRINTF:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I ./includes/ -I./

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
