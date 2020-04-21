/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:35:15 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/09 14:36:05 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;
	int		starti;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen(s))
	{
		if (!(p = malloc(1 * sizeof(char))))
			return (0);
		p[0] = '\0';
		return (p);
	}
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	starti = start;
	while (start < (unsigned int)len + starti && s[start])
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
