/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:34:51 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/16 11:26:35 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_cmd_path(char *cmd)
{
	char		*cmd_path;
	struct stat	stats;

	if (ft_strchr(cmd, '/'))
	{
		stat(cmd, &stats);
		if (!S_ISDIR(stats.st_mode) && !access(cmd, F_OK))
			return (print_error(126, PERM_DEN, cmd));
		if (!S_ISDIR(stats.st_mode))
			return (print_error(127, ERR_DIR, cmd));
		return (print_error(126, "is a directory", cmd));
	}
	cmd_path = get_cmd_path(cmd);
	stat(cmd_path, &stats);
	if (!cmd_path || (S_ISDIR(stats.st_mode)))
		return (print_error(CMD_NT_FD, ERR_CMD, cmd));
	// if (!access(cmd_path, F_OK) && !access(cmd_path, X_OK))
	// 	return (print_error(126, PERM_DEN, cmd_path));
	free(cmd_path);
	return (EXIT_SUCCESS);
}

bool	is_forkable(char *cmd)
{
	if (!ft_strncmp(cmd, "cd", 3) || !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6) || !ft_strncmp(cmd, "exit", 5))
		return (false);
	return (true);
}

bool	is_operator(t_token *token)
{
	if (token->type == OTHER)
		return (false);
	return (true);
}

char	*get_absolute_path(char *cmd)
{
	char	*path1;
	char	*path;
	int		i;

	i = -1;
	if (!access(cmd, R_OK | F_OK | X_OK))
		return (ft_strdup(cmd));
	while (sh()->path[++i])
	{
		path1 = ft_strjoin(sh()->path[i], "/");
		path = ft_strjoin(path1, cmd);
		free(path1);
		if (!access(path, R_OK | F_OK | X_OK))
			return (path);
		free(path);
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd)
{
	char	*path;
	char	*cwd;

	if (*cmd == '.')
	{
		cmd++;
		cwd = getenv_var("PWD");
		path = ft_strjoin(cwd, cmd);
	}
	else
		path = get_absolute_path(cmd);
	return (path);
}
