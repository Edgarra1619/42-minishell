#ifndef ERROR_H
# define ERROR_H

int		print_error(const char *command, const char *path, const char *error);
int		print_var_error(const char *var, const char *error);
int		print_syntax_error(const char *error);
void	buffer_error(const char *str);

#endif
