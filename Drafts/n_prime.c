#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	ft_find_next_prime2(int nb, int **prime_list, int last_prime_xth)
{
	int boolean;
	int prime_xth = 1;
	int run_counts;

//	printf("Coucou");
	while (prime_xth <= last_prime_xth) //Search of prime number until the Xth
	{
//		printf("Prime actual : %d\t Total :%d\n", prime_xth, last_prime_xth);
		run_counts = 0;
		boolean = 0;
		nb++;
		while (run_counts < prime_xth) //Increment all the counters, that already had their number appear
		{
			prime_list[run_counts][1]++;
			if (prime_list[run_counts][0] == prime_list[run_counts][1])
			{
				prime_list[run_counts][1] = 0;  //each counter is in base of his own Prime
				boolean++;
			}
			run_counts++;
		}
		if (boolean == 0) //If none of the counter got "a new digit"(it's an hidden division), we have a prime
		{
			prime_list[prime_xth++][0] = nb;
//			printf("Prime :%d\n", prime_list[prime_xth - 1][0]);
		}
	}

	return (prime_list[prime_xth - 1][0]);

}

int   find_n_prime2(int last_prime_xth)
{
	int solution = 0;
	int compteur = 0;
  int **prime_list;

//  printf("\tMalloc of: int * (%d + 1)\n", last_prime_xth);
  if(!(prime_list = (int**)malloc((last_prime_xth + 2) * sizeof(int*)))) //PROBLEM ?
    {
      printf("\tMALLOC 1 A ECHOUE\n");
      exit (1);
    }

		while (compteur < last_prime_xth + 1)
		{
			if(!(prime_list[compteur] = (int*)malloc(2 * sizeof(int)))) //PROBLEM ?
				{
					printf("\tMALLOC 2 A ECHOUE\n");
					exit (1);
				}
//				  printf("\tMalloc[%d] Done !\n", compteur);
				  prime_list[compteur][0] = 0;
					prime_list[compteur][1] = 0;
//				 	printf("\t\tPrime list Initialized at 0\n");
					compteur++;
		}

  prime_list[0][0] = 2;
	compteur = 0;
//	printf("Inchallah?\n");
  solution = ft_find_next_prime2(2, prime_list, last_prime_xth);
//	printf("Inchallah!\n");
	while (compteur <= last_prime_xth + 1)
  	free(prime_list[compteur++]);  //PROBLEM ?
	free(prime_list);
  return (solution);
}

void   loop2(int limite)
{
	int lap = -1; //lap = Xth prime number first searched

  while (++lap < limite)
  {
    printf("\nlap : %d <= %d limite\n\n", lap, limite);
    if (limite - lap <= 51)
      printf("\t\t\t%deme -> %d\n\n", lap + 1, find_n_prime2(lap));
    else
        find_n_prime2(lap);
  }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int	ft_find_next_prime(int nb, int *prime_list)
{
	int x;

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
					if (++nb % 2 == 0)
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

  while(i<=limite)
    prime_list[i++]=0;
  return(prime_list);
}

int   find_n_prime(int limite)
{
	int compteur = 0;
  int *prime_list = NULL;

//  printf("\tMalloc of: int * (%d + 1)\n", limite);
  if(!(prime_list = (int*)malloc((limite + 2) * sizeof(int)))) //PROBLEM ?
    {
      printf("\tMALLOC A ECHOUE\n");
      exit (1);
    }
//  printf("\tMalloc Done !\n");
  prime_list = initialize(prime_list, limite + 1);
//  printf("\t\tPrime list Initialized at 0\n");

  prime_list[compteur] = 2;

  while (compteur++ < limite)
	{
      prime_list[compteur] = ft_find_next_prime(prime_list[compteur - 1] + 1, prime_list);
//			printf("\t\t\t%deme -> %d\n", compteur, prime_list[compteur - 1]);
	}

  compteur = prime_list[compteur - 1];
  free(prime_list);  //PROBLEM ?
  return (compteur);
}

void   loop(int limite)
{
	int lap = -1; //lap = Xth prime number first searched

  while (++lap < limite)
  {
//    printf("\nlap : %d <= %d limite\n\n", lap, limite);
    if (limite - lap <= 51)
      printf("\t\t\t%deme -> %d\n\n", lap + 1, find_n_prime(lap));
    else
        find_n_prime(lap);
  }
}

int main()
{
  int limite = 20; // stoping after founding X prime number || int max is the 105 097 564th prime number 105097564
	clock_t t;
	t = clock();

	loop2(limite);
  printf("%deme -> %d\n", limite, find_n_prime2(limite));


	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

	printf("Prime_finder2 took %f seconds to execute \n\n", time_taken);
	/*
	t = clock();

	loop(limite);
//  printf("%deme -> %d\n", limite, find_n_prime(limite));


	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

	printf("Prime_finder took %f seconds to execute \n\n", time_taken);
*/
  return (0);
}
