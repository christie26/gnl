
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 1

char *ft_update(char *res, char *buf, size_t len)
{
	char *tmp;

	if (res)
	{
		tmp = ft_strdup(res);
		free(res);
		res = (char *)malloc(len + 1);
		if (!res)
			return (0);
		ft_strlcpy(res, tmp, ft_strlen(tmp) + 1);
		free(tmp);
		ft_strlcat(res, buf, len + 1);
	}
	else
	{
		res = (char *)malloc(len + 1);
		if (!res)
			return (0);
		ft_strlcpy(res, buf, len + 1);
	}
	res[len] = 0;
	return (res);
}

char *get_next_line(int fd)
{
	char	*buf;
	char	*res;
	size_t	len;
	t_chr	chr;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	len = 0;
	res = 0;
	while (1)
	{
		read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = 0;
		chr = ft_strchr(buf, '\n');
		if (chr.ptr)	//chr.ptr is not null -> stop 
		{
			len += chr.idx;
			res = ft_update(res, buf, len);
			if (!res)
				return (0);	
			break;
		}
		else // keep going 
		{
			len += BUFFER_SIZE;
			res = ft_update(res, buf, len);
			if (!res)
				return (0);	
		}	
	}
	return (res); 
}

int main(void)
{
	char	*res;
	int		fd;
	fd = open("./text.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("result is %s\n", res);
}
