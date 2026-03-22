NAME = exec

SRC_DIR = src
OBJ_DIR = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c resolve_resta_um.c
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "✅ $(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f saida.txt

re: fclean all

run: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re val