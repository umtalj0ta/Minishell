/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:50:54 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/10 14:00:22 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	has_enclosed_quotes(char *line)
{
	int	s_quotes;
	int	d_quotes;

	s_quotes = 0;
	d_quotes = 0;
	while (*line)
	{
		if (*line == '\'')
			s_quotes++;
		if (*line == '\"' )
			d_quotes++;
		line++;
	}
	if (s_quotes % 2 != 0 || d_quotes % 2 != 0)
		return (false);
	return (true);
}

int	parser(t_shell *shell, char *line)
{
	if (!has_enclosed_quotes(line))
		return (print_error(ERR_UNCLOSED_QUOTES));
	get_token(shell, line);
	syntax_checker(shell->token);
	//exander
	//upon success return SUCCESS
	return (EXIT_SUCCESS);
}
