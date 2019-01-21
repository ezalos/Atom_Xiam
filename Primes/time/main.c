/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 00:16:57 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/23 01:58:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int max is the 105 097 564th prime number 105097564
#include <stdio.h>
#include <stdlib.h>
#include "time_exe.h"

int		find_n_prime(int limite);
void	ft_puttab(const char *s, int separation);

int main(int ac, char **av)
{
//	char str[41];
//	int i = 0;

	if (ac < 2)
		return (0);
	time_exe(__func__, cl(clock()));
	printf("\n\n\t\tThe %dth prime number is: %d\n\n", atoi(av[1]), find_n_prime(atoi(av[1]) - 1));
	print_time(time_exe(__func__, clock()));
/*
	while (i < 41)
	{
		str[i] = ((i + 1) % 10) + '0';
		i++;
	}

	while (--i > -1)
	{
		str[i] = '\0';
		printf("%s", str);
		ft_puttab(str, atoi(av[1]));
		printf("|%d\n", i);
	}*/
	return (0);
}
