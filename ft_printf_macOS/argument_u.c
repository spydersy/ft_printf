/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:37:46 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/11 15:35:48 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_period_u(unsigned int nbr, int char_nbr)
{
	if (!g_minfield)
		ft_putnbr_unsigned(nbr);
	else if (g_flag == 1 && g_minfield != 0)
	{
		ft_putnbr_unsigned(nbr);
		ft_putchar_while(' ', ft_vabs(g_minfield) - char_nbr);
	}
	else if (!g_flag && g_minfield > 0)
	{
		ft_putchar_while('0', g_minfield - char_nbr);
		ft_putnbr_unsigned(nbr);
	}
	else if (g_flag == -1 && g_minfield > 0)
	{
		ft_putchar_while(' ', g_minfield - char_nbr);
		ft_putnbr_unsigned(nbr);
	}
}

void	ft_min_inf_max_u(unsigned int nbr, int char_nbr)
{
		ft_putchar_while('0', g_maxfield - char_nbr);
		ft_putnbr_unsigned(nbr);		
}

void	ft_min_sup_max_u(unsigned int nbr, int char_nbr)
{
	if (g_flag == 0 || g_flag == -1)
	{
		ft_putchar_while(' ', g_minfield - (ft_max_of(g_maxfield, char_nbr)));
		ft_putchar_while('0', g_maxfield - char_nbr);
		ft_putnbr_unsigned(nbr);
	}
	else
	{
		ft_putchar_while('0', g_maxfield - char_nbr);
		ft_putnbr_unsigned(nbr);
		ft_putchar_while(' ', g_minfield - (ft_max_of(g_maxfield, char_nbr)));
	}
}

void	ft_period_u(unsigned int nbr, int char_nbr)
{
	if (g_minfield <= g_maxfield)
		ft_min_inf_max_u(nbr, char_nbr);
	else
		ft_min_sup_max_u(nbr, char_nbr);	
}

void	ft_nbr_is_zero_u()
{
	if (g_minfield && !g_maxfield)
		ft_putchar_while(' ', ft_vabs(g_minfield));
	else if (!g_minfield && !g_maxfield)
	{
	}
}

void	ft_u_argument(void)
{
	unsigned int    nbr;
	int             char_nbr;
	
	nbr = (unsigned int)va_arg(g_ap, unsigned int);
    char_nbr = ft_calcul_nbr_u(nbr, 0, 10);
	if ((nbr == 0 && g_period) && ((!g_maxfield && g_minfield) || (!g_maxfield && !g_minfield)))
		ft_nbr_is_zero_u();
	else if (!g_period)
		ft_no_period_u(nbr, char_nbr);
	else
		ft_period_u(nbr, char_nbr);
}