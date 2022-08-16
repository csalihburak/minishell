#!/bin/bash
#agunes
shell_f=$(echo -n "$SHELL" | awk -F / '{print $3}')
shell_f="${HOME}/.${shell_f}rc"

if grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null && ls "$HOME"/./minishell &>/dev/null; then
    sed -i '' -e '$ d' ~/.zshrc
    exit 0

fi

if ! grep "alias minishell='~/./minishell'" <"$shell_f" &>/dev/null && ls "$HOME"/./minishell &>/dev/null; then
    exit 0

fi