/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 02:00:02 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/29 00:31:00 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nb_bits_x_p(unsigned long long value)
{
	unsigned long long	quotient;
	unsigned long long	tmp;
	int					c;

	c = 0;
	if (value == 0)
		return (1);
	quotient = value;
	while (quotient)
	{
		tmp = quotient % 16;
		c++;
		quotient = quotient / 16;
	}
	return (c);
}

void		ft_puthex_fd(int fd, unsigned long long value)
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
		ft_putchar_fd(fd, hexadecimal[i--]);
}

void		dot_present_p(unsigned long long p, int nb_bits, int special_case)
{
	if (g_opts.width <= 0 || g_opts.flag == 1)
	{
		ft_putstr_fd(1, "0x");
		if (!special_case)
			ft_puthex_fd(1, p);
		else if (p == 0 && g_opts.precision == 0 && p != 0)
			ft_putchar_fd(1, ' ');
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits - 2);
		if (p == 0 && g_opts.width < 0)
			ft_putchar_fd(1, ' ');
	}
	else if (g_opts.width >= 0 && g_opts.flag == -1)
	{
		ft_nb_putchar_fd(1, ' ',
		ft_vabs(g_opts.width) - nb_bits - 2 + special_case);
		ft_putstr_fd(1, "0x");
		if (!special_case)
			ft_puthex_fd(1, p);
	}
}

void		dot_not_present_p(unsigned long long p, int nb_bits)
{
	if (g_opts.width <= 0 || g_opts.flag == 1)
	{
		ft_putstr_fd(1, "0x");
		ft_puthex_fd(1, p);
		if (ft_vabs(g_opts.width) >= nb_bits + 2)
		{
			ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - nb_bits - 2);
		}
	}
	else if (g_opts.width >= 0 && g_opts.flag == -1)
	{
		ft_nb_putchar_fd(1, ' ', g_opts.width - nb_bits - 2);
		ft_putstr_fd(1, "0x");
		ft_puthex_fd(1, p);
	}
}

void		ft_conversion_p(void)
{
	unsigned long long	p;
	int					nb_bits;
	int					special_case;

	p = va_arg(g_ap, unsigned long long);
	special_case = ((g_opts.dot && !g_opts.precision && !p)
	? (1) : (0));
	nb_bits = ft_nb_bits_x_p(p);
	if (g_opts.dot)
	{
		dot_present_p(p, nb_bits, special_case);
	}
	else
		dot_not_present_p(p, nb_bits);
}
