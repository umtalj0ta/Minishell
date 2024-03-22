/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:54 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/22 10:00:07 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_exit(void)
{
	int		count;
	char	*substr;

	count = 0;
	scanner(RESET);
	while (scanner(READ))
	{
		substr = ft_strnstr(scanner(READ)->content, "exit",
				ft_strlen(scanner(READ)->content));
		if (substr)
			count++;
		scanner(NEXT);
	}
	return (count);
}

void	run_exit(t_ast *ast)
{
	if (get_matrix_len(ast->args) > 2)
	{
		print_error(1, "too many arguments", "exit");
		return ;
	}
	if (ast->args[1] && ft_isnumeric(ast->args[1]))
		sh()->exit_status = ft_atoi(ast->args[1]) % 256;
	else if (ast->args[1] && !ft_isnumeric(ast->args[1]))
		print_error(ERR_SYNTHAX, "numeric argument required", ast->args[1]);
	printf("exit\n");
	free_shell(false);
}
