/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:05:45 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/20 11:00:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion_c(void)
{
	char	c;

	c = va_arg(g_ap, int);
	if (g_opts.flag == 1 || (g_opts.w_src && g_opts.width < 0))
	{
		ft_putchar_fd(1, c);
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - 1);
	}
	else
	{
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - 1);
		ft_putchar_fd(1, c);
	}
}
