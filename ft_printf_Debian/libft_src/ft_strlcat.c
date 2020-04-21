/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:18:20 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/10 18:58:24 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lend;
	size_t lens;
	size_t len;
	size_t i;

	if (size == 0)
		return (ft_strlen(src));
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	len = lens + lend;
	i = 0;
	if (size < lend)
		len = (lens + size);
	if (size > lend)
	{
		while (src[i] && (lend + i) < (size - 1))
		{
			dst[lend + i] = src[i];
			i++;
		}
		dst[lend + i] = '\0';
		len = (lens + lend);
	}
	return (len);
}
