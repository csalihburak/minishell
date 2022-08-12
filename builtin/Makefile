NAME = builtin.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
ARFLAGS = -rcs
SRCS = cd.c		\
	env.c 		\
	ft_builtin.c	\
	echo.c			\
	pwd.c			\
	exit.c			\
	export.c		\
	exportutils.c	\
	exportutils2.c	\
#	unset.c			\

PRIN = ../libft/libft.a

OBJS= $(SRCS:.c=.o)
all: ${NAME}


$(NAME): $(OBJS)
	@ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}
	@echo [$(OBJS)]$(B)

fclean: clean
	@rm -rf ${NAME}
	@echo [$(NAME)]$(B)

re: fclean all

.PHONY: fclean re all clean