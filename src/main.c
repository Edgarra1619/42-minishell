#include <minishell/env.h>
#include <minishell/exec.h>
#include <minishell/signals.h>
#include <minishell/tokenizer.h>
#include <libft.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **prev_envp)
{
	t_pipeline	pl;
	char		*status;

	(void)argc;
	(void)argv;
	init_env(prev_envp);
	get_env(NULL, NULL, NULL, &status);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, prompt_handler);
		pl.prompt = readline("$ ");
		if (!pl.prompt)
			return (1);
		add_history(pl.prompt);
		if (tokenize_pipeline(&pl))
		{
			free(pl.prompt);
			continue ;
		}
		exec_pipeline(&pl);
		signal(SIGINT, cmd_handler);
		signal(SIGQUIT, cmd_handler);
		wait_pipeline(&pl);
		free(pl.prompt);
	}
	return (0);
}
