/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:11:08 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/11 21:10:13 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_nbr_hexa(unsigned int	nbr_hexa)
{
	long	quotient;
	long	tmp;
	int		c;

	c = 0;
	quotient = nbr_hexa;
	while (quotient)
	{
		tmp = quotient % 16;
		if (tmp < 10)
			c++;
		else
			c++;
		quotient = quotient / 16;
	}
	return (c);
}

void		ft_putchar_hexa(unsigned int	nbr_hexa)
{
	long	quotient;
	long	tmp;
	char	hexadecimal[100];
	int		i;

	i = -1;
	quotient = nbr_hexa;
	while (quotient)
	{
		tmp = quotient % 16;
		if (tmp < 10)
			hexadecimal[++i] = 48 + tmp;
		else if (tmp >= 10 && g_argument == 'x')
			hexadecimal[++i] = 87 + tmp;
		else if (tmp >= 10 && g_argument == 'X')
			hexadecimal[++i] = 55 + tmp;
		quotient = quotient / 16;
	}
	hexadecimal[++i] = '\0';
	i--;
	if (nbr_hexa == 0)
		ft_putchar('0');
	while (i >= 0)
		ft_putchar(hexadecimal[i--]);

}

void	ft_hexa_argument_noperiod(unsigned int	nbr_hexa, int nbr_char, int special)
{
	(nbr_hexa == 0) ? (nbr_char += 1) : (nbr_char += 0);
	if (g_flag == 1)
	{
		if (!special)
			ft_putchar_hexa(nbr_hexa);
		ft_putchar_while(' ', g_minfield - nbr_char + special);
	}
	else if (g_flag == 0 || g_flag == -1)
	{
		if (g_flag == 0)
			ft_putchar_while('0', g_minfield - nbr_char);
		else if (g_flag == -1)
			ft_putchar_while(' ', g_minfield - nbr_char + special);
		if (!special)
			ft_putchar_hexa(nbr_hexa);
	}
}

void	ft_hexa_argument_period(unsigned nbr_hexa, int nbr_char, int special)
{
	(nbr_hexa == 0) ? (nbr_char += 1) : (nbr_char += 0);
	if (g_minfield <= g_maxfield)
	{
		ft_putchar_while('0', g_maxfield - nbr_char);
		if (!special)
			ft_putchar_hexa(nbr_hexa);
	}
	else
	{
		if (g_flag == 1)
		{
			ft_putchar_while('0', g_maxfield - nbr_char);
			if (!special)
				ft_putchar_hexa(nbr_hexa);
			ft_putchar_while(' ', g_minfield - ft_max_of(g_maxfield, nbr_char) + special);
		}
		else if (g_flag == 0 || g_flag == -1)
		{
			ft_putchar_while(' ', g_minfield - ft_max_of(g_maxfield, nbr_char) + special);
			ft_putchar_while('0', g_maxfield - nbr_char);
			if (!special)
				ft_putchar_hexa(nbr_hexa);
		}
	}
}

void	ft_hexa_argument(void)
{
	unsigned int    nbr_hexa;
	int             nbr_char;
	int				special;
	nbr_hexa = va_arg(g_ap, unsigned int);
	(!nbr_hexa && g_period && !g_maxfield) ? (special = 1) : (special = 0);
	nbr_char = ft_nbr_hexa(nbr_hexa);
	if (!g_period)
		ft_hexa_argument_noperiod(nbr_hexa, nbr_char, special);
    else
        ft_hexa_argument_period(nbr_hexa, nbr_char, special);
}
