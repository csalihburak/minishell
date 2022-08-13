NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -I ./lib/readline/include
LDFLAGS = -L ./lib/readline/lib -lreadline
SRCS = main.c \
	utils.c		\
	signal.c	\
	ft_parser.c	\
	ft_parser2.c	\
	ft_execute.c	\
	ft_free.c		\
	./Pipe/token.c			\
	./Pipe/create_pipes.c	\
	./Pipe/run_pipes.c		\
	./Pipe/pipe_builtin.c			\
	./file_operators/op_handling.c	\
	./file_operators/op_utils.c		\
	./file_operators/operator.c		\
	./file_operators/run_op_pipes.c		\
	./file_operators/setup_op_pipe.c		\

OBJS= $(SRCS:.c=.o)
PRIN = ./libft/libft.a
RED = '\033[0;31m'
BUILTIN = ./builtin/builtin.a
LIB	= ./lib/.minishell

all: $(LIB) $(PRIN) $(BUILTIN) $(NAME)

$(LIB):
	@make -C ./lib

$(PRIN):
	@make -C ./libft

$(BUILTIN):
	@make -C ./builtin


$(NAME): $(OBJS) $(PRIN) $(BUILTIN)
	@$(CC) ${LDFLAGS} $(OBJS) -o $(NAME) $(PRIN) $(BUILTIN)
	@echo "Minishell ready."

%.o: %.c
	@echo $(R)Compiling: [$<]
	@${CC} $(CFLAGS) -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}
	@make clean -C ./builtin
#	@make clean -C ./libft
	@echo [$(OBJS)]$(B)

fclean: clean
	@rm -rf ${NAME}
	@make fclean -C ./builtin
	@make fclean -C ./libft
#	@rm -rf ./libft/libft.a
	@echo [$(NAME)]$(B)

re: fclean all

norm:
	norminette *.c

.PHONY: fclean re all clean