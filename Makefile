NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

FILES	=	main.c \
			utils.c \
			figures/plane.c \
			figures/sphere.c \
			geometry/vector.c \
			intersections/sphere_intersection.c \
			intersections/plane_intersection.c \
			intersections/cylinder_intersection.c \
			ray_tracing/trace_ray.c \
			scene/camera.c \
			parser/parser.c \
			parser/parser_utils.c \
			parser/parser_utils2.c \
			parser/parser_stuff.c \
			parser/parser_elements.c

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

FLAGS = -L $(LIB)libft -lft

MACOS_FLAGS	= -L $(LIB)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

${NAME}:	${OBJS} Makefile
			make -C $(LIB)libft
# make -C $(LIB)lib_vector
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) $(MACOS_FLAGS) -o ${NAME}

all:		${NAME}

clean:
			make clean -C $(LIB)libft
# make clean -C $(LIB)lib_vector
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)libft
# make fclean -C $(LIB)lib_vector
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
