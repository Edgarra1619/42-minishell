/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:46 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:48:47 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/env.h>
#include <minishell/error.h>
#include <minishell/exit.h>
#include <libft.h>

static bool	is_num(const char *str);

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
	else if (!is_num(argv[1]) || ft_atoi_safe(&status, argv[1]))
	{
		if (print_output)
			print_error("exit", argv[1], "numeric argument required");
		return (2);
	}
	if (is_single_cmd && print_output)
		ft_putstr_fd("exit\n", 2);
	clear_exit(status);
	return (1);
}

static bool	is_num(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (true)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
		if (!*str)
			return (true);
	}
}
