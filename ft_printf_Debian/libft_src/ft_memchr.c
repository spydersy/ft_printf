/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:02:26 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/10 18:03:37 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	l;
	size_t			i;

	i = 0;
	l = (unsigned char)c;
	src = (unsigned char*)s;
	while (i < n)
	{
		if (*src == l)
			return (src);
		src++;
		i++;
	}
	return (0);
}
