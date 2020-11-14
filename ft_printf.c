/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:01:35 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/23 19:09:43 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_toupper(int c)
{
	if (97 <= c && c <= 122)
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

int		ft_nb_bits(long long i)
{
	int				nb;
	int				r;
	unsigned long	q;

	q = 10;
	r = 1;
	if (i < 0)
	{
		nb = 2;
		i *= -1;
	}
	else
		nb = 1;
	while (1)
	{
		if ((i / q) == 0)
			break ;
		else
		{
			nb++;
			q *= 10;
		}
	}
	return (nb);
}

void	ft_init(void)
{
	g_opts.flag = -1;
	g_opts.width = 0;
	g_opts.w_src = 0;
	g_opts.dot = 0;
	g_opts.precision = 0;
	g_opts.p_src = 0;
	g_opts.conversion = 0;
}

void	redirection(void)
{
	if (g_opts.conversion == 'c')
		ft_conversion_c();
	else if (g_opts.conversion == 's')
		ft_conversion_s();
	else if (g_opts.conversion == 'd' || g_opts.conversion == 'i')
		ft_conversion_i_d();
	else if (g_opts.conversion == 'u')
		ft_conversion_u();
	else if (g_opts.conversion == '%')
		ft_conversion_prct();
	else if (g_opts.conversion == 'p')
		ft_conversion_p();
	else if (g_opts.conversion == 'x')
		ft_conversion_hex(0);
	else if (g_opts.conversion == 'X')
		ft_conversion_hex(1);
}

int		ft_printf(const char *format, ...)
{
	int		i;

	i = -1;
	g_nb_char = 0;
	va_start(g_ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar_fd(1, format[i]);
		else
		{
			if (format[i + 1] == '%')
			{
				ft_putchar_fd(1, '%');
				i++;
			}
			else
			{
				i = ft_manip(format, i);
			}
		}
	}
	va_end(g_ap);
	return (g_nb_char);
}
