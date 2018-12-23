/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_prime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:40:58 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/22 21:12:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "time_exe.h"

int	ft_find_next_prime(int nb, int *prime_list)
{
	time_exe(__func__, cl(clock()));
	int x;

  	x = 0;
  	if (nb <= 2)
	{
		time_exe(__func__, cl(clock()));
      return(2);
  	}
    if (nb == 3)
	{
		time_exe(__func__, cl(clock()));
      return (nb);
  }
  	while (nb <= 2147483647)
  	{
  		while (prime_list[x]!=0 && prime_list[x] <= nb / prime_list[x])
  		{
  			if (nb % prime_list[x] == 0)
  			{
//				if (++nb % 2 == 0)
  				nb++;
  				x = -1;
  			}
  			x++;
  		}
			time_exe(__func__, cl(clock()));
      return(nb); //nombre premier est int max
  	}
		time_exe(__func__, cl(clock()));
    return(0); //Nombre recherché superieur a int max
}

int   *initialize(int *prime_list, int limite)
{
  int i = 0;

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
	  	time_exe(__func__, cl(clock()));
	  exit (1);
      //return (NULL);
    }
  prime_list = initialize(prime_list, limite + 1);
  prime_list[compteur] = 2;

  while (compteur++ < limite)
	{
      prime_list[compteur] = ft_find_next_prime(prime_list[compteur - 1] + 1, prime_list);
			//printf("The %dth prime number is: %d\n", compteur + 1, prime_list[compteur]);
	}

  compteur = prime_list[compteur - 1];
  //free(prime_list);
  	time_exe(__func__, cl(clock()));
  return (compteur);
  //return (prime_list);
}

/*
void   loop(int limite)
{
	int lap = -1; //lap = Xth prime number first searched

  while (++lap < limite)
  {
//    printf("\nlap: %d/%d\n\n", lap, limite);
    if (limite - lap <= 1)
      printf("\t\t\tThe %dth prime number is: %d\n\n\n", lap + 1, find_n_prime(lap));
    else
        find_n_prime(lap);
  }
}
*/


int main()
{
  	int limite = 1000;	// stoping after founding X prime number
						// int max is the 105 097 564th prime number 105097564

//	printf("%d\n", i);
	time_exe(__func__, cl(clock()));
	printf("The %dth prime number is: %d\n", limite, find_n_prime(limite - 2));
//	loop(limite);

	print_time(time_exe(__func__, clock()));
	return (0);
}
