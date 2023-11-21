/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:01:08 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/21 14:40:37 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(char **args)
{
	int		i;
	bool	new_line;

	i = 1;
	new_line = true;
	if (!args[i])
		return (printf("\n"));
	if (!ft_strncmp(args[i], "-n", 3))
	{
		new_line = false;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i++]);
		if (args[i])
			printf(" ");
	}
	if (new_line)
		printf("\n");
	return (EXIT_SUCCESS);
}
