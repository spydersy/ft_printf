/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:19:11 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/20 12:30:24 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_puthex_upper_fd(int fd, unsigned long long value)
{
	unsigned long long	quotient;
	unsigned long long	tmp;
	char				hexadecimal[100];
	int					i;

	i = -1;
	quotient = value;
	while (quotient)
	{
		tmp = quotient % 16;
		if (tmp < 10)
			hexadecimal[++i] = 48 + tmp;
		else if (tmp >= 10)
			hexadecimal[++i] = 87 + tmp;
		quotient = quotient / 16;
	}
	hexadecimal[++i] = '\0';
	i--;
	if (value == 0)
		ft_putchar_fd(fd, '0');
	while (i >= 0)
		ft_putchar_fd(fd, ft_toupper(hexadecimal[i--]));
}

void		dot_not_present_hex(unsigned long long x, int nb_bits, int upper)
{
	if (g_opts.width <= 0 || g_opts.flag == 1)
	{
		((upper) ? (ft_puthex_upper_fd(1, x)) : (ft_puthex_fd(1, x)));
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits);
	}
	else if (g_opts.width >= 0 && g_opts.flag == -1)
	{
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits);
		((upper) ? (ft_puthex_upper_fd(1, x)) : (ft_puthex_fd(1, x)));
	}
	else if (g_opts.flag == 0)
	{
		ft_nb_putchar_fd(1, '0', g_opts.width - nb_bits);
		((upper) ? (ft_puthex_upper_fd(1, x)) : (ft_puthex_fd(1, x)));
	}
}

void		dot_present_hex(unsigned long long x, int nb_bits,
			int upper, int special_case)
{
	if (g_opts.width <= 0 || g_opts.flag == 1)
	{
		ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits);
		if (!special_case)
			((upper) ? (ft_puthex_upper_fd(1, x)) : (ft_puthex_fd(1, x)));
		ft_nb_putchar_fd(1, ' ',
		ft_vabs(g_opts.width)
		- ft_max_of(g_opts.precision, nb_bits) + special_case);
	}
	else if (g_opts.flag == -1 && g_opts.width >= 0)
	{
		ft_nb_putchar_fd(1, ' ',
		ft_vabs(g_opts.width)
		- ft_max_of(g_opts.precision, nb_bits) + special_case);
		ft_nb_putchar_fd(1, '0', g_opts.precision - nb_bits);
		if (!special_case)
			((upper) ? (ft_puthex_upper_fd(1, x)) : (ft_puthex_fd(1, x)));
	}
	else if (g_opts.flag == 0 && g_opts.width > 0)
	{
		flag_zero_hex(nb_bits, upper, x);
	}
}

void		ft_conversion_hex(int upper)
{
	unsigned long long		x;
	int						nb_bits;
	int						special_case;

	x = (unsigned long long)va_arg(g_ap, unsigned long long);
	nb_bits = ft_nb_bits_x_p(x);
	special_case = ((g_opts.dot && !g_opts.precision && !x)
	? (1) : (0));
	if (g_opts.dot == 0)
	{
		dot_not_present_hex(x, nb_bits, upper);
	}
	else
	{
		dot_present_hex(x, nb_bits, upper, special_case);
	}
}
