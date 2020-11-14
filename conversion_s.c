/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:51:36 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/20 11:00:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_s(int len)
{
	if ((g_opts.p_src == 1 && g_opts.precision < 0)
	|| g_opts.precision > len)
	{
		g_opts.precision = len;
	}
}

void	dot_present_s(char *s)
{
	if (g_opts.flag == 1 || g_opts.width < 0)
	{
		ft_nb_putstr_fd(1, s, ft_vabs(g_opts.precision));
		ft_nb_putchar_fd(1, ' ',
		ft_vabs(g_opts.width) - ft_vabs(g_opts.precision));
	}
	else
	{
		ft_nb_putchar_fd(1, ' ',
		ft_vabs(g_opts.width) - ft_vabs(g_opts.precision));
		ft_nb_putstr_fd(1, s, ft_vabs(g_opts.precision));
	}
}

void	dot_not_present_s(char *s)
{
	if (g_opts.flag == 1 || g_opts.width < 0)
	{
		ft_putstr_fd(1, s);
		ft_nb_putchar_fd(1, ' ',
		ft_vabs(g_opts.width) - ft_strlen(s));
	}
	else
	{
		ft_nb_putchar_fd(1, ' ', g_opts.width - ft_strlen(s));
		ft_putstr_fd(1, s);
	}
}

void	ft_conversion_s(void)
{
	char	*s;

	s = va_arg(g_ap, char*);
	if (s == NULL)
		s = "(null)";
	ft_init_s(ft_strlen(s));
	if (g_opts.dot)
	{
		dot_present_s(s);
	}
	else
	{
		dot_not_present_s(s);
	}
}
