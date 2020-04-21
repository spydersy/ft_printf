/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:42:12 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/10 21:42:19 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		len_word(const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i++])
		len++;
	return (len);
}

static	size_t		count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (count);
}

void				*free_split(char **split, int k)
{
	while (k >= 0)
	{
		free(split[k]);
		k--;
	}
	free(split);
	split = NULL;
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**split;

	i = 0;
	k = 0;
	if (!s || !(split = (char **)malloc(sizeof(char *)
					* (count_word(s, c) + 1))))
		return (NULL);
	while (i < count_word(s, c))
	{
		if (!(split[i] = (char *)malloc(sizeof(char)
						* (len_word(&s[k], c) + 1))))
			return ((free_split(split, k - 1)));
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			split[i][j++] = s[k++];
		split[i][j] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}
