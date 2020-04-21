/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:55:01 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/12 15:58:17 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(format);
	va_start(g_ap, format);
	init_return_value();
	init_global();
	while (format[i] != '\0' && i < len)
	{
		if (format[i] == '%' && format[i] != '\0')
		{
			init_global();
			i += ft_checkpercent(format + i);
			i--;
		}
		else if (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(g_ap);
	return (g_return_value);
}
