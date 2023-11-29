/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <jgomes-v@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:01:08 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/29 16:44:57 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(t_ast *ast)
{
	int		i;
	bool	new_line;

	i = 1;
	new_line = true;
	if (!ast->args[i])
		return (printf("\n"));
	if (!ft_strncmp(ast->args[i], "-n", 3))
	{
		new_line = false;
		i++;
	}
	while (ast->args[i])
	{
		printf("%s", ast->args[i++]);
		if (ast->args[i])
			printf(" ");
	}
	if (new_line)
		printf("\n");
	return (EXIT_SUCCESS);
}
