/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:37 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/03 12:00:45 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_chr	ft_strchr(const char *s, int c)
{
	char	key;
	char	*src;
	size_t	i;
	size_t	len_src;
	t_chr	res;

	src = (char *) s;
	len_src = ft_strlen(src);
	key = c;
	i = 0;
	res.ptr = 0;
	res.idx = 0;
	while (i < len_src)
	{
		if (src[i] == key)
		{
			res.ptr = src;
			res.idx = i;
			return (res);
		}
		i++;
	}
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	i;
	char	*s;

	s = (char *)src;
	i = 0;
	len_src = ft_strlen(s);
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	return (len_src);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*new;
	char	*tmp;

	len = ft_strlen((char *)src);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!(new))
		return (0);
	tmp = new;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (new);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	i = 0;
	if (size == 0)
		return (len_src);
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] && len_dst + 1 + i < size)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_dst + len_src);
}
