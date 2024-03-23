SRC=push_swap.c \
	add_nums_to_stack.c \

OBJS=${SRC:.c=.o}
CC=cc
CFLAGS= -Wall -Wextra -Werror

NAME=push.a
LIBFT=libft.a

RM=rm -rf
ARCH= ar -rcs

all: ${LIBFT} ${NAME} 
${NAME}: ${OBJS}
	${ARCH} ${NAME} ${OBJS}
${LIBFT}:
	make -C libft
clean:
	${RM} ${OBJS}
	make fclean -C libft
fclean: clean
	${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re bonus