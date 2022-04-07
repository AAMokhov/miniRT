NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

MLX		= $(LIB)minilibx_opengl_20191021

FILES	=	main.c \
			utils.c \
			hook.c \
			output_for_user.c \
			geometry/vector.c \
			geometry/tuple.c \
			geometry/collations.c \
			geometry/normal.c \
			geometry/matrix.c \
			geometry/new_matrix.c \
			geometry/matrix_utils.c \
			geometry/view.c \
			ray_tracing/trace_ray.c \
			ray_tracing/ray.c \
			ray_tracing/color.c \
			ray_tracing/computations.c \
			ray_tracing/light.c \
			ray_tracing/resize.c \
			intersections/sphere_intersection.c \
			intersections/plane_intersection.c \
			intersections/cylinder_intersection.c \
			parser/parser.c \
			parser/parser_utils.c \
			parser/parser_utils2.c \
			parser/parser_stuff.c \
			parser/parser_elements.c \

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD) $(MACOS_MACRO)

FLAGS = -L $(LIB)libft -lft $(MACOS_FLAGS)

MACOS_MACRO = -D MACOS

MACOS_FLAGS	= -L $(MLX) -lmlx -framework OpenGL -framework AppKit

${NAME}:	${OBJS} ${HEAD} Makefile
			make -C $(LIB)libft
			make -C $(MLX)
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

all:		${NAME}

clean:
			make clean -C $(LIB)libft
			make clean -C $(MLX)
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)libft
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
