/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_prime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:40:58 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/23 03:07:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "time_exe.h"

int	ft_find_next_prime(int nb, int *prime_list)
{
	int x;
	time_exe(__func__, cl(clock()));

	x = 0;
	if (nb <= 2)
		return(2);
	if (nb == 3)
		return (nb);
	while (nb <= 2147483647)
	{
		while (prime_list[x]!=0 && prime_list[x] <= nb / prime_list[x])
		{
			if (nb % prime_list[x] == 0)
			{
				nb++;
				x = -1;
			}
			x++;
		}
		return(nb); //nombre premier est int max
	}
	return(0); //Nombre recherché superieur a int max
}

int   *initialize(int *prime_list, int limite)
{
	int i = 0;
	time_exe(__func__, cl(clock()));

	while(i<=limite)
		prime_list[i++]=0;
	return(prime_list);
}

int		find_n_prime(int limite)
{
	time_exe(__func__, cl(clock()));
	int compteur = 0;
	int *prime_list = NULL;

	if(!(prime_list = (int*)malloc((limite + 2) * sizeof(int))))
	{
		printf("\tMALLOC Faillure!\n");
		return (0);
	}
	prime_list = initialize(prime_list, limite + 1);
	prime_list[compteur] = 2;

	while (compteur++ < limite)
		prime_list[compteur] = ft_find_next_prime(prime_list[compteur - 1] + 1, prime_list);

	compteur = prime_list[compteur - 1];
	return (compteur);
}
