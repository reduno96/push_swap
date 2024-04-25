SRCM=./mandatory/push_swap.c \
	./mandatory/add_nums_to_stack.c \
	./mandatory/ft_all_check.c\
	./mandatory/ft_free_utils.c \
	./mandatory/ft_nodes_utlis.c\
	./mandatory/ft_error.c \
	./mandatory/ft_swap_rules.c \
	./mandatory/ft_push_rules.c \
	./mandatory/ft_rotate_rules.c \
	./mandatory/ft_reverse_rotate_rules.c \
	./mandatory/ft_sort.c \
	./mandatory/ft_sort_utils.c \
	./mandatory/ft_range_sort.c \

CC=cc
CFLAGS= -Wall -Wextra -Werror

NAME = push_swap

OBJSM=${SRCM:.c=.o}

LIBFT = ./libft/libft.a

BONUSS = ./bonus/checker

FLBONUS = ./bonus
FLLIBFT = ./libft

RM=rm -rf
ARCH= ar -rcs

all: ${LIBFT} ${OBJSM} ${NAME}

${BONUSS}:
	@make -C ${FLBONUS}

bonus: ${BONUSS}

${NAME}: ${OBJSM} mandatory/push_swap.h
	${CC} ${CFLAGS} ${OBJSM} ${LIBFT} -o ${NAME}

%.o: %.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

${LIBFT}:
	@make -C ${FLLIBFT}



clean:
	make fclean -C ${FLLIBFT}
	make clean -C ${FLBONUS}
	${RM} ${OBJSM}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${FLBONUS}

re: fclean all

.PHONY: all clean fclean re bonus