/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:57:28 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/09 14:39:48 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*if_neg(long j)
{
	int		i;
	long	c;
	char	*dest;

	j = -j;
	c = j;
	i = 1;
	while (c / 10 != 0)
	{
		c = c / 10;
		i++;
	}
	dest = (char*)malloc(sizeof(char ) * (i + 2));
	if (dest == NULL)
		return (NULL);
	i++;
	dest[i] = '\0';
	while (j > 0)
	{
		i--;
		dest[i] = j % 10 + 48;
		j = j / 10;
	}
	dest[--i] = '-';
	return (dest);
}

char	*if_zero(long j)
{
	char *dest;

	j = 0;
	dest = (char*)malloc(sizeof(char) * 2);
	if (dest == NULL)
		return (NULL);
	dest[j] = '0';
	dest[++j] = '\0';
	return (dest);
}

char	*if_pos(long j)
{
	int		i;
	long	c;
	char	*dest;

	c = j;
	i = 1;
	while (c / 10 != 0)
	{
		c = c / 10;
		i++;
	}
	dest = (char*)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	dest[i] = '\0';
	while (j > 0)
	{
		i--;
		dest[i] = j % 10 + 48;
		j = j / 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	long	j;
	char	*a;

	j = (long)n;
	if (j == 0)
		a = if_zero(j);
	else if (j < 0)
		a = if_neg(j);
	else
		a = if_pos(j);
	return (a);
}
