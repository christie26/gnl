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

// return null if they can't find the key
char	*ft_strchr(const char *s, int c)
{
	char	key;
	char	*src;
	size_t	i;
	size_t	len_src;

	src = (char *) s;
	len_src = ft_strlen(src);
	key = c;
	i = 0;
	while (i < len_src + 1)
	{
		if (*src == key)
			return (src);
		src++;
		i++;
	}
	return (0);
}

char	*ft_strndup(const char *src, size_t len)
{
//	size_t	len;
	char	*new;
	char	*tmp;

//	len = ft_strlen((char *)src);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!(new))
		return (0);
	tmp = new;
	while (*src && *src != '\n')
		*tmp++ = *src++;
	*tmp = 0;
	return (new);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*dst;
	size_t	len_s1;
//	size_t	len_s2;
	size_t	total;

	len_s1 = ft_strlen((char *)s1);
//	len_s2 = ft_strlen((char *)s2);
	total = len_s1 + len;
	dst = (char *)malloc(sizeof(char) * (total + 1));
	if (!dst)
		return (0);
	while (len_s1--)
		*dst++ = *s1++;
	while (len--)
		*dst++ = *s2++;
//	free((void *)s1);
	*dst = 0;
	dst -= total;
	return (dst);
}
/*
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;
	size_t	total;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	total = len_s1 + len_s2;
	dst = (char *)malloc(sizeof(char) * (total + 1));
	if (!dst)
		return (0);
	while (len_s1--)
		*dst++ = *s1++;
	while (len_s2--)
		*dst++ = *s2++;
	*dst = 0;
	dst -= total;
	return (dst);
}
*/
