/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:07 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/22 17:41:33 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_buffer(char *buf, char *sto, int fd)
{
	ssize_t	read_size;
	char	*tmp;

	while (!ft_strchr(sto, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = 0;
		tmp = sto;
		sto = ft_strjoin(sto, buf);
		free(tmp);
		if (!sto)
			return (0);
		if (read_size < BUFFER_SIZE)
			break ;
	}
	if (read_size == -1)
		return (0);
	if (read_size == 0 && sto[0] == 0)
		return (0);
	return (sto);
}

char	*ft_get_line(char **sto)
{
	size_t	n;
	char	*line;

	n = 0;
	while ((*sto)[n] && (*sto)[n] != '\n')
		n++;
	line = ft_substr(*sto, 0, n + 1);
	*sto = ft_substr(*sto, n + 1, ft_strlen(*sto) - n - 1);
	return (line);
}

char	*ft_free(char **buf1, char **buf2)
{
	free(*buf1);
	*buf1 = 0;
	free(*buf2);
	*buf2 = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*sto[OPEN_MAX];
	char		*buf;
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (!sto[fd])
	{
		sto[fd] = ft_strdup("");
		if (!sto[fd])
			return (0);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	tmp = ft_read_buffer(buf, sto[fd], fd);
	if (!tmp)
		return (ft_free(&buf, &sto[fd]));
	sto[fd] = tmp;
	line = ft_get_line(&sto[fd]);
	ft_free(&buf, &tmp);
	return (line);
}
