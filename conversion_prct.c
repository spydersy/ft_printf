/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_prct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:45:41 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/20 11:00:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_not_present_prct(void)
{
	if (g_opts.flag == 0)
	{
		ft_nb_putchar_fd(1, '0', g_opts.width - 1);
		ft_putchar_fd(1, '%');
	}
	else if (g_opts.flag == 1 || (g_opts.width < 0 && g_opts.w_src))
	{
		ft_putchar_fd(1, '%');
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - 1);
	}
	else if (g_opts.flag == -1)
	{
		ft_nb_putchar_fd(1, ' ', g_opts.width - 1);
		ft_putchar_fd(1, '%');
	}
}

void	dot_present_prct(void)
{
	if (g_opts.flag == 1 || g_opts.width < 0)
	{
		ft_putchar_fd(1, '%');
		ft_nb_putchar_fd(1, ' ', ft_vabs(g_opts.width) - 1);
	}
	else if (g_opts.flag == -1)
	{
		ft_nb_putchar_fd(1, ' ', g_opts.width - 1);
		ft_putchar_fd(1, '%');
	}
}

void	ft_conversion_prct(void)
{
	if (g_opts.dot == 0)
	{
		dot_not_present_prct();
	}
	else
	{
		dot_present_prct();
	}
}
