#include <minishell/env.h>
#include <minishell/signals.h>
#include <minishell/tokenizer.h>
#include <minishell/pipeline.h>
#include <minishell/exit.h>
#include <libft.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

int	main(__attribute__((unused)) int argc,
	__attribute__((unused)) char **argv,
	char **prev_envp)
{
	t_pipeline *const	pl = get_pipeline();
	char				*status;

	init_env(prev_envp);
	get_env(NULL, NULL, NULL, &status);
	while (1)
	{
		clear_pipeline(pl);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, prompt_handler);
		pl->prompt = readline("$ ");
		if (!pl->prompt)
			break ;
		if (pl->prompt[0])
			add_history(pl->prompt);
		if (tokenize_pipeline(pl))
			continue ;
		exec_pipeline(pl);
		signal(SIGINT, cmd_handler);
		signal(SIGQUIT, cmd_handler);
		wait_pipeline(pl);
	}
	ft_putstr_fd("exit\n", 2);
	clear_exit(*status);
}
