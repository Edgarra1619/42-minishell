#include <minishell/signals.h>
#include <minishell/minishell.h>

#include <readline/readline.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

int	g_lastsignal;

void	heredoc_handler(int sig)
{
	write(1, "\n", 1);
	close(0);
	g_lastsignal = sig;
}

void	prompt_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	rl_replace_line("", 1);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	cmd_handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
	else
		write(1, "Quit (core dumped)\n", 19);
}
