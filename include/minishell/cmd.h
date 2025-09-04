#ifndef CMD_H
# define CMD_H

#include <minishell/types.h>

#include <stdbool.h>

void	fork_cmd(t_cmd *cmd);
void	pipe_cmds(t_cmd *cmd1, t_cmd *cmd2);
bool	is_cmd_builtin(const char *name);

#endif
