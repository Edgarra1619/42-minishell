#include <minishell/pipeline.h>
#include <minishell/error.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	clear_exit(const char status)
{
	clear_pipeline(NULL);
	rl_clear_history();
	exit(status);
}

void	error_exit(const char status)
{
	print_error(NULL, NULL, NULL);
	clear_exit(status);
}
