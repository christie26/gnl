/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:45:03 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/22 16:59:48 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*res;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	
	res = get_next_line(fd);
	printf("%s\n", res);
	ft_free(res);
	
	res = get_next_line(fd);
	printf("%s\n", res);
	ft_free(res);
	return (0);
}
