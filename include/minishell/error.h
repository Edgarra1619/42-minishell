#ifndef ERROR_H
# define ERROR_H

void	error_exit(void);
int		print_error(const char *cmd, const char *path, const char *error);
int		print_var_error(const char *var, const char *error);
int		print_syntax_error(const char *error);

#endif
