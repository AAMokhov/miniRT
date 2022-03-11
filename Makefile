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

# MACOS_MACRO = -D MACOS

# LINUX_MACRO = -D LINUX

MACOS_FLAGS	= -L $(LIB)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

# LINUX_FLAGS = -L $(LIB)minilibx-linux -lmlx -lm -lX11 -lXext -lpthread

# UNAME := $(shell uname)

# ifeq ($(UNAME),Darwin)
# 	NUM_THREADS = $(shell sysctl -n hw.ncpu)
# 	CFLAGS += $(MACOS_MACRO)
# 	FLAGS += $(MACOS_FLAGS)
# endif
# ifeq ($(UNAME),Linux)
# 	NUM_THREADS = $(shell nproc --all)
# 	CFLAGS += $(LINUX_MACRO)
# 	FLAGS += $(LINUX_FLAGS)
# endif

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
