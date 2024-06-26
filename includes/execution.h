/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:06:20 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/14 14:27:56 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

/// ============================================================================
// EXECUTOR.C
// =============================================================================
/**
 * @brief Creates pipes and executes the ast. waits for all child to finish
 * their task.
 * 
 */
void	executor(void);

/**
 * @brief check if the command is not builtin and execute accordingly
 * 
 * @param ast 
 */
void	match_cmd(t_ast *ast, bool already_slept);

/**
 * @brief executes forkable commands. the function first checks if the command
 * is valid and sets exit_status. checks for redirection and set
 * fd accordingly. then for and connect in/output to the corresponding pipes.
 * executes the command and restore in/output.
 * 
 * @param ast 
 * @return int 
 */
void	execute_child(t_ast *ast);

/**
 * @brief call execve on the command path.
 * 
 * @param ast 
 * @return int 
 */
void	execute_cmd(t_ast *ast);

/// ============================================================================
// PIPES.C
// =============================================================================
/**
 * @brief creates the pipes array.
 * 
 */
void	pipe_create(void);

/**
 * @brief connect the io of the commands to the appropriate pipes
 * 
 * @param ast_pos 
 */
void	pipe_connect(int ast_pos);

/// ============================================================================
// REDIRECTIONS.C
// =============================================================================
/**
 * @brief handle the four different types of redirection
 * 
 * @param ast 
 */
int		handle_redir(t_ast *ast, bool *first);

/**
 * @brief calls dup2 on fd_in and fd_out that has been set previously
 * to pipes or files.
 * 
 */
void	redirect_io(void);

/**
 * @brief close the fd that have been open, restore STDIN and STDOUT
 * as the fd by default.
 * 
 * @param node_pos 
 */
void	restore_io(int node_pos);

/**
 * @brief creates a temporary file that will store the content inputed
 * during the heredoc and associate fd with the command
 * 
 * @param ast 
 */
void	handle_heredoc(t_ast *ast);

/**
 * @brief return true if token type is a redirection.
 * 
 * @param token 
 * @return true 
 * @return false 
 */
bool	is_redirection(t_token *token);

#endif