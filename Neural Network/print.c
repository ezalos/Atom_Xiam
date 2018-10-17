#include "struct.h"

void ft_print_all(t_neuron **list, int plan[5])
{
  int i = 0;
  int j;
  int k;

  while (plan[i]!=0)
  {
    printf("\n_________________\nLayer %d\n_________________\n", i);
    j = 0;
    while (j<plan[i])
    {
        printf("\n\tNeuron(%d)\t = %lg\n", j, list[i][j].data);
        k = -1;
        if (plan[i + 1] != 0)
          while (++k < plan[i+1])
          if (list[i][j].tab_coef[k]>0)
            printf("\t\tCoeff to Neuron %d\t= %lg\n", k, list[i][j].tab_coef[k]);
          else
            printf("\t\tCoeff to Neuron %d\t=%lg\n", k, list[i][j].tab_coef[k]);
        j++;
    }
    i++;
    printf("\n");
  }
}
