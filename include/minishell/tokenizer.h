#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <minishell/types.h>

int	tokenize_pipeline(t_pipeline *const pl);
int	tokenize_cmd(t_cmd *cmd);
int	verify_prompt_syntax(const char *prompt);

#endif
