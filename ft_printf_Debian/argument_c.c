/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:19:34 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/12 10:22:18 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_argument(void)
{
	char	c;

	c = va_arg(g_ap, int);
	// printf("\n----- %d ----- %d ----- %d ----- %d -----\n", g_flag, g_minfield, g_period, g_maxfield);
	if (g_flag == -1 && !g_minfield)
		ft_putchar(c);
	if ((g_minfield != 1 && g_flag == 1))
	{
		ft_putchar(c);
		ft_putchar_while(' ', (ft_vabs(g_minfield) - 1));
	}
	else if (g_flag == -1 && g_minfield > 0)
	{
		ft_putchar_while(' ', g_minfield - 1);
		ft_putchar(c);
	}
}
