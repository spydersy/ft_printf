/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_prct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 21:50:03 by abelarif          #+#    #+#             */
/*   Updated: 2020/04/09 23:23:28 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_prct_argument()
{
    if (!g_period)
    {
        if (g_flag == 0)
        {
            // ft_putchar_while('0', g_minfield - 1);
            ft_putchar('%');
        }
        if (g_flag == 1)
        {
            ft_putchar('%');
            // ft_putchar_while(' ', g_minfield - 1);
        }
         if (g_flag == -1)
        {
            // ft_putchar_while(' ', g_minfield - 1);
            ft_putchar('%');
        }       
    }
    else
    {
        if (g_flag == 1)
        {
            ft_putchar('%');
            // ft_putchar_while(' ', g_minfield - 1);
        }
        else if (g_flag == -1)
        {
            // ft_putchar_while(' ', g_minfield - 1);
            ft_putchar('%');
        }
    }
}
