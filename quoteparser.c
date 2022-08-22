/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoteparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:35:21 by malasaha          #+#    #+#             */
/*   Updated: 2022/08/22 10:26:53 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_char(const char *str, int index, char c)
{
	int	in;
	int	i;

	in = 0;
	i = 0;
	if (str[index] == c)
		return (-1);
	while (str[i])
	{
		if (i == index)
		{
			if (in)
				return (1);
			return (0);
		}
		if (str[i] == c)
		{
			in = !in;
		}
		i++;
	}
	return (0);
}

int	in_quotes(const char *s, int i)
{
	return (in_char(s, i, '\'') || in_char(s, i, '"'));
}

int	in_single_quotes(const char *s, int i)
{
	return (in_char(s, i, '\''));
}

size_t	w_l(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && (s[r] != c || in_quotes(s, r)))
		r++;
	return (r);
}

size_t	w_c(char const *s, char c)
{
	size_t	r;
	size_t	i;

	r = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' \
		|| (s[i + 1] == c && !in_quotes(s, i + 1))))
			r++;
		i++;
	}
	return (r);
}

char	**ft_split_quote(char const *s, char c)
{
	char		**r;
	size_t		i;
	size_t		l;
	size_t		w_i;
	char const	*sf;

	sf = s;
	if (!s)
		return (NULL);
	l = w_c(s, c);
	r = (char **)malloc(sizeof(char *) * l + 1);
	i = -1;
	while (++i < l)
	{
		while ((*s == c && !in_quotes(sf, s - sf)) && *s != '\0')
			s++;
		r[i] = (char *)malloc(sizeof(char) * w_l(s, c) + 1);
		w_i = 0;
		while ((*s != c || in_quotes(sf, s - sf)) && *s != '\0')
			r[i][w_i++] = *s++;
		r[i][w_i] = '\0';
	}
	r[i] = NULL;
	return (r);
}
