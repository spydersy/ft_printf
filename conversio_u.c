/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversio_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:14:59 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/25 16:53:08 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_u(int nb_bits)
{
	if (g_opts.precision < 0 || g_opts.precision < nb_bits)
	{
		g_opts.precision = nb_bits;
	}
}

int		ft_max_of(int i, int j)
{
	return (((i < j) ? (j) : (i)));
}

void	dot_not_present_u(unsigned int u, int nb_bits)
{
	if (g_opts.width >= 0 && g_opts.flag == -1)
	{
		ft_nb_putchar_fd(1, ' ', g_opts.width - nb_bits);
		ft_putnbr_fd(1, u);
	}
	else if (g_opts.width <= 0 || g_opts.flag == 1)
	{
		ft_putnbr_fd(1, u);
		if (ft_vabs(g_opts.width) > nb_bits)
			ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits);
	}
	else if (g_opts.flag == 0)
	{
		if (g_opts.width >= nb_bits)
			ft_nb_putchar_fd(1, '0', g_opts.width - nb_bits);
		ft_putnbr_fd(1, u);
	}
}

void	dot_present_u(unsigned int u, int nb_bits)
{
	if (!g_opts.flag && g_opts.width > 0)
		flag_zero_u(u, nb_bits);
	else if (g_opts.width <= 0 || g_opts.flag == 1)
	{
		if (g_opts.precision == 0 && u == 0)
			ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width));
		else
		{
			ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits);
			ft_putnbr_fd(1, u);
			ft_nb_putchar_fd(1, ' ',
			ft_vabs(g_opts.width) - ft_max_of(g_opts.precision, nb_bits));
		}
	}
	else if (g_opts.width >= 0 && g_opts.flag == -1)
	{
		ft_nb_putchar_fd(1, ' ',
		g_opts.width - ft_max_of(g_opts.precision, nb_bits));
		if (g_opts.precision >= nb_bits)
			ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits);
		if (u == 0 && g_opts.precision == 0)
			ft_putchar_fd(1, ' ');
		else
			ft_putnbr_fd(1, u);
	}
}

void	ft_conversion_u(void)
{
	unsigned int		u;
	int					nb_bits;

	u = (unsigned int)va_arg(g_ap, unsigned int);
	nb_bits = ft_nb_bits(u);
	if (g_opts.dot == 0)
	{
		dot_not_present_u(u, nb_bits);
	}
	else
	{
		dot_present_u(u, nb_bits);
	}
}
