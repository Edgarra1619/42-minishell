#ifndef PIPELINE_H
# define PIPELINE_H

# include <minishell/types.h>

t_pipeline	*get_pipeline(void);
void		exec_pipeline(t_pipeline *pl);
void		clear_pipeline(t_pipeline *pl);
void		wait_pipeline(t_pipeline *pl);

#endif
