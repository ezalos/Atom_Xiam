/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:13:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/20 17:12:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct			s_vertice
{
	char				*name;
	char				**attributes;
	struct s_edge		*edg;
}						t_ver;

typedef struct			s_edge
{
	int					qlink;
	char				**attributes;
	struct s_vertice	**ver;
}						t_edg;

typedef struct			s_omni
{
	struct s_vertice	*ver;
	int					qver;
	int					qvat;
	struct s_edge		*edg;
	int					qedg;
	int					qeat;
}						t_edg;
