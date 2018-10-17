#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>
# include <stdio.h>
# include <time.h>  // sert a donner le temps pour generer les nombres aléatoires

typedef struct    s_neuron
{
  double          data;
  double          *tab_coef;
  double          bias;
}                 t_neuron;

typedef struct    s_picture
{
  int             actual_data;
  int             magic_number;
  FILE            *fptr;
  double          *tab_values;
}                 t_picture;

void ft_print_all(t_neuron **list, int plan[5]);
t_neuron **ft_init(int *plan);

#endif
