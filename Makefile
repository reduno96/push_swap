SRC=push_swap.c \
	add_nums_to_stack.c \
	ft_all_check.c\
	ft_free_utils.c \
	ft_nodes_utlis.c\
	ft_error.c \
	ft_rules_utils.c \


OBJS=${SRC:.c=.o}
CC=cc
CFLAGS= -Wall -Wextra -Werror

NAME = push_swap
LIBFT = ./libft/libft.a

RM=rm -rf
ARCH= ar -rcs

all: ${LIBFT} ${NAME}

${NAME}: ${OBJS} push_swap.h
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C libft
clean:
	${RM} ${OBJS}
	make fclean -C libft
fclean: clean
	${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re bonus