/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:07 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/03 18:05:03 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_update(char *res, char *buf, size_t len)
{
	char	*tmp;

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

int	ft_read_line(char *buf, size_t *len, int fd)
{
	t_chr	chr;
	int		val;

	val = read(fd, buf, BUFFER_SIZE);
	if (val == -1 || val == 0) // invalid or empty file -> problem when file end free buf  
		return (0);
	buf[BUFFER_SIZE] = 0;
	chr = ft_strchr(buf, '\n');
	if (chr.ptr)
	{
		*len += (chr.idx + 1);
		return (1);
	}
	else
		*len += BUFFER_SIZE;
	return (2);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*res;
	int				val;
	static size_t	len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	res = 0;
	len = 0;
	while (1)
	{
		val = ft_read_line(buf, &len, fd);
		if (val == 1) //when they meet new line 
		{
			res = ft_update(res, buf, len);
			break ;
		}
		else if (val == 0)
			break ;
		else
			res = ft_update(res, buf, len);
	}
	if (res == 0 || val == 0)
		free(buf);
	return (res);
}
