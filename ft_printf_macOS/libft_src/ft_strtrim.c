/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:33:25 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/10 21:03:04 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		start;
	int		end;
	int		nav;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	nav = 0;
	while (check_set(s1[start], set))
		start++;
	while (check_set(s1[end - 1], set) && end > start)
		end--;
	strtrim = malloc((end - start + 1) * sizeof(char));
	if (!strtrim)
		return (NULL);
	while (nav < end - start)
	{
		strtrim[nav] = s1[nav + start];
		nav++;
	}
	strtrim[nav] = '\0';
	return (strtrim);
}
