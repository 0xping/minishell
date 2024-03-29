# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
END = \033[0m

#Texture
BOLD = \033[1m

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
LDFLAGS = -lreadline #-L$(shell brew --prefix readline)/lib

# Target name
NAME = minishell
LIBFT = ./lib/libft/libft.a


# Source files
LIB = $(LIBFT)  # $(wildcard ./lib/**/*.c)
SRC = $(wildcard ./src/*.c ./src/**/*.c)
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT) : $(wildcard ./lib/libft/*.c)
	@echo "$(GREEN)\n⌛ Compiling libft ...$(END)"
	@make -sC ./lib/libft
	@make -sC ./lib/libft bonus
	@make -sC ./lib/libft clean

$(NAME): $(SRC) $(LIB)
	@echo "$(GREEN)⌛ Compiling $(NAME) ...$(END)"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully\n$(END)"
	@echo "To start your shell, use: $(YELLOW)$(BOLD)make start$(END)"


start :
	clear
	@./$(NAME)

clean :
	@echo "$(RED)\n⌛ removing object files ...$(END)"
	@rm -rf $(OBJ)
	@make -sC  ./lib/libft clean
	@echo "$(RED)🗑️  objects removed \n$(END)"

fclean : clean
	@echo "$(RED)\n⌛ removing $(NAME) ...$(END)"
	@rm -rf $(NAME)
	@make -sC  ./lib/libft fclean
	@echo "$(RED)🗑️  $(NAME) removed \n$(END)"

re : fclean all

.PHONY: all clean fclean re
