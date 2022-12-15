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

int	ft_read_buffer(char *buf, char **res, int fd)
{
	ssize_t	read_size;
	ssize_t	len;

	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == -1 || read_size == 0)
		return (0); 
	buf[read_size] = 0; 
	if (ft_strchr(buf, '\n'))
		len = (ft_strchr(buf, '\n') - buf);
	else
		len = read_size;
//	printf("len is %zu\n", len);
	if (!(*res)) //only initial called 
		*res = ft_strndup(buf, len);
	else
		*res = ft_strnjoin(*res, buf, len);
	if (len != read_size)
		return (1);
	else
		return (2);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*tab;
	int			val;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	val = 2;
	while (val == 2)
		val = ft_read_buffer(buf, &tab, fd);
	free(buf);
	return (tab);
}
