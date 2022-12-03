#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int	fd;
	int rd;
	char *buf;

	(void)ac;
	buf = (char *)malloc(BUFFER);
	fd = open (av[1], O_RDONLY);
	rd = read(fd, buf, BUFFER);
	printf("buf is %s\nrd is %d", buf, rd);
}
