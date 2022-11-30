#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char	*res;
	int		fd;
	fd = open("./text.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("result is %s\n", res);
}