#!/bin/bash
shell_f=$(echo -n "$SHELL" | awk -F / '{print $3}')
shell_f="${HOME}/.${shell_f}rc"
rm -rf ~/./minishell

if grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null && ls "$HOME"/./minishell &>/dev/null; then
	echo "\033[33m\n -- Minishell already uninstalled --\n\033[0m"
    sed -i '' -e '$d' ~/.zshrc
    exit 0

fi

if ! grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null && ls "$HOME"/./minishell &>/dev/null; then
	echo "\033[33m\n -- Minishell already uninstalled --\n\033[0m"
    sed -i '' -e '$d' ~/.zshrc
    exit 0

fi