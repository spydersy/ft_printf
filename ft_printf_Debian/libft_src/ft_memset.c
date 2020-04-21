/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:07:42 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/09 13:08:23 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	l;
	unsigned long	i;

	i = 0;
	p = b;
	l = c;
	while (i < len)
	{
		p[i] = l;
		i++;
	}
	return (p);
}
