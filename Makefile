NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

MLX		= $(LIB)minilibx_opengl_20191021

FILES	=	main.c \
			utils.c \
			geometry/vector.c \
			figures/sphere.c \
			scene/camera.c \
			scene/scene.c \
			ray_tracing/trace_ray.c \
			intersections/sphere_intersection.c \
			intersections/plane_intersection.c \
			parser/parser.c \
			parser/parser_utils.c \
			parser/parser_utils2.c \
			parser/parser_stuff.c \
			parser/parser_elements.c

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD) $(MACOS_MACRO)

FLAGS = -L $(LIB)libft -lft $(MACOS_FLAGS)

MACOS_MACRO = -D MACOS

MACOS_FLAGS	= -L $(MLX) -lmlx -framework OpenGL -framework AppKit

${NAME}:	${OBJS}
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
