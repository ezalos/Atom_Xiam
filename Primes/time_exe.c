/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/22 12:47:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*
time_exe(__func__, cl(clock()));
print_time(time_exe(__func__, clock()));
*/

void 	print_time_struct(t_time *g)
{
	printf(_RED"\tAdress:\t\t%p\n", (void *)g);
	printf(_CYAN "\t%s" _RESET, g->name);
	ft_puttab(g->name, 4);
	printf(_CYAN "Time: %f s.\n" _RESET, ((double)g->t));
 	printf("\tNEXT:\t\t%p\n" _RESET, (void*)g->next);
}

void	ft_puttab(const char *s, int separation)
{
	int tab;

	tab = ft_strlen(s);
//	if (tab % 4 != 0)
//		tab = (tab / 4) + 1;
//	else
		tab = tab / 4;
	while (separation - tab++ >= 0)
		printf("\t");
//		write(1, "\t", 1);
}

void	print_time(t_time *timee)
{
	t_time			*tmp;
	double		total;
	int				tab;

	total = 0;
	tmp = timee;
	while (tmp->next)
	{
		total += (double)tmp->t;
		tmp = tmp->next;
	}
	printf(_CYAN "Total time of program: %f\n" _RESET, (double)total);

	tmp = timee;
	while (tmp->next)
	{
		printf(_CYAN "\t%f%%\tfor %s" _RESET, (((double)tmp->t)/total) * 100, tmp->name);
		ft_puttab(tmp->name, 4);
		printf(_CYAN " in %f seconds\n" _RESET, ((double)tmp->t));
		printf("\t\t\t\tNb call: %d\tRelative Time: %f\n", tmp->nb_call, (double)(tmp->t/tmp->nb_call));
		tmp = tmp->next;
	}
}

double	cl(clock_t t)
{
	static double	origin;
	double m;

	if (!origin)
		origin = ((double)(clock()));
//	printf("cl%f\norigin%f\n", (double)t, (double)origin);
	m = ((double)(t - origin))/CLOCKS_PER_SEC;
	return (m);
	//origin = ((double)(clock()))/CLOCKS_PER_SEC;
}

static t_time	*time_link_creation(const char* s, double t)
{
	t_time	*timee;

	if(!(timee = (t_time*)malloc(sizeof(t_time))))
		return (NULL);
	timee->name = ft_strdup((const char*)s);
	timee->t = t;
	timee->nb_call = 1;
	timee->next = NULL;
//	print_time_struct(timee);
	return(timee);
}

static t_time	*time_exceptions( t_time **timee, const char* s, double t)
{
	if (s == NULL)
		return (NULL);
	else
	{
		*timee = time_link_creation(s, t);
		return (*timee);
	}
}

static int		update_time( t_time *timee, const char* s, double t)
{
	if (ft_strstr(s, timee->name))
	{
		timee->t = timee->t + t;
		timee->nb_call++;
		return (1);
	}
	return (0);
}

t_time	*time_exe(const char* s, double t)
{
	static t_time		*timee;
	t_time				*tmp;

	if (s == NULL || timee == NULL)
		return (time_exceptions(&timee, s, t));

//	printf("T=%f\n", t);
	if (update_time(timee, s, t))
		return (timee);
	tmp = timee;
	while (tmp->next != NULL)
	{
//		printf(_RESET"WHILE\n"_CYAN);
		print_time_struct(tmp);
		if (update_time(tmp, s, t))
			return (timee);
		tmp = tmp->next;
	}
	tmp->next = time_link_creation(s, t);
	return (timee);
}
