/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_i_d_u_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:28:16 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/30 01:52:51 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero_u(unsigned int u, int nb_bits)
{
	if (!u && !g_opts.precision)
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width));
	else if (!u && g_opts.precision)
	{
		if (g_opts.precision > 0)
			ft_nb_putchar_fd(1, ' ',
			g_opts.width - ft_max_of(nb_bits, g_opts.precision));
		if (g_opts.precision < 0)
			g_opts.precision = g_opts.width;
		ft_nb_putchar_fd(1, '0', ft_max_of(nb_bits, g_opts.precision));
	}
	else if (u)
	{
		if (g_opts.precision >= 0)
		{
			ft_nb_putchar_fd(1, ' ',
			g_opts.width - ft_max_of(g_opts.precision, nb_bits));
			ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits);
		}
		else
			ft_nb_putchar_fd(1, '0', g_opts.width - nb_bits);
		ft_putnbr_fd(1, u);
	}
}

void	flag_zero_i_d(int i, int neg, int nb_bits)
{
	if (g_opts.precision > 0)
		ft_nb_putchar_fd(1, ' ',
		g_opts.width - ft_max_of(nb_bits, g_opts.precision + neg));
	if (neg)
		ft_putchar_fd(1, '-');
	ft_nb_putchar_fd(1, '0',
	((g_opts.precision > 0)
	? (g_opts.precision - nb_bits + neg) : (g_opts.width - nb_bits)));
	ft_putnbr_fd(1, ft_vabs(i));
}

void	flag_zero_hex(int nb_bits, int upper, unsigned long long x)
{
	if (g_opts.precision < 0)
	{
		ft_nb_putchar_fd(1, '0', g_opts.width - nb_bits);
		((upper) ? (ft_puthex_upper_fd(1, x)) : (ft_puthex_fd(1, x)));
	}
	else
	{
		ft_nb_putchar_fd(1, ' ',
		g_opts.width - ft_max_of(g_opts.precision, nb_bits));
		ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits);
		if (x != 0)
		{
			((upper) ? (ft_puthex_upper_fd(1, x)) : (ft_puthex_fd(1, x)));
		}
		else if (g_opts.precision == 0 && x == 0)
			ft_putchar_fd(1, ' ');
		else
			ft_puthex_fd(1, x);
	}
}
