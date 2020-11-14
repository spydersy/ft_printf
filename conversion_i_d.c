/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_i_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:54:38 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/30 01:53:12 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_init_i_d(int nb_bits)
{
	if ((g_opts.p_src == 1 && g_opts.precision <= 0)
	|| (0 < g_opts.precision && g_opts.precision < nb_bits)
	|| (g_opts.dot == 1 && g_opts.precision == 0))
	{
		g_opts.precision = nb_bits;
	}
}

void	no_flag_i_d(int i, int neg, int nb_bits)
{
	int		index;

	index = 0;
	if (g_opts.precision == nb_bits && neg)
	{
		ft_nb_putchar_fd(1, ' ', g_opts.width - g_opts.precision - neg);
		ft_putchar_fd(1, '-');
		ft_nb_putchar_fd(1, '0', neg);
		index = 1;
	}
	ft_init_i_d(nb_bits);
	if (ft_vabs(g_opts.width) >= (g_opts.precision) && !index)
	{
		if (g_opts.precision > nb_bits && neg)
			ft_nb_putchar_fd(1, ' ', g_opts.width - g_opts.precision - neg);
		else
			ft_nb_putchar_fd(1, ' ', g_opts.width - g_opts.precision);
	}
	if (neg && !index)
		ft_putchar_fd(1, '-');
	g_opts.precision += ((index) ? (-1) : (0));
	if (g_opts.precision > nb_bits)
		ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits + neg);
	ft_putnbr_fd(1, ft_vabs(i));
}

void	dot_present_i_d(int i, int neg, int nb_bits)
{
	if (g_opts.flag == 1 || g_opts.width < 0)
	{
		ft_init_i_d(nb_bits);
		if (neg)
			ft_putchar_fd(1, '-');
		if (g_opts.precision > nb_bits)
			ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits + neg);
		ft_putnbr_fd(1, ft_vabs(i));
		if (ft_vabs(g_opts.width) >= (neg + g_opts.precision))
		{
			if (i < 0 && g_opts.precision > nb_bits)
				g_opts.precision += 1;
			ft_nb_putchar_fd(1, ' ',
			ft_vabs(g_opts.width) - g_opts.precision);
		}
	}
	else if (g_opts.flag == 0 && g_opts.width > 0)
	{
		flag_zero_i_d(i, neg, nb_bits);
	}
	else
	{
		no_flag_i_d(i, neg, nb_bits);
	}
}

void	dot_not_present_i_d(int i, int neg, int nb_bits)
{
	if (g_opts.flag == 0 && g_opts.width > 0)
	{
		if (neg)
			ft_putchar_fd(1, '-');
		if (g_opts.width > nb_bits)
			ft_nb_putchar_fd(1, '0', g_opts.width - nb_bits);
		ft_putnbr_fd(1, ft_vabs(i));
	}
	else if (g_opts.w_src && g_opts.width < 0)
	{
		ft_putnbr_fd(1, i);
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits);
	}
	else if (g_opts.flag == 1 || g_opts.width <= 0)
	{
		ft_putnbr_fd(1, i);
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits);
	}
	else if (g_opts.flag == -1 && g_opts.width > 0)
	{
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits);
		ft_putnbr_fd(1, i);
	}
}

int		ft_conversion_i_d(void)
{
	int		i;
	int		nb_bits;
	int		neg;

	i = va_arg(g_ap, int);
	nb_bits = ft_nb_bits(i);
	if (g_opts.precision == 0 && i == 0 && g_opts.dot)
	{
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width));
		return (0);
	}
	neg = ((i < 0) ? (1) : (0));
	if (g_opts.dot)
		dot_present_i_d(i, neg, nb_bits);
	else
		dot_not_present_i_d(i, neg, nb_bits);
	return (0);
}
