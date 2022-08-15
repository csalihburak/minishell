#!/bin/bash
shell_f=$(echo -n "$SHELL" | awk -F / '{print $3}')
shell_f="${HOME}/.${shell_f}rc"
cp -f ./minishell "$HOME"

if grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null && ls "$HOME"/./minishell &>/dev/null; then
	echo "\033[33m\n -- Minishell already installed --\n\033[0m"
  sleep 1
  exit 0

fi

if ! grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null; then
	echo "alias minishell='~/./minishell'" >>"$shell_f"
	echo "\033[32m\n -- Minishell setup successful --\n\033[0m"
  sleep 1
	exit 0

fi
