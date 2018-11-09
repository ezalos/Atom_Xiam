/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:15 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/09 17:38:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int     ft_open(const char *av)
{
    int file;

    if (-1 == (file = open(av, O_RDONLY)))
        return (ft_error("File can't be opened.\n"));
    return (file);
}
