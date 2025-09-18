#include <minishell/exit.h>
#include <minishell/error.h>
#include <minishell/fd.h>
#include <minishell/signals.h>
#include <minishell/tokenizer.h>
#include <minishell/types.h>

#include <libft.h>

#include <signal.h>
#include <stdlib.h>

int	parse_next_special(char ***arg, int *argc, t_cmd *cmd, bool parse_spaces);

static int	get_redirtype(char *str)
{
	while (*str)
	{
		if (*str == '<')
		{
			if (*(str + 1) == '<')
				return (OPEN_HEREDOC);
			if (*(str + 1) == '>')
				return (OPEN_RDWR);
			return (OPEN_READ);
		}
		if (*str == '>')
		{
			if (*(str + 1) == '<')
				return (0);
			if (*(str + 1) == '>')
				return (OPEN_APPEND);
			return (OPEN_WRITE);
		}
		str++;
	}
	return (0);
}

static int	get_redirfd(char **arg, char **str, int type)
{
	int			fd;
	char	*tmp;

	tmp = *str;
	if (ft_atoi_safe(&fd, *str))
		fd = -1;
	while (*tmp != '<' && *tmp != '>')
	{
		if (!ft_isdigit(*tmp))
			fd = -1;
		tmp++;
	}
	if (fd < 0 || *str == tmp)
	{
		if(*str != tmp)
			append_args(arg, *str, tmp);
		if (type == OPEN_HEREDOC || type == OPEN_READ
			|| type == OPEN_RDWR)
			fd = 0;
		if (type == OPEN_APPEND || type == OPEN_WRITE)
			fd = 1;
	}
	*str = tmp + 1 + (type == OPEN_HEREDOC
		|| type == OPEN_APPEND || type == OPEN_RDWR);
	return (fd);
}

int	parse_redirs(char **arg, t_cmd *cmd)
{
	t_redir *const	redir = cmd->redirs + cmd->num_redirs++;
	int				argc;

	redir->open_flags = get_redirtype(cmd->cmd);
	argc = 0;
	redir->source_fd = get_redirfd(arg, &cmd->cmd, redir->open_flags);
	while (ft_isspace(*cmd->cmd))
		(cmd->cmd)++;
	redir->target_path = ft_calloc(sizeof(char *), argc + 2);
	while (*cmd->cmd)
	{
		if (parse_next_special(&(redir->target_path), &argc, cmd, false))
			return (1);
		if (cmd->cmd[-1] == ' ')
			break ;
	}
	if (argc > 0)
		return (print_syntax_error("ambiguous redirection"));
	if (!redir->target_path[0] || !redir->target_path[0][0])
		return (print_syntax_error("incomplete redirection"));
	if (redir->open_flags == OPEN_HEREDOC)
		open_heredoc(&(redir->target_fd), redir->target_path[0]);
	return (0);
}

