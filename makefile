NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SOURCE =	main.c \
			./utils/tools.c ./opps/push_algo.c \

DPNCY =		./inc/ft_printf/libftprintf.a \
			./inc/ft_printf/libft/libft.a \

all: $(NAME)

$(NAME): $(SOURCE) linked_obj
	gcc $(CFLAGS) -o $(NAME) $(SOURCE) $(DPNCY)

linked_obj:
	make -C ./inc/ft_printf
	make -C ./inc/ft_printf/libft

clean: $(NAME)
	rm -rf $(NAME)
	rm -rf ./inc/ft_printf/libftprintf.a
	rm -rf ./inc/ft_printf/libft/libft.a

fclean:	clean
	rm -rf ./inc/ft_printf/*.o
	rm -rf ./inc/ft_printf/libft/*.o

re: fclean all
