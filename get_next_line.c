
#include "get_next_line.h"
#define BUFFER_SIZE 1

int	ft_update(char *res, char *buf, size_t len)
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
	return (1);
}

int	ft_read_line(char *res, char *buf, size_t len, int fd)
{
	t_chr	chr;
	int		val;

	val = read(fd, buf, BUFFER_SIZE);
	if (val == -1)
		return (0);
	buf[BUFFER_SIZE] = 0;			// file ends before BUFFER_SIZE
	chr = ft_strchr(buf, '\n');
	if (chr.ptr)
	{
		len += chr.idx;
		val = ft_update(res, buf, len);
		if (val == 0)
			return (0);	
		return (1);
	}
	else
	{
		len += BUFFER_SIZE;
		val = ft_update(res, buf, len);
		if (val == 0)
			return (0);	
	}
	return (2);
}

char *get_next_line(int fd)
{
	char		*buf;
	static char	*res;
	int			val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	res = 0;
	while (1)
	{
		val = ft_read_line(res, buf, 0, fd);
		if (val == 0)
			return (0);
		else if (val == 1)
			break ;
	}
	return (res); 
}