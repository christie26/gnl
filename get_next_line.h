
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_chr
{
	char	*ptr;
    size_t  idx;
}	t_chr;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
t_chr   ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
