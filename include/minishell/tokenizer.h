/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:56:24 by edgribei          #+#    #+#             */
/*   Updated: 2025/09/23 14:56:27 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <minishell/types.h>

# include <stdbool.h>

int		tokenize_pipeline(t_pipeline *pl);
int		tokenize_cmd(t_cmd *cmd);
int		verify_prompt_syntax(const char *prompt);
int		append_args(char **arg, char *str, char *end);
void	expand_str(char **line, char **input);
char	*find_next_special(char *str);
int		parse_whtspc(int *argc, char ***arg, char **str);
int		parse_quotes(char **arg, char **str, bool dquote);
int		parse_expans(int *argc, char ***arg, char **str, bool inquotes);
int		parse_redirs(char **arg, t_cmd *cmd);

#endif
