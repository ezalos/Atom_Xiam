/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:52:19 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/23 03:34:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_exe.h"

/*
time_exe(__func__, cl(clock()));
print_time(time_exe(__func__, clock()));
*/

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (*(s1++) == *(s2++))
		if (*(s1 - 1) == '\0' || *(s2 - 1) == '\0')
			return (0);
	return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		size;

	size = ft_strlen(s);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dest[size] = '\0';
	i = -1;
	while (++i < size)
		dest[i] = s[i];
	return (dest);
}

int		ft_intlen(int n)
{
	int size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void 	print_time_struct(t_time *g)
{
	printf(_RED"\t\tAdress:\t\t%p\n", (void *)g);
	printf(_CYAN "\t%s" _RESET, g->name);
	ft_puttab(g->name, 4);
	printf(_CYAN "Time: %f s.\n" _RESET, ((double)g->t));
 	printf("\t\tNEXT:\t\t%p\n\n" _RESET, (void*)g->next);
}

void	ft_puttab_nb(int length, int separation)
{
	int n = 4; //is equal to 8 for windows
	int tab = 0;
	while (tab + length < separation * n)
	{
		printf(" ");
		tab++;
	}
}

void	ft_puttab(const char *s, int separation)
{
	int n = 4; //is equal to 8 for windows
	int tab = 0;
	int length = ft_strlen(s);
	int bb = 0;

	while (tab + length < separation * n)
	{
		printf(" ");
		tab++;
	}
}

void	print_time(t_time *timee)
{
	t_time		*tmp;
	double		total;
	int			max_length = 0;
	int			tab = 6;

	total = 0;
	tmp = timee;
	while (tmp)
	{
		total += (double)tmp->t;
		if (max_length < ft_strlen(tmp->name))
			max_length = (ft_strlen(tmp->name) / 4);
		tmp = tmp->next;
	}
	printf(_CYAN "\nTotal time of program: %f\n\n" _RESET, (double)total);

	tab = max_length + 4;
	tmp = timee;
	printf("\t________________________________________________________\n");
	while (tmp)
	{
		if (total != 0)
		{
			printf("\t");
				if ((int)(((tmp->t)/total) * 100) / 10 < 1)
					printf(" ");
			printf(_YELLOW "%d%%" _RESET, (int)(((tmp->t)/total) * 100));
		}
		else
			printf("\t");
		printf(_RED "\t%s" _RESET, tmp->name);
		ft_puttab(tmp->name, tab);
		printf(_MAGENTA "%f s\n" _RESET, ((double)tmp->t));
		printf(_GREEN "\t%dn" _RESET, tmp->nb_call);
		ft_puttab_nb(ft_intlen(tmp->nb_call), tab);
		printf(_CYAN "Rt:\t%f s/n\n" _RESET, (double)(tmp->t/tmp->nb_call));
		printf("\t________________________________________________________\n");
		tmp = tmp->next;
	}
}

double	cl(clock_t t)
{
	static double	origin;
	double m;

	if (!origin)
		origin = ((double)(clock()));
	m = ((double)(t - origin))/(CLOCKS_PER_SEC);
	return (m);
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

static t_time	*time_exceptions( t_time **timee, char **last, const char* s, double t)
{
	if (s == NULL)
		return (NULL);
	else
	{
		*last = ft_strdup((const char*)s);
		*timee = time_link_creation(s, t);
		return (*timee);
	}
}

static int		update_time(t_time *timee, const char* s, double t)
{
	if (!ft_strcmp(s, timee->name))
	{
		timee->t = timee->t + t;
		timee->nb_call++;
		return (1);
	}
	return (0);
}

t_time	*update_last(t_time *timee, char **last, const char* s)
{
	char* tmp;

	if (ft_strcmp(s, *last))
	{
		tmp = (char *)*last;
		*last = ft_strdup((const char*)s);
		free(tmp);
	}
	return (timee);
}

t_time	*time_exe(const char* s, double t)
{
	static t_time		*timee;
	static char			*last;
	t_time				*tmp;

	printf("last:%s\ns:%s\ntime %f\n", last, s, t);
	if (s == NULL || timee == NULL || last == NULL)
		return (time_exceptions(&timee, &last, s, t));
	if (update_time(timee, (const char*)last, t))
		return (update_last(timee, &last, s));
	tmp = timee;
	while (tmp->next != NULL)
	{
		if (update_time(tmp, (const char*)last, t))
			return (update_last(timee, &last, s));
		tmp = tmp->next;
	}
	if (update_time(tmp, (const char*)last, t))
		return (update_last(timee, &last, s));
	tmp->next = time_link_creation((const char*)last, t);
	return (update_last(timee, &last, s));
}
