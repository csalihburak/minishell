#!/bin/bash
#agunes
shell_f=$(echo -n "$SHELL" | awk -F / '{print $3}')
shell_f="${HOME}/.${shell_f}rc"
cp -f ./minishell "$HOME"

if ! grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null; then
	echo "alias minishell='~/./minishell'" >>"$shell_f"
	exit 0

fi