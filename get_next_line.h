/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:22 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/15 17:08:07 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *src, size_t len);
char	*ft_strnjoin(const char *s1, const char *s2, size_t len);
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
//size_t	ft_strlcat(char *dst, const char *src, size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif
