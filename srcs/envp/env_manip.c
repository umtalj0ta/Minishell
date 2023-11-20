/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:30:04 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/14 11:20:14 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*scanner_env(t_operation op)
{
	static t_list	*curr = NULL;

	if (op == RESET)
		curr = sh()->env_lst;
	else if (op == READ && curr)
		return (curr->content);
	else if (op == NEXT && curr)
		curr = curr->next;
	else if (op == GET_NEXT)
		return (curr->next->content);
	return (NULL);
}

char	*my_getenv(char *key)
{
	scanner_env(RESET);
	while (scanner_env(READ))
	{
		if (ft_strnstr(scanner_env(READ)->key, key, ft_strlen(key)))
			return (scanner_env(READ)->value);
		scanner(NEXT);
	}
	return (NULL);
}