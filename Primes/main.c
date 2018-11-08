#include "header.c"

int main()
{
	clock_t t = clock();
	double time_taken;
  int limite = 105097564;	// stoping after founding X prime number
											// int max is the 105 097 564th prime number 105097564

	printf("The %dth prime number is: %d\n", limite, find_n_prime(limite - 1));
//	loop(limite);

	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("Prime_finder took %f seconds to execute \n\n", time_taken);

  return (0);
}
