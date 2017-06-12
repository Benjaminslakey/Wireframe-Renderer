NAME= FdF

LIBS= $(MLX_LIB) $(GFX_LIB) $(FT_LIB) $(PF_LIB)

MLX_LIB= libmlx.a

GFX_LIB= libgfx.a

FT_LIB= libft.a

SRCS= sources/fdf.c \
	  sources/parse.c \
	  sources/events.c \
	  sources/error.c \
	  gnl/get_next_line.c \

CFILES= $(addprefix .x, $(SRCS))

OBJS= $(addsuffix .o, $(SRCS))

HEADER=

CFLAGS= -Wall -Wextra -Werror

LDFLAGS= -L./ -lmx

FRAMEWORK= -framework OpenGL -framework AppKit

.PHONY: libraries test all clean fclean re

all: $(NAME)

$(NAME): $(LIBS)
	gcc $(CFLAGS) -o FdF $(SRCS) $(LDFLAGS) $(FRAMEWORK) $(LIBS) -O3

libraries: $(MLX_LIB) $(GFX_LIB) $(FT_LIB)

$(FT_LIB):
	make -C libft
	mv libft/$(FT_LIB) .

$(MLX_LIB):
	make -C mlx
	mv mlx/$(MLX_LIB) .

$(GFX_LIB):
	make -C libgfx
	mv libgfx/$(GFX_LIB) .

clean:
	make clean -C libgfx
	make clean -C mlx
	make clean -C libft
	rm -rf $(LIBS)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
