/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:45:03 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/23 10:52:50 by yoonsele         ###   ########.fr       */
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
	
	for (int i = 0; i < 4; i++)
	{
		res = get_next_line(fd);
		printf("%s\n", res);
		free(res);
	}
	return (0);
}
