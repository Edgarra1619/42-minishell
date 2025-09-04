#include <minishell/env.h>
#include <minishell/tokenizer.h>
#include <minishell/exec.h>
#include <minishell/pipeline.h>
#include <libft.h>

#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv, char **prev_envp)
{
	t_pipeline *const	pl = get_pipeline();
	char				*status;

	(void)argc;
	(void)argv;
	init_env(prev_envp);
	get_env(NULL, NULL, NULL, &status);
	while (1)
	{
		pl->prompt = readline("$ ");
		if (!pl->prompt)
			break ;
		if (pl->prompt[0])
			add_history(pl->prompt);
		if (tokenize_pipeline(pl))
		{
			clear_pipeline(pl);
			continue ;
		}
		exec_pipeline(pl);
		wait_pipeline(pl);
		clear_pipeline(pl);
	}
	rl_clear_history();
	return (*status);
}
