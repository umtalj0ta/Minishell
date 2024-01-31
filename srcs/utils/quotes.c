/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:36 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/31 11:31:43 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_quotes(char *line)
{
	int		quotes;
	int		in_squote;
	int		in_dquote;

	quotes = 0;
	in_squote = 0;
	in_dquote = 0;
	while (*line)
	{
		if (*line == '\'' && in_dquote == 0)
		{
			in_squote = 1 - in_squote;
			quotes++;
		}
		else if (*line == '"' && in_squote == 0)
		{
			in_dquote = 1 - in_dquote;
			quotes++;
		}
		line++;
	}
	return (quotes);
}

char	*remove_quotes(char *content, char quote)
{
	char	*res;
	char	*pre;
	int		i;
	int		j;
	int		count;

	pre = pre_trim(content, quote);
	i = -1;
	count = 0;
	while (pre[++i])
		if (pre[i] == quote)
			count++;
	res = ft_calloc(sizeof(char), i - count + 1);
	i = 0;
	j = 0;
	while (pre[i])
	{
		if (pre[i] == quote)
			i++;
		else
			res[j++] = pre[i++];
	}
	res[j] = '\0';
	free(pre);
	return (res);
}

char	get_first_quote(char *line)
{
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
			return (*line);
		line++;
	}
	return (*line);
}

int	get_last_quote_pos(char *line)
{
	int		i;
	char	quote;
	int		pos;
	int		quotes_count;

	quotes_count = 0;
	quote = get_first_quote(line);
	pos = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == quote)
		{
			pos = i;
			quotes_count++;
		}
		if ((line[i] == ' ' || line[i] == '>' || line[i] == '<'
				|| line[i] == '|') && quotes_count % 2 == 0)
			break ;
	}
	return (pos);
}
