#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>

int	echo_builtin(char **argv);
int	pwd_builtin(bool print_output);
int	cd_builtin(char **argv, bool print_output);
int	env_builtin(void);
int	export_builtin(char **argv, bool print_output);
int	unset_builtin(char **argv);
int	exit_builtin(char **argv, bool print_output, bool is_single_cmd);

#endif
