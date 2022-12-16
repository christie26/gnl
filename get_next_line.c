/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:07 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/15 17:08:05 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_read_buffer(char *buf, char 	*res, int fd)
{
	ssize_t	read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == -1 || read_size == 0)
		return (0); 
	buf[read_size] = 0; 
	if (!(res)) 
		res = ft_strdup(buf);
	else
		res = ft_strjoin(res, buf);
	return (res);
}

char	*ft_remove_line(char *sto, char *line)
{
	size_t	len;
	char	*tmp;
	char	*new;

	len = ft_strlen(line);
	tmp = sto + len;
	new = ft_strdup(tmp);
	free (sto);
	sto = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*sto;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!ft_strchr(buf, '\n'))
	{
		sto = ft_read_buffer(buf, sto, fd);
		if (!sto) //error
		{
			free(buf);
			buf = 0;
			return (0);
		}		
	}
	free(buf);
	buf = 0;
	line = ft_strndup(sto);
	sto = ft_remove_line(sto, line);
	return (line);
}
