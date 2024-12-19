CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = bc_list1.c\
		bc_list2.c\
		bc_list3.c\
		divide_list_init.c\
		divide_list1.c\
		divide_list2.c\
		ft_comp_cord.c\
		ft_comp_cord2.c\
		list_move.c\
		main.c\
		ope_integrate1.c\
		ope_integrate2.c\
		ope_integrate3.c\
		operation1.c\
		solve.c\
		sort_list_u3_to_bottom1.c\
		sort_list_u3_to_bottom2.c\
		sort_list_u3_to_other.c\
		sort_list_u3.c\
		sort_list.c\
		free.c\

LIBFTPRINTF = libftprintf.a
LIBFTPRINTF_PATH = ./ft_printf

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF_PATH)/$(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF_PATH)/$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	rm -f $(OBJ)

fclean: clean
		make -C $(LIBFTPRINTF_PATH) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
