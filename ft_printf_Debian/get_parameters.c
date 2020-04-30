/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:27:05 by abelarif          #+#    #+#             */
/*   Updated: 2020/04/29 22:30:35 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkpercent(const char *format)
{
	int i;
	int	j;
	int nb_print_percent;

	i = 0;
	j = 0;
	while (format[i] == '%')
	{
		j++;
		i++;
	}
	nb_print_percent = j / 2;
	while (nb_print_percent)
	{
		ft_putchar('%');
		nb_print_percent--;
	}
	if (j % 2 == 1)
	{
		i += ft_check_after_percent(format + i);
	}
	return (i);
}

int		ft_check_after_percent(const char *format)
{
	int i;

	i = 0;
	i += ft_checkflags(format + i);
	while (format[i] == '-')
		i++;
	i += ft_checkminfield(format + i);
	i += ft_checkperiod_maxfield(format + i);
	i += ft_checkargument(format + i);
	return (i);
}

int		ft_checkflags(const char *format)
{
	int i;

	i = 0;
	if (format[i] == '0')
	{
		g_flag = 0;
		i++;
		return (i);
	}
	else if (format[i] == '-')
	{
		g_flag = 1;
		i++;
		return (i);
	}
	else
	{
		g_flag = -1;
		return (i);
	}
}

int		ft_checkminfield(const char *format)
{
	int i;

	i = 0;
	if ((format[i] == '*') || ft_isdigit_or_signe(format[i]))
	{
		if (('0' <= format[i] && format[i] <= '9') || (format[i] == '-'))
		{
			g_minfield = ft_atoi(format);
			while (('0' <= format[i] && format[i] <= '9') || format[i] == '-')
				i++;
			return (i);
		}
		else
		{
			g_indexmin = 10;
			g_minfield = va_arg(g_ap, int);
			if (g_minfield < 0 )
			{
				g_indexmin++;
				g_minfield *= -1;
				g_flag = 1;
			}
			i++;
			return (i);
		}
	}
	else
		g_minfield = 0;
	return (i);
}

int		ft_checkperiod_maxfield(const char *format)
{
	int i;

	i = 0;
	if (format[i] == '.')
	{
		g_period = 1;
		i++;
		i += ft_checkmaxfield(format + i);
		return (i);
	}
	return (i);
}
