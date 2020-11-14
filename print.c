/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:56:49 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/17 00:30:14 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	g_nb_char++;
}

void	ft_nb_putchar_fd(int fd, char c, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_putchar_fd(fd, c);
		i++;
	}
}

void	ft_putstr_fd(int fd, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		ft_putchar_fd(fd, str[i]);
	}
}

void	ft_nb_putstr_fd(int fd, char *str, int nb)
{
	int		i;

	i = -1;
	while (++i < nb && str[i])
	{
		ft_putchar_fd(fd, str[i]);
	}
}

void	ft_putnbr_fd(int fd, long n)
{
	unsigned long nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd(fd, '-');
		nb = -n;
	}
	if (nb <= 9)
	{
		ft_putchar_fd(fd, nb + 48);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(fd, nb / 10);
		ft_putchar_fd(fd, nb % 10 + 48);
	}
}
