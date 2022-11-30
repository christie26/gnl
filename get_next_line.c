
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 5

char *get_next_line(int fd)
{
	char	*buf;
	char	*res;
	char	*ptr;
	size_t	i;

	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	

	while (1)
	{
		read(fd, &buf, BUFFER_SIZE);
		ptr = ft_strchr(buf, '\n');
		if (!ptr)
			break;
		ptr = '\0';
		
	}
	
	// copy until that [buf -> res] strlcat 
	// read again in buf


	return (buf); 
}

int main(void)
{
	char	*res;
	int		fd;
	fd = open("./text.txt", O_RDONLY);
	res = get_next_line(fd);
	write(1, &res, 5);
}
