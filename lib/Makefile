LIB				= ./.minishell

all : $(LIB)

clean :
	@rm -rf ./readline ./.minishell

fclean : 
	@rm-rf ./readline ./.minishell

re : fclean all


$(LIB):
	@curl -O http://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
	@gunzip -c readline-8.2-rc1.tar.gz | tar xopf -
	@mv readline-8.2-rc1 readline
	/bin/sh -c "cd readline && sh ./configure --prefix=$(shell echo $(PWD))/lib/readline"
	make install -C readline
	@rm -f readline-8.2-rc1.tar.gz
	@mkdir ./.minishell

.PHONY: all  fclean re