NAME		= push_swap

CC			= gcc
INC			= ./
CFLAGS		= -g -Wall -Wextra -Werror -I./
RM			= rm -f
OBJ_PATH 	= ./obj/

SRC		= push_swap.c \
	  error_handling.c \
	  utils.c \
	  ./operations/swap.c \
	  ./operations/push.c \
	  ./operations/rotate.c \
	  ./operations/reverse_rotate.c \
	  ./operations/cases_3to5.c \
	  ./operations/case_x.c \
	  ./stack/stack_handling_1.c \
	  ./stack/stack_handling_2.c \
	  ./stack/a_to_b.c \
	  ./stack/b_to_a.c \

OBJ	= $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_FILES) $(NAME)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -g $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_FILES): $(SRC)	

$(NAME):	$(OBJ_FILES)
	$(CC) -g $(CFLAGS) -I $(INC) $(OBJ_FILES) -o $(NAME)

clean:
	@$(RM) $(OBJ) $(OBJ_FILES)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re