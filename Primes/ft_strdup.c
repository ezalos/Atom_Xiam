/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:48 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/22 12:33:53 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
size_t		ft_strlen(const char *s);

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
