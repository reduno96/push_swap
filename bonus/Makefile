SRCB=checker_bonus.c \
	add_nums_to_stack_bonus.c \
	ft_all_check_bonus.c\
	ft_nodes_utlis_bonus.c\
	ft_error_bonus.c \
	ft_swap_rules_bonus.c \
	ft_push_rules_bonus.c \
	ft_rotate_rules_bonus.c \
	ft_reverse_rotate_rules_bonus.c \
	ft_sort_bonus.c \
	ft_sort_utils_bonus.c \
	ft_range_sort_bonus.c \
	../get_next_line/get_next_line.c \
	../get_next_line/get_next_line_utils.c \

CC=cc
CFLAGS= -Wall -Wextra -Werror
CHECKER = ../checker
OBJSB=${SRCB:.c=.o}

LIBFT = ../libft/libft.a

FLLIBFT = ../libft
RM=rm -rf
ARCH= ar -rcs

all: ${LIBFT} ${OBJSB} ${CHECKER}

${CHECKER}: ${OBJSB} ./push_swap_bonus.h
	${CC} ${CFLAGS} ${OBJSB} ${LIBFT} -o ${CHECKER}

%.o: %.c bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

${LIBFT}:
	@make -C ${FLLIBFT}

clean:
	${RM} ${OBJSB}

fclean:
	${RM} ${CHECKER}

re: fclean all

.PHONY: all clean fclean re bonus