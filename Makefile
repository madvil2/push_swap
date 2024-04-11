NAME :=				push_swap

SRC_PATH :=			srcs/
INC_PATH :=			includes/
OBJ_PATH :=			.obj/
LIB_PATH :=			libft/

CC :=				cc
CFLAGS :=			-g -Wall -Werror -Wextra
IFLAGS :=			-I $(INC_PATH) -I $(LIB_PATH)
LFLAGS :=			-L $(LIB_PATH) -lft

HFILES :=			push_swap
FILES :=			main\
					operations_push\
					operations_reverse_rotate\
					operations_rotate\
					operations_swap\
					stack_init\
					utils
LIB :=				$(LIB_PATH)libft.a

HDRS :=				$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=				$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=				$(SRCS:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIB):
	if [ ! -d "$(LIB_PATH)" ]; then \
		git clone git@github.com:madvil2/libft.git $(LIB_PATH); \
	fi
	$(MAKE) -C $(dir $@) $(notdir $@)

$(OBJS): $(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDRS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)

fclean: mfclean
	rm -rf $(LIB_PATH)

re: fclean all

mclean:
	rm -f $(OBJS)

mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)

mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
