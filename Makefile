NAME = exec

SRC_DIR = src
OBJ_DIR = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c

OBJ = $(SRCS:.c=.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJ))
	$(CC) $(CFLAGS) -o $(NAME) $(addprefix $(OBJ_DIR)/, $(OBJ))
	@echo "✅ $(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

re: fclean all