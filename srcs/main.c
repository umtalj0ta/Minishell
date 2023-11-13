/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:34:54 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/13 16:48:25 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* variable to have access to the struc during debug*/
t_shell	*debug_shell;

t_shell	*sh(void)
{
	static t_shell	sh;

	debug_shell = &sh;
	return (&sh);
}

static void	main_loop(void)
{
	while (42)
	{
		sh()->line = readline("prompt> ");
		signals(1);
		add_history(sh()->line);
		parser();
		if (!ft_strncmp(sh()->line, "exit", 4))
		{
			free_shell(false);
			break ;
		}
		print_token_content();
		free_shell(true);
	}
	clear_history();
}

int	main(void)
{
	init_shell();
	main_loop();
	return (EXIT_SUCCESS);
}
