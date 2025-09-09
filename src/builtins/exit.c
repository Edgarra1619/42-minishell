#include <minishell/env.h>
#include <minishell/pipeline.h>
#include <minishell/error.h>
#include <minishell/exit.h>
#include <libft.h>

#include <stdlib.h>
#include <stdbool.h>

int	exit_builtin(char **argv, const bool print_output, const bool is_single_cmd)
{
	char	*env_status;
	int		status;

	if (!argv[1])
	{
		get_env(NULL, NULL, NULL, &env_status);
		status = *env_status;
	}
	else if (argv[2])
	{
		if (print_output)
			print_error("exit", NULL, "too many arguments");
		return (1);
	}
	else if (ft_atoi_safe(&status, argv[1]))
	{
		if (print_output)
			print_error("exit", NULL, "numeric argument required");
		return (1);
	}
	if (is_single_cmd && print_output)
		ft_putstr_fd("exit\n", 2);
	clear_exit(status);
	return (1);
}
