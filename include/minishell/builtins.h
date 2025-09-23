/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:54:21 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:54:22 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>

int	echo_builtin(char **argv);
int	pwd_builtin(bool print_output);
int	cd_builtin(char **argv, bool print_output);
int	env_builtin(void);
int	export_builtin(char **argv, bool print_output);
int	unset_builtin(char **argv, bool print_output);
int	exit_builtin(char **argv, bool print_output, bool is_single_cmd);

#endif
