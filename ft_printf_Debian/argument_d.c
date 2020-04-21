/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:21:51 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/11 14:32:49 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_period(int nbr, int char_nbr)
{
	if (!g_minfield)
		ft_putnbr(nbr);
	else if (g_flag == 1 && g_minfield != 0)
	{
		ft_putnbr(nbr);
		ft_putchar_while(' ', ft_vabs(g_minfield) - char_nbr);
	}
	else if (!g_flag && g_minfield > 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		ft_putchar_while('0', g_minfield - char_nbr);
		(nbr  != -2147483648) ? (ft_putnbr(nbr)) : (ft_putstr("2147483648"));
	}
	else if (g_flag == -1 && g_minfield > 0)
	{
		ft_putchar_while(' ', g_minfield - char_nbr);
		ft_putnbr(nbr);
	}
}

void	ft_min_int(int char_nbr, int index_neg)
{
	ft_putchar('-');
	ft_putchar_while('0', g_maxfield - char_nbr + index_neg);
	ft_putnbr(2);
	ft_putnbr(147483648);
}

void	ft_min_inf_max(int nbr, int char_nbr, int index_neg)
{
	if (nbr < 0 &&  nbr != -2147483648)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= 0)
	{
		ft_putchar_while('0', g_maxfield - char_nbr + index_neg);
		ft_putnbr(nbr);		
	}
	else if (nbr == -2147483648)
		ft_min_int(char_nbr, index_neg);
}

void	ft_min_sup_max(int nbr, int char_nbr, int index_neg)
{
	if (g_flag == 0 || g_flag == -1)
	{
		ft_putchar_while(' ', g_minfield - (ft_max_of(g_maxfield, char_nbr)));
		if (nbr == -2147483648)
			ft_min_int(char_nbr, index_neg);
		else if (index_neg)
		{
			ft_putchar('-');
			ft_putchar_while('0', g_maxfield - char_nbr + index_neg);
			ft_putnbr(nbr * -1);
		}
		else
		{
			ft_putchar_while('0', g_maxfield - char_nbr + index_neg);
			ft_putnbr(nbr);
		}
	}
	else
	{
		if (nbr == -2147483648)
			ft_min_int(char_nbr, index_neg);
		else if (index_neg)
		{
			ft_putchar('-');
			ft_putchar_while('0', g_maxfield - char_nbr + index_neg);
			ft_putnbr(nbr * -1);
		}
		else
		{
			ft_putchar_while('0', g_maxfield - char_nbr + index_neg);
			ft_putnbr(nbr);
		}
		ft_putchar_while(' ', g_minfield - (ft_max_of(g_maxfield, char_nbr)) - index_neg);
	}
	
}

void	ft_period(int nbr, int char_nbr)
{
	int index_neg;

	(nbr < 0) ? (index_neg = 1) : (index_neg = 0);
	if (g_minfield <= g_maxfield)
		ft_min_inf_max(nbr, char_nbr, index_neg);
	else
		ft_min_sup_max(nbr, char_nbr, index_neg);	
}

void	ft_nbr_is_zero()
{
	if (g_minfield && !g_maxfield)
		ft_putchar_while(' ', ft_vabs(g_minfield));
	else if (!g_minfield && !g_maxfield)
	{
	}
}

void	ft_d_argument(void)
{
	int	nbr;
	int	char_nbr;
	
	nbr = va_arg(g_ap, int);
	char_nbr = ft_calcul_nbr(nbr, 0, 10);
	if ((nbr == 0 && g_period) && ((!g_maxfield && g_minfield) || (!g_maxfield && !g_minfield)))
		ft_nbr_is_zero();
	else if (!g_period)
		ft_no_period(nbr, char_nbr);
	else
		ft_period(nbr, char_nbr);
}
