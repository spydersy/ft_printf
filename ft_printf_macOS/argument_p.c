/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:43:02 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/11 21:03:07 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nbr_ptr(unsigned long long	value)
{
	unsigned long long	quotient;
	unsigned long long	tmp;
	int		c;

	c = 0;
	quotient = value;
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

void		ft_putchar_hexa_ptr(unsigned long long	value)
{
	unsigned long long	quotient;
	unsigned long long	tmp;
	char	hexadecimal[100];
	int		i;

	i = -1;
	quotient = value;
	while (quotient)
	{
		tmp = quotient % 16;
		if (tmp < 10)
			hexadecimal[++i] = 48 + tmp;
		else if (tmp >= 10 )
			hexadecimal[++i] = 87 + tmp;
		quotient = quotient / 16;
	}
	hexadecimal[++i] = '\0';
	i--;
	if (value == 0)
		ft_putchar('0');
	while (i >= 0)
		ft_putchar(hexadecimal[i--]);
}

void	ft_ptr_argument_noperiod(unsigned long long	value, int nbr_char, int special)
{
	(value == 0) ? (nbr_char += 1) : (nbr_char += 0);
	if (g_flag == 1)
	{
		ft_putstr("0x");
		if (!special)
			ft_putchar_hexa_ptr(value);
		ft_putchar_while(' ', g_minfield - nbr_char - 2);
	}
	else if (g_flag == 0 || g_flag == -1)
	{
		if (g_flag == 0)
		{
			ft_putstr("0x");
			ft_putchar_while('0', g_minfield - nbr_char -2);
		}
		else if (g_flag == -1)
		{
			ft_putchar_while(' ', g_minfield - nbr_char - 2);
			ft_putstr("0x");
		}
		if (!special)
			ft_putchar_hexa_ptr(value);
	}
}

int	ft_max_of(int var1, int var2)
{
	return ((var1 > var2) ? (var1) : (var2)); 
}

void	ft_ptr_argument_period(unsigned long long value, int nbr_char, int special)
{
	(value == 0) ? (nbr_char += 1) : (nbr_char += 0);
	if (g_minfield <= g_maxfield)
	{
		ft_putstr("0x");
		ft_putchar_while('0', g_maxfield - nbr_char - 2);
		if (!special)
			ft_putchar_hexa_ptr(value);
	}
	else
	{
		if (g_flag == 1)
		{
			ft_putstr("0x");
			ft_putchar_while('0', g_maxfield - nbr_char);
			if (!special)
				ft_putchar_hexa_ptr(value);
			ft_putchar_while(' ', g_minfield - ft_max_of(g_maxfield, nbr_char) - 2 + special);
		}
		else if (g_flag == 0 || g_flag == -1)
		{
			ft_putchar_while(' ', g_minfield - ft_max_of(g_maxfield, nbr_char) - 2 + special);
			ft_putstr("0x");
			ft_putchar_while('0', g_maxfield - nbr_char);
			if (!special)
				ft_putchar_hexa_ptr(value);
		}
	}
}

void	ft_p_argument(void)
{
	unsigned long long    value;
	int             	nbr_char;
	int					special;
	value = va_arg(g_ap, unsigned long long);
	(!value && g_period && !g_maxfield) ? (special = 1) : (special = 0);
	nbr_char = ft_nbr_ptr(value);
	if (!g_period)
		ft_ptr_argument_noperiod(value, nbr_char, special);
    else
        ft_ptr_argument_period(value, nbr_char, special);
}