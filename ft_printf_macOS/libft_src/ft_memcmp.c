/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:03:42 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/09 14:38:42 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (*((unsigned char*)s1) == *((unsigned char*)s2))
		{
			s1++;
			s2++;
			i++;
		}
		else
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
