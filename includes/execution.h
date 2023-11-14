/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:06:20 by achabrer          #+#    #+#             */
/*   Updated: 2023/11/14 17:43:44 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

/// ============================================================================
// EXECUTOR.C
// =============================================================================
void	executor(t_ast *ast);
int		execute_cmd(t_ast *ast);
char	*redir_output(t_ast *ast);

/// ============================================================================
// EXECUTOR_UTIL.C
// =============================================================================
bool	is_not_operator(t_token *token);
char	*get_cmd_path(char *cmd);

#endif