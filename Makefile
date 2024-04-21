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

SRCB=./bonus/checker_bonus.c \
	./bonus/add_nums_to_stack_bonus.c \
	./bonus/ft_all_check_bonus.c\
	./bonus/ft_free_utils_bonus.c \
	./bonus/ft_nodes_utlis_bonus.c\
	./bonus/ft_error_bonus.c \
	./bonus/ft_swap_rules_bonus.c \
	./bonus/ft_push_rules_bonus.c \
	./bonus/ft_rotate_rules_bonus.c \
	./bonus/ft_reverse_rotate_rules_bonus.c \
	./bonus/ft_sort_bonus.c \
	./bonus/ft_sort_utils_bonus.c \
	./bonus/ft_range_sort_bonus.c \
	./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c \

CC=cc
CFLAGS= -Wall -Wextra -Werror

NAME = push_swap
CHECKER = checker

OBJSM=${SRCM:.c=.o}
OBJSB=${SRCB:.c=.o}


LIBFT = ./libft/libft.a

RM=rm -rf
ARCH= ar -rcs

all: ${LIBFT} ${OBJSM} ${NAME}

${NAME}: ${OBJSM} mandatory/push_swap.h
	${CC} ${CFLAGS} ${OBJSM} ${LIBFT} -o ${NAME}

${CHECKER}: ${OBJSB} bonus/push_swap_bonus.h
	${CC} ${CFLAGS} ${OBJSB} ${LIBFT} -o ${CHECKER}

${LIBFT}:
	@make -C libft

bonus: ${LIBFT} ${OBJSB} ${CHECKER}

clean:
	make fclean -C libft
	${RM} ${OBJSM} ${OBJSB}

fclean: clean
	${RM} ${NAME} ${CHECKER} ${OBJSM} ${OBJSB}

re: fclean all

.PHONY: all clean fclean re bonus