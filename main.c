#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*res;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	res = get_next_line(fd);
	printf("result is %s\n", res);
}
