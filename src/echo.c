#include <libft.h>

int	echo(char **argv)
{
	int	newline;
	int	i;

	newline = 1;
	++argv;
	while (*argv && argv[0][0] == '-' && argv[0][1])
	{
		i = 1;
		while (argv[0][i] == 'n')
			++i;
		if (argv[0][i])
			break ;
		newline = 0;
		++argv;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv, 1);
		if (argv[1])
			ft_putchar_fd(' ', 1);
		++argv;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
