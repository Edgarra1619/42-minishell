/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:47:20 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:47:21 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
