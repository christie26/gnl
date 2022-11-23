
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	char	*buf;
	size_t	len;

	len = 0;
	while (read(fd, &buf, 1) > 0)
	{
		len++;
		buf++;
	}
	return (buf); 
}

int main(void)
{
	char	*res;
	int		fd;
	fd = open("./text.txt", O_RDWR);
	res = get_next_line(fd);
	write(1, &res, 5);
}
