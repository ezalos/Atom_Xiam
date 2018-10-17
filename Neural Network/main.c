#include "struct.h"

int main(int argc, char const *argv[])
{
  t_neuron  **neural_network; //here is created a list of layers, which individually contains all the neurons(t_neuron) of this layer.
  int       plan[5] = {28/**28*/, 16, 16, 10, 0}; //Number of neurons for each layer. Need to be finished by 0

  if(!(neural_network = ft_init(plan))) // need to be double checked.
    return 0;

  ft_run()

  ft_print_all(neural_network, plan);

//free malloc

  return 0;
}
