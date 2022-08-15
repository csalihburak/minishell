NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -I ./lib/readline/include -g
LDFLAGS = -L ./lib/readline/lib -lreadline
SRCS = main.c \
	dolar.c		\
	utils.c		\
	signal.c	\
	parser.c	\
	parser2.c	\
	execute.c	\
	free.c		\
	exportenv.c	\
	./Pipe/token.c			\
	./Pipe/run_pipes.c		\
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

all: $(LIB) $(PRIN) $(BUILTIN) $(NAME) $(TERM)

$(LIB):
	@make -C ./lib

$(PRIN):
	@make -C ./libft

$(BUILTIN):
	@make -C ./builtin


$(NAME): $(OBJS) $(PRIN) $(BUILTIN)
	@$(CC) ${LDFLAGS} $(OBJS) -o $(NAME) $(PRIN) $(BUILTIN)
	@echo "Minishell ready."

$(TERM):
	@bash install.sh

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
	@bash uninstall.sh
	@rm -rf ~/./minishell


re: fclean all

norm:
	norminette *.c

.PHONY: fclean re all clean