/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:54:30 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:54:31 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

int		get_error_status(void);
int		print_error(const char *cmd, const char *path, const char *error);
int		print_var_error(const char *cmd, const char *var, const char *error);
int		print_syntax_error(const char *error);

#endif
