/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:50:54 by achabrer          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/10 20:39:56 by jgomes-v         ###   ########.fr       */
=======
/*   Updated: 2023/11/11 11:12:36 by achabrer         ###   ########.fr       */
>>>>>>> 7ba973f3153ccd150b3bc420078a6536a76631c8
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

bool	has_enclosed_quotes(char *line)
{
	return (count_quotes(line) % 2 == 0);
}

int	parser(t_shell *shell, char *line)
{
	if (!has_enclosed_quotes(line))
		return (print_error(ERR_UNCLOSED_QUOTES, 2));
	get_token(shell, line);
	if (!shell->token)
<<<<<<< HEAD
		main_loop(shell);
=======
		return (EXIT_FAILURE);
>>>>>>> 7ba973f3153ccd150b3bc420078a6536a76631c8
	syntax_checker(shell->token);
	//expander
	command_table_generator(shell);
	return (EXIT_SUCCESS);
}
