#include "struct.h"

t_neuron **ft_init(int *plan)
{
  t_neuron    **neural_network;
  t_neuron    *layer;
  int current_layer = 0;
  int current_neuron;
  int next_layer;
  int nb_layers = 0;
  double a = -10;
  double b = 10;

//  srand(time(NULL));
  while(plan[nb_layers])
    nb_layers++;
  printf("nb layers :%d\n", nb_layers);
  if(!(neural_network = (t_neuron **)malloc(nb_layers * sizeof(layer))))
    return NULL;
  while (current_layer < nb_layers)
  {
    printf("Creation of the layer[%d] with %d neurons \n",
      current_layer, plan[current_layer]);
    if(!(neural_network[current_layer]
      = (t_neuron *)malloc(plan[current_layer] * sizeof(t_neuron))))
      return NULL;

    current_neuron = 0;
      while (current_neuron < plan[current_layer])
      {
        neural_network[current_layer][current_neuron].data
          = rand()/(double)RAND_MAX;
        neural_network[current_layer][current_neuron].bias = 0;
        next_layer = 0;
        if (current_layer + 1 < nb_layers)
        {
          if(!(neural_network[current_layer][current_neuron].tab_coef
            = (double *)malloc(sizeof(double) * plan[current_layer + 1])))
            return NULL;
        while (next_layer < plan[current_layer + 1])
        {
          neural_network[current_layer][current_neuron].tab_coef[next_layer]
            = (rand()/(double)RAND_MAX) * (b-a) + a;
          next_layer++;
        }
        }
        current_neuron++;
      }

    current_layer++;
  }
  return (neural_network);
}


/*int main() {
  int c, n;

  double frand_a_b(double a, double b){
     return ( rand()/(double)RAND_MAX ) * (b-a) + a
 }
  printf("Ten random numbers in [1,100]\n");

  for (c = 1; c <= 10; c++) {
    n = rand() % 100 + 1;
    printf("%d\n", n);
  }

  return 0;
}*/





/*
typedef struct    s_neuron
{
  double          data;
  double          *tab_coef;
  double          bias;
}                 t_neuron;
 */
