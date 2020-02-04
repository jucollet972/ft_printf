# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 21:26:15 by jucollet     #+#   ##    ##    #+#        #
#    Updated: 2019/03/27 22:26:05 by jucollet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

FLAGS= -Wall -Wextra 


INCLUDES= -I includes\
		  -I libft/includes/

SRC_PATH = sources/
SRC_NAME = ft_printf.c

BIN_PATH = bin/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
BIN = $(addprefix $(BIN_PATH),$(SRC_NAME:.c=.o))

all : $(NAME)

$(NAME): $(BIN_PATH) $(BIN)
	@make -C libft
	@ar -rc $(NAME) $(BIN) libft/bin/*
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
test : $(BINPATH) $(BIN)
	$(CC) $(FLAGS) $(INCLUDES) libft/libft.a $(SRC) -o ft_printf

re : fclean all

.PHONY: clean re all fclean
