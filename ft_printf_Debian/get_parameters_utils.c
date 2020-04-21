/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:01:23 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/12 20:46:46 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkmaxfield(const char *format)
{
	int i;

	i = 0;
	if ((format[i] == '*') || ft_isdigit_or_signe(format[i]))
	{
		if (('0' <= format[i] && format[i] <= '9') || (format[i] == '-'))
		{
			g_maxfield = ft_atoi(format);
			while ('0' <= format[i] && format[i] <= '9')
				i++;
			return (i);
		}
		else
		{
			g_indexmax = 1;
			g_maxfield = va_arg(g_ap, int);
			(g_maxfield < 0) ? (g_indexmax = 11) : (g_indexmax = 10);
			i++;
			return (i);
		}
	}
	else
	{
		g_maxfield = 0;
		return (i);
	}
	return (i);
}

int		ft_checkargument(const char *format)
{
	int		i;
	int		j;
	char	*checkargument;

	i = 0;
	j = 0;
	checkargument = "cspdiuxX%%";
	while (format[i])
	{
		if (format[i] == checkargument[j])
		{
			g_argument = checkargument[j];
			i += ft_go_to_argument(g_argument);
			return (i);
		}
		j++;
	}
	return (i);
}

int		ft_go_to_argument(char g_argument)
{
	//csdiuXxp%
	int i;

	i = 0;
	if (g_argument == 'c')
		ft_c_argument();
	else if (g_argument == '%')
		ft_prct_argument();
	else if (g_argument == 'd' || g_argument == 'i')
		ft_d_argument();
	else if (g_argument == 's')
		ft_s_argument();
	else if (g_argument == 'x' || g_argument == 'X')
		ft_hexa_argument();
	else if (g_argument == 'u')
		ft_u_argument();
	else if (g_argument == 'p')
		ft_p_argument();
	i++;
	return (i);
}
