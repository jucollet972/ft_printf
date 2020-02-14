# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 21:26:15 by jucollet     #+#   ##    ##    #+#        #
#    Updated: 2020/02/13 23:34:48 by gmonacho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=libft.a

CC=gcc

FLAGS= -Wall -Werror -Wextra

INCLUDES= -I includes/

HEADERS= includes/libft.h\
		 includes/get_next_line.h

SRC_PATH = sources/
SRC_NAME =	ft_atoi.c		ft_bzero.c			ft_count_integer.c\
		ft_count_word.c		ft_isalnum.c		ft_isalpha.c\
		ft_isascii.c		ft_isdigit.c		ft_isprint.c\
		ft_isspace.c 		ft_isword.c			ft_itoa.c\
		ft_lstaddback.c		ft_lstadd.c			ft_lstdel.c\
		ft_lstdelone.c		ft_lstiter.c		ft_lstmap.c\
		ft_lstnew.c			ft_memalloc.c		ft_memccpy.c\
		ft_memchr.c			ft_memcmp.c			ft_memcpy.c\
		ft_memdel.c			ft_memmove.c		ft_memset.c\
		ft_putchar.c		ft_putchar_fd.c		ft_putendl.c\
		ft_putendl_fd.c		ft_putnbr.c			ft_putnbr_fd.c\
		ft_putnendl.c		ft_putstr.c			ft_putstr_fd.c\
		ft_strcat.c			ft_strchr.c			ft_strchr_index.c\
		ft_strclr.c			ft_strcmp.c			ft_strcpy.c\
		ft_strdel.c			ft_strdup.c			ft_strequ.c\
		ft_striter.c		ft_striteri.c		ft_strjoin.c\
		ft_strlcat.c		ft_strlen.c			ft_strmap.c\
		ft_strmapi.c		ft_strncat.c		ft_strncmp.c\
		ft_strncpy.c		ft_strnequ.c		ft_strnew.c\
		ft_strnstr.c		ft_strrchr.c		ft_strsplit.c\
		ft_strstr.c			ft_strsub.c			ft_strtrim.c\
		ft_tolower.c		ft_toupper.c		ft_trimspace.c\
		ft_putnendl_fd.c	ft_strrchr_index.c 	ft_swap.c\
		ft_strjoinfree.c    get_next_line.c		ft_count_long_long.c\
		ft_strrev.c			ft_base_char.c		ft_itoa_base.c\
		ft_count_ull.c		ft_itoa_ll.c		ft_itoa_ull.c

BIN_PATH = bin/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
BIN = $(addprefix $(BIN_PATH),$(SRC_NAME:.c=.o))

all : $(NAME)

$(NAME): $(BIN_PATH) $(BIN) $(HEADERS)
	@ar -rc $(NAME) $(BIN)
	@ranlib $(NAME)
	@echo "\033[32m[Your Library is ready]\033[0m"

$(BIN_PATH)%.o : $(SRC_PATH)%.c
		@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $^
$(BIN_PATH):
	@mkdir -p $(BIN_PATH)
clean :
		@rm -rf $(BIN_PATH)
		@echo "\033[31m[File .o deleted]\033[0m"

fclean : clean
		@rm -rf $(NAME)
		@echo "\033[31m[Libft.a deleted]\033[0m"

re : fclean all

shape :
	@echo "\033[32m.____    .___________________________________\033[0m"
	@echo "\033[32m|    |   |   \______   \_   _____/\__    ___/\033[0m"
	@echo "\033[32m|    |   |   ||    |  _/|    __)    |    |\033[0m"
	@echo "\033[32m|    |___|   ||    |   \|     \     |    |\033[0m"
	@echo "\033[32m|_______ \___||______  /\___  /     |____|\033[0m"
	@echo "\033[32m        \/           \/     \/\033[0m"

.PHONY: clean re all fclean
