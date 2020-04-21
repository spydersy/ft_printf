/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:20:18 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/13 00:20:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_argument_noperiod(char *str)
{
	int	lenstr;

	lenstr = ft_strlen(str);
	if (lenstr > g_minfield)
		ft_putstr(str);
	else
	{
		if (g_flag == 1 && g_minfield > 0)
		{
			ft_putstr(str);
			ft_putchar_while(' ', g_minfield - lenstr);
		}
		else if (!g_minfield)
			ft_putstr(str);
		else if (g_flag == -1 && g_minfield > 0)
		{
			ft_putchar_while(' ', g_minfield - lenstr);
			ft_putstr(str);
		}
	}
	
}

int ft_nb_str(char *str)
{
	int	len_str;

	len_str = ft_strlen(str);
	if (len_str <= g_maxfield)
	{
		return (len_str);
	}
	else
	{
		return (g_maxfield);
	}
}

int ft_min_of(int i, int j)
{
	return ((i < j) ? (i) : (j));
}

void	ft_s_argument_period(char *str, int special)
{
	int i;
	int	nb_str;
	int	minofnbrs;

	minofnbrs = ft_min_of(ft_strlen(str), g_maxfield);
	i = 0;
	if (g_flag == 1)
	{
		if (g_minfield == g_maxfield && g_minfield < (int)ft_strlen(str) && !special)
			ft_putstr(str);
		else 
		{
			if (!special)
			{
				while (i < g_maxfield && str[i])
				{
					ft_putchar(str[i]);
					i++;
				}
			}
			ft_putchar_while(' ', g_minfield - i);
		}
	}
	else if (!g_minfield)
	{
		if (!special)
		{
			while (i < minofnbrs)
			{
				ft_putchar(str[i]);
				i++;
			}
		}
	}
	else
	{
		nb_str = ft_nb_str(str);
		ft_putchar_while(' ', g_minfield - nb_str);
		if (!special)
		{
			while (i < nb_str && str[i])
			{
				ft_putchar(str[i]);
				i++;
			}
		}		
	}	
}

void	ft_s_argument(void)
{
	char *str;
	int	special;
	
	str = va_arg(g_ap, char *);
	(g_maxfield < 0) ? (g_maxfield *= -1) : (g_maxfield *= 1);
	if (str == NULL)
		str = "(null)";
	(g_period && !g_maxfield) ? (special = 1) : (special = 0);
	if (g_indexmax == 11 && g_minfield < ft_vabs(g_maxfield))
		g_period = 0;
	if (!g_period)
	{
		ft_s_argument_noperiod(str);
	}
	else
	{
		ft_s_argument_period(str, special);
	}
}
