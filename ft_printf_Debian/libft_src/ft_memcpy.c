/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:05:24 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/09 15:37:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char *s;

	d = dst;
	s = src;
	if (d == 0 && s == 0)
		return (0);
	while (n--)
		*d++ = *s++;
	return (dst);
}
