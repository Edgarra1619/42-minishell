#ifndef BUILTINS_H
# define BUILTINS_H

#include <stdbool.h>

int	echo(char **argv);
int	pwd(bool print_output);
int	cd(char **argv, bool print_output);
int	env(void);
int	export(char **argv, bool print_output);
int	unset(char **argv);

#endif
