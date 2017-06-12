NAME = libft.a

SRCS= d_strlen \
	dstr_strlen \
	ft_nbrlen \
	ft_str_toupper \
	ft_str_tolower \
	ft_atoi \
	ft_bzero \
	ft_memchr \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_itoa \
	ft_realloc \
	ft_memset \
	ft_putchar \
	ft_putchar_fd \
	ft_putendl \
	ft_putendl_fd \
	ft_putnbr \
	ft_putnbr_fd \
	ft_putstr \
	ft_putstr_fd \
	ft_str_isnum \
	ft_strchr \
	ft_strcmp \
	ft_strcpy \
	ft_strdup \
	ft_strndup \
	ft_strnew \
	ft_strequ \
	ft_strlen \
	ft_strncmp \
	ft_strncpy \
	ft_strnequ \
	ft_strnstr \
	ft_strrchr \
	ft_strsplit \
	ft_strstr \
	ft_strtrim \
	ft_tolower \
	ft_toupper \
	w_dcount \
	ft_strclr \
	ft_strdel \
	ft_memdel \
	ft_memalloc \
	ft_striter \
	ft_strsub \
	ft_strjoin \
	ft_memcpy \
	ft_memccpy \
	ft_memmove \
	ft_strcat \
	ft_strncat \
	ft_strlcat \
	ft_striteri \
	ft_strmap \
	ft_strmapi \
	ft_memcmp \
	ft_lstnew \
	ft_lstdelone \
	ft_lstdel \
	ft_lstadd \
	ft_lstiter \
	ft_lstmap \
	ft_btree_create_node \
	ft_btree_apply_prefix \
	ft_btree_apply_infix \
	ft_is_prime \
	print_bits \
	print_hex \
	ft_sqrt \
	ft_append_str \
	ft_prepend_str \
	new_int_table \
	delete_int_table \
	clone_int_array \
	copy_int_array \
	integer_quicksort \
	swap_integers \

CFILES= $(addsuffix .c, $(SRCS))

OFILES= $(addsuffix .o, $(SRCS))

HEADER= -I ../libft

CFLAGS= -Wall -Wextra -Werror

.PHONY: make all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

$(OFILES): $(CFILES)
	gcc $(HEADER) $(CFLAGS) $(CFILES) -c

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

