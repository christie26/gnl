/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:45:03 by yoonsele          #+#    #+#             */
/*   Updated: 2022/12/23 10:53:58 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*res1;
	char	*res2;
	int		fd1;
	int		fd2;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	for (int i = 0; i < 4; i++)
	{
		res1 = get_next_line(fd1);
		printf("%s\n", res1);
		free(res1);
	}
	for (int i = 0; i < 4; i++)
	{
		res2 = get_next_line(fd2);
		printf("%s\n", res2);
		free(res2);
	}
	return (0);
}
