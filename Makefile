NAME = push_swap
NAME_C = checker
NAME_P = push_swap

FLAGS = -Wall -Wextra -Werror
LIB_DIR = libft/
HEADER_DIR = include/

SRC_C =			checker.c \
				operations_1.c \
				operations_2.c \
				stack_initialisation.c \
				utils.c

SRC_DIR_C =		src/checker/

SRC_P =			ft_find.c \
				operations_1.c \
				operations_2.c \
				push_swap.c \
				sort_1.c \
				sort_2.c \
				find_mid.c \
				stack_initialisation.c \
				utils.c \
				utils_2.c \
				is_prev.c

SRC_DIR_P =		src/push_swap/


GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

OBJ_C = $(patsubst %.c,%.o,$(SRC_C))
OBJ_P = $(patsubst %.c,%.o,$(SRC_P))

OBJ_DIR = obj/
OBJ_DIR_C = $(OBJ_DIR)checker_o/
OBJ_DIR_P = obj/push_swap_o/
OBJS_C = $(addprefix $(OBJ_DIR_C),$(OBJ_C))
OBJS_P = $(addprefix $(OBJ_DIR_P),$(OBJ_P))
OBJS = $(addprefix $(OBJ_DIR_C),$(OBJ_C)) $(addprefix $(OBJ_DIR_P),$(OBJ_P))

all: $(NAME)

$(OBJ_DIR_C)%.o: $(SRC_DIR_C)%.c
	@mkdir -p $(OBJ_DIR_C)
	@gcc -c $< -o $@ -I $(HEADER_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR_C) was created$(RESET)"

$(OBJ_DIR_P)%.o: $(SRC_DIR_P)%.c
	@mkdir -p $(OBJ_DIR_P)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR_P) was created$(RESET)"

$(NAME):  $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(FLAGS) $(OBJS_C) -L. libft/libft.a -o $(NAME_C)
	@$(CC) $(FLAGS) $(OBJS_P) -L. libft/libft.a -o $(NAME_P)

clean:
	@make clean -C $(LIB_DIR)
	@rm -Rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@echo "$(NAME): $(RED)libft.a was deleted$(RESET)"
	@rm -f $(NAME_C) $(NAME_P)
	@echo "$(NAME): $(RED)$(NAME_P) and $(RED)$(NAME_C) were deleted$(RESET)"

re: fclean all
.PHONY: all clean fclean re