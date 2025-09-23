/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:54:39 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:54:40 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <minishell/types.h>

# include <stdbool.h>

void	fork_cmd(t_cmd *cmd);
void	pipe_cmds(t_cmd *cmd1, t_cmd *cmd2);
bool	is_cmd_builtin(const char *name);

#endif
