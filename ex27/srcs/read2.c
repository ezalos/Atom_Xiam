/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:13 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/09 16:12:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char    *ft_read(int file_descriptor)
{
    char   *reader;
    int     read_count;
    int     buffer;
    int     i;

    read_count = 0;
    buffer = sizeof(char) * 1000;
    if (!(reader = (char*)malloc(buffer + sizeof(char))))
        return (ft_p_error("Error during ORIGIN Malloc\n"));
    while  (read_count < (read_count += read(file_descriptor, reader, buffer)))
    {
        if (read_count < 0)
            return (ft_p_error("Error during file reading\n"));
        if (!(reader = (char*)malloc(buffer + sizeof(char))))
            return (ft_p_error("Error during 1st Malloc\n"));
        if (!(reader = (char*)malloc(buffer + sizeof(char))))
            return (ft_p_error("Error during 2nd Malloc\n"));
    }
    if (read_count != ft_strlen(reader))
        return (ft_p_error("Error : reading is missing part of file\n"));
    return (reader);
}
