/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:47:26 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:47:27 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/signals.h>
#include <minishell/minishell.h>
#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

#include <limits.h>
#include <unistd.h>

void	remove_uninitialized_vars(void)
{
	char	**envp;

	get_env(NULL, NULL, &envp, NULL);
	while (*envp)
	{
		if (!ft_strchr(*envp, '='))
			remove_var(*envp);
		envp++;
	}
}

void	update_status_signal(void)
{
	char	*status;

	if (!g_lastsignal)
		return ;
	get_env(NULL, NULL, NULL, &status);
	*status = 128 + g_lastsignal;
	g_lastsignal = 0;
}

void	update_pwd(const bool print_output)
{
	char *const	pwd = get_var("PWD");
	char		buffer[VAR_MAX];
	char		cwd[PATH_MAX];

	if (pwd)
	{
		ft_strlcpy(buffer, "OLDPWD=", VAR_MAX);
		ft_strlcat(buffer, pwd, VAR_MAX);
		set_var(buffer, print_output);
	}
	ft_strlcpy(buffer, "PWD=", VAR_MAX);
	if (getcwd(cwd, PATH_MAX))
		ft_strlcat(buffer, cwd, VAR_MAX);
	set_var(buffer, print_output);
}

void	update_shlvl(int add, const bool print_output)
{
	char *const	shlvl = get_var("SHLVL");
	int			lvl;

	if (!shlvl)
	{
		set_var("SHLVL=1", print_output);
		return ;
	}
	lvl = ft_atoi(shlvl);
	if (lvl >= 999)
	{
		print_error(NULL, NULL,
			"warning: shell level too high, resetting to 1");
		set_var("SHLVL=1", print_output);
		return ;
	}
	ft_itoa_cpy(shlvl, ft_max(lvl + add, 0));
}
