/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:10:18 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/11 15:27:07 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_return_value++;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}
/* debut change */
void	ft_putnbr_unsigned(unsigned int nb)
{

	if (nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}
/* fin */
int		ft_putchar_while(char c, int i)
{
	if (i < 0)
		return (0);
	while (i)
	{
		ft_putchar(c);
		i--;
	}
	return (0);
}
