#include <minishell/env.h>
#include <minishell/pipeline.h>
#include <minishell/error.h>
#include <libft.h>

#include <stdlib.h>
#include <stdbool.h>

int	exit_builtin(char **argv, const bool print_output)
{
	char	*env_status;
	int		status;

	if (!argv[1])
	{
		clear_pipeline(NULL);
		get_env(NULL, NULL, NULL, &env_status);
		exit(*env_status);
	}
	if (argv[2])
	{
		if (print_output)
			print_error("exit", NULL, "too many arguments");
		return (1);
	}
	if (ft_atoi_safe(&status, argv[1]))
	{
		if (print_output)
			print_error("exit", NULL, "numeric argument required");
		return (1);
	}
	clear_pipeline(NULL);
	exit(status);
}
