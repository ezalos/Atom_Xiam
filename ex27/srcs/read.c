/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:13 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/09 17:12:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int    ft_read(int file_descriptor, char reader[1000])
{
    int     buffer;

    buffer = 1000 * sizeof(char);
    if  (!(0 < read(file_descriptor, reader, buffer)))
        return (ft_error("Error during reading process\n"));
    return (1);
}
