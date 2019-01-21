/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:12:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/21 11:35:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	*create_struct(char type, size_t size_struct, **init_func)
{
	void	*ptr;

	if (!(ptr = (void*)malloc(size_struct)))
		return (NULL);
	ptr = init_func[type](ptr);
	return (ptr);
}

void	*add_ver_in_edg(t_ver *v0, t_ver *v1)
{
	t_ver	**tmp;
	int		i;

	if (!(tmp = (t_ver**)malloc(sizeof(t_ver*) * ++(v0->edg->qlink))))
		return (NULL);
	i = -1;
	while (++i < v0->edg->qlink - 1)
		tmp[i] = v0->edg->ver[i];
	tmp[i] = v1;
	free(v0->edg->ver);
	v0->edg->ver = tmp;

	if (!(tmp = (t_ver**)malloc(sizeof(t_ver*) * ++(v1->edg->qlink))))
		return (NULL);
	i = -1;
	while (++i < v1->edg->qlink - 1)
		tmp[i] = v1->edg->ver[i];
	tmp[i] = v0;
	free(v1->edg->ver);
	v1->edg->ver = tmp;

	return (v0->edg->ver);
}

void	*link_vertices(t_ver *v0, t_ver **v, size_t size_tab)
{
	int		i;

	i = -1;
	while (++i < size_tab)
		if (!(add_ver_in_edg(v0, v[i])))
			return (NULL);
	return (v0);
}

int		main(int argc, char **av)
{

	return (0);
}
