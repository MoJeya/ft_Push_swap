NAME =		checker

CFLAGS =	-Wall -Wextra -Werror

SOURCE =	main.c \
			./utils/main_tools.c ./opps/push_algo.c ./opps/swap_algo.c ./opps/rot_algo.c \
			./utils/sorting_tools.c ./utils/helper_tools.c \

DPNCY =		./inc/ft_printf/libftprintf.a \
			./inc/ft_printf/libft/libft.a \

all:	$(NAME)

$(NAME): linked_obj
	gcc $(CFLAGS) -o $(NAME) $(SOURCE) $(DPNCY)

linked_obj:
	make -C ./inc/ft_printf
	make -C ./inc/ft_printf/libft

clean:
	rm -f ./inc/ft_printf/*.o ./inc/ft_printf/libft/*.o

fclean:	clean
	rm -f $(NAME) ./inc/ft_printf/libftprintf.a ./inc/ft_printf/libft/libft.a

re: fclean all
