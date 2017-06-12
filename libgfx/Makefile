NAME= libgfx.a

SRCS= draw \
	  projections \
	  transformations \
	  matrix_math \
	  point_vector \
	  points \
	  view \
	  img_data \

CFILES= $(addprefix sources/, $(addsuffix .c, $(SRCS)))

OFILES= $(addsuffix .o, $(SRCS))

HEADER= -I includes/libgfx

CFLAGS= -Wall -Wextra -Werror

.PHONY: all clean fclean re

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
