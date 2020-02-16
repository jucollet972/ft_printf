# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 21:26:15 by jucollet     #+#   ##    ##    #+#        #
#    Updated: 2020/02/14 17:29:40 by gmonacho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME= libftprintf.a

CC= gcc

FLAGS= -Wall -Wextra -Werror


INCLUDES= -I includes\
		  -I libft/includes/

HEADERS= includes/ft_printf.h\
		 libft/includes/libft.h

SRC_PATH = sources/

SRC_NAME = ft_printf.c 				ft_construct_str.c	ft_accurate_string.c\
	       ft_get_less_option_str.c ft_format_flags.c 	ft_get_format.c\
		   ft_dec.c					ft_unsigned.c		ft_format_string.c\
		   ft_width.c				extended_params.c	extended_params_bis.c



BIN_PATH = bin/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
BIN = $(addprefix $(BIN_PATH),$(SRC_NAME:.c=.o))

all : $(NAME)

$(NAME): $(BIN_PATH) $(BIN) $(HEADERS)
	@make -C libft
	@ar -rc $(NAME) $(BIN) libft/bin/*.o
	@ranlib $(NAME)
	@echo "\033[32m[Your Library is ready]\033[0m"

$(BIN_PATH)%.o : $(SRC_PATH)%.c
		@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $^
$(BIN_PATH):
	@mkdir -p $(BIN_PATH)
clean :
		@make clean -C libft
		@rm -rf $(BIN_PATH)
		@echo "\033[31m[File .o deleted]\033[0m"

fclean : clean
		@make fclean -C libft
		@rm -rf $(NAME)
		@echo "\033[31m[Libft.a deleted]\033[0m"

test : $(BINPATH) $(BIN) $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) libft/libft.a $(NAME) -o ft_printf

re : fclean all

.PHONY: clean re all fclean
