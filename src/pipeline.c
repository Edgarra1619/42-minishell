#include <minishell/types.h>
#include <minishell/env.h>
#include <libft.h>

#include <sys/wait.h>
#include <stdlib.h>

t_pipeline	*get_pipeline(void)
{
	static t_pipeline	s_pl;

	return (&s_pl);
}

void	clear_pipeline(t_pipeline *pl)
{
	t_cmd	*cmd;

	if (!pl)
		pl = get_pipeline();
	free(pl->prompt);
	pl->prompt = NULL;
	while (pl->num_cmds--)
	{
		cmd = pl->cmds + pl->num_cmds;
		free_split(cmd->argv);
		while (cmd->num_redirs--)
		{
			if (cmd->redirs[cmd->num_redirs].target_path)
				free(cmd->redirs[cmd->num_redirs].target_path[0]);
			free(cmd->redirs[cmd->num_redirs].target_path);
		}
	}
	pl->num_cmds = 0;
	free(pl->cmds);
	pl->cmds = NULL;
}

void	wait_pipeline(t_pipeline *const pl)
{
	int		i;
	int		status;
	char	*env_status;

	get_env(NULL, NULL, NULL, &env_status);
	i = 0;
	while (i < pl->num_cmds && pl->cmds[i].pid > 0)
	{
		waitpid(pl->cmds[i].pid, &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		*env_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		*env_status = 128 + WTERMSIG(status);
	else
		*env_status = 1;
}
