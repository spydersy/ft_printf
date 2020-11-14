/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:58:59 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/30 00:48:57 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flag(const char *format, int i)
{
	if (format[i] == '0' && format[i + 1] != '-')
	{
		g_opts.flag = 0;
		while (format[i] == '0')
			i++;
	}
	else if (format[i] == '-')
	{
		g_opts.flag = 1;
		while (format[i] == '-')
			i++;
	}
	return (i);
}

int		get_width(const char *format, int i)
{
	if (ft_isdigit(format[i]))
	{
		g_opts.width = ft_atoi(format + i);
		i = ft_skip_digit(format, i);
	}
	else if (format[i] == '*')
	{
		g_opts.width = va_arg(g_ap, int);
		g_opts.w_src = 1;
		i++;
	}
	return (i);
}

int		get_precision(const char *format, int i)
{
	if (format[i] == '.')
	{
		g_opts.dot = 1;
		if (ft_isdigit(format[++i]))
		{
			g_opts.precision = ft_atoi(format + i);
			i = ft_skip_digit(format, i);
		}
		else if (format[i] == '*')
		{
			g_opts.precision = va_arg(g_ap, int);
			g_opts.p_src = 1;
			i++;
		}
	}
	return (i);
}

int		get_conversion(const char *format, int i)
{
	g_opts.conversion = format[i];
	return (i++);
}

int		ft_manip(const char *format, int i)
{
	ft_init();
	i++;
	while (format[i] && format[i] == ' ')
		i++;
	i = get_flag(format, i);
	i = get_width(format, i);
	i = get_precision(format, i);
	i = get_conversion(format, i);
	redirection();
	return (i);
}
