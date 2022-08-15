#!/bin/bash
shell_f=$(echo -n "$SHELL" | awk -F / '{print $3}')
shell_f="${HOME}/.${shell_f}rc"
rm -rf ~/./minishell

while true; do

echo "\033[33mDo you really want to uninstall this program ? \033[0m\0"
	read -r yn
	case $yn in
	[Yy]*) break ;;
	[Nn]*) exit ;;
	*) echo "\n\033[31mPlease answer yes or no !\033[0m\0\n" ;;
	esac
done

if grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null && ls "$HOME"/./minishell &>/dev/null; then
	echo "\033[33m\n -- Minishell uninstall complete --\n\033[0m"
    sed -i '' -e '$ d' ~/.zshrc
	sleep 1
    exit 0

fi

if ! grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null && ls "$HOME"/./minishell &>/dev/null; then
	echo "\033[33m\n -- Minishell already uninstalled --\n\033[0m"
    sed -i '' -e '$ d' ~/.zshrc
	sleep 1
    exit 0

fi