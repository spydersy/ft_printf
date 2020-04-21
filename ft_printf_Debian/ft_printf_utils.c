/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:08:29 by abelarif          #+#    #+#             */
/*   Updated: 2020/04/10 00:18:58 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int ft_atoi(const char *str)
{
	long	res;
	int		nav;
	int		sign;

	nav = 0;
	sign = 1;
	res = 0;
	while (str[nav] == 32 || (str[nav] >= 9 && str[nav] <= 13 && str[nav]))
		nav++;
	if (str[nav] == '-')
	{
		sign = -1;
		nav++;
	}
	else if (str[nav] == '+')
		nav++;
	while (str[nav] >= '0' && str[nav] <= '9')
	{
		if (res < 0 && sign < 0)
			return (0);
		else if (res < 0 && sign > 0)
			return (-1);
		res = res * 10 + str[nav++] - '0';
	}
	return (res * sign);	
}

int		ft_vabs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

int		ft_isdigit_or_signe(int c)
{
	if ((c <= 57 && c >= 48) || (c == '-') || (c == '+'))
		return (1);
	else
		return (0);
}

int		ft_calcul_nbr(int nbr, unsigned long binf, unsigned long bsup)
{
	int	i;

	i = 1;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		i++;
		nbr = nbr * -1;
	}
	if (0 <= nbr && nbr <= 9)
		return (i);
	while (1)
	{
		if (binf <= (unsigned long)nbr && (unsigned long)nbr < bsup)
			return (i);
		else
		{
			binf = bsup;
			bsup *= 10;
			i++;
		}
	}
	return (i);
}

int		ft_calcul_nbr_u(unsigned int nbr, unsigned long binf, unsigned long bsup)
{
	int	i;

	i = 1;
	if (nbr <= 9)
		return (i);
	while (1)
	{
		if (binf <= (unsigned long)nbr && (unsigned long)nbr < bsup)
			return (i);
		else
		{
			binf = bsup;
			bsup *= 10;
			i++;
		}
	}
	return (i);
}

void	init_return_value(void)
{
	g_return_value = 0;
}

void	init_global(void)
{
	g_indexmin = 0;
	g_indexmax = 0;
	g_flag = -1;
	g_minfield = 0;
	g_period = 0;
	g_maxfield = 0;
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
