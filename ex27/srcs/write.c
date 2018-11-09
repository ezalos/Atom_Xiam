/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:11 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/09 17:01:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    ft_puterror(char c)
{
    write(2, &c, 1);
}

int	    ft_error(char *str)
{
    while (*str)
        ft_puterror(*(str++));
    return (0);
}

char    *ft_p_error(char *str)
{
    while (*str)
        ft_puterror(*(str++));
    return (NULL);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*(str++));
}
