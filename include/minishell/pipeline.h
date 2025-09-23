/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:55:20 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:55:21 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include <minishell/types.h>

t_pipeline	*get_pipeline(void);
void		exec_pipeline(t_pipeline *pl);
void		clear_pipeline(t_pipeline *pl);
void		wait_pipeline(t_pipeline *pl);

#endif
