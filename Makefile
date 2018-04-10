NAME = libftprintf.a

FILE_C = ft_main.c ft_print_conv.c parsing.c processing_s.c \
		left_right.c processing_d.c check.c libft/ft_atoi.c \
		libft/ft_putchar.c libft/ft_putstr.c \
		libft/ft_strchr.c libft/ft_strdel.c \
		libft/ft_strlen.c libft/ft_strnew.c \
		libft/ft_strsub.c libft/ft_memalloc.c \
		libft/ft_memset.c ft_itoa_max.c libft/ft_strdup.c

FILE_O = $(FILE_C:.c=.o)

GCC = gcc -Wall -Wextra -Werror -c -o

all: $(NAME)

$(NAME): $(FILE_O)
	ar rc $(NAME) $(FILE_O)

%.o: %.c
	$(GCC) $@ $<

clean:
	rm -f $(FILE_O)

fclean: clean
	rm -f $(NAME)

re: fclean all