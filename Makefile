NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

FILES	=	main.c \

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

FLAGS = -L $(LIB)libft -lft

MACOS_FLAGS	= -L $(LIB)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

${NAME}:	${OBJS}
			make -C $(LIB)libft
# make -C $(LIB)lib_vector
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

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
