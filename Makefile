#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huweber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 15:40:22 by huweber           #+#    #+#              #
#    Updated: 2017/10/25 15:40:23 by huweber          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
SRCS_DIR = srcs
INCS_DIR = -I includes
LIBFT_INCS_DIR = -I libft/includes
OBJS_DIR = objs
LIBFT_DIR = libft
LIBFT_LINKER = -lft -L ./libft/
NAME = ft_ls
RM = rm -rf
SRCS = 	$(SRCS_DIR)/core.c \
		$(SRCS_DIR)/handle_errors.c \
		$(SRCS_DIR)/handle_acl.c \
		$(SRCS_DIR)/path_concat.c \
		$(SRCS_DIR)/file_list.c \
		$(SRCS_DIR)/args_to_list.c \
		$(SRCS_DIR)/set_env.c \
		$(SRCS_DIR)/print_files.c \
		$(SRCS_DIR)/print_long.c \
		$(SRCS_DIR)/parse.c \
		$(SRCS_DIR)/merge_sort.c \
		$(SRCS_DIR)/swap_files.c
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@printf '\033[32m[✔] %s\n\033[0m' "-------Compiling Sources-------"
	@make -s -j -C $(LIBFT_DIR)
	@printf '\033[32m[✔] %s\n\033[0m' "-------Compiling Library-------"
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT_LINKER)
	@printf '\033[32m[✔] %s\n\033[0m' "-------------Done--------------"

objs/%.o: srcs/%.c
	@if [ ! -d objs ]; then mkdir -p $(dir $@); fi
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@$(CC) $(CC_FLAGS) -c $(INCS_DIR) $(LIBFT_INCS_DIR) $< -o $@
	@printf '\033[0m[✔] %s\n\033[0m' "$<"

clean:
	@printf '\033[31m[✔] %s\n\033[0m' "-------Cleaning Objects--------"
	@make clean -s -C $(LIBFT_DIR)
	@printf '\033[31m[✔] %s\n\033[0m' "------Cleaning Lib Objects-----"
	@$(RM) $(OBJS)

fclean: clean
	@printf '\033[31m[✔] %s\n\033[0m' "-------Cleaning Library--------"
	@make fclean -s -C $(LIBFT_DIR)
	@printf '\033[31m[✔] %s\n\033[0m' "---------Cleaning Bin----------"
	@$(RM) $(NAME)
	@$(RM) $(OBJS_DIR)

re: fclean all
