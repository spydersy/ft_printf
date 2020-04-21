/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:59:44 by abelarif          #+#    #+#             */
/*   Updated: 2020/03/13 01:06:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


// int main()
// {
// 	int		i;

// 	i = ft_printf(">>%010%<<\n",-13);
// 	printf("return : %d\n", i);
// 	return (0);
// }

int main()
{
	const char *format;
	int return_printf;
	int return_myprintf;
	
	char *str;
	format = ">>%*.*i<<\n\n";
	str = NULL;

	printf("\n%s-------------------\n\n", format);
	return_myprintf = ft_printf(format , 10, 3, -1);
	return_printf = printf(format, 10, 3 ,-1);
	printf("my printf return : %d\n", return_myprintf);
	printf("\n   printf return : %d\n", return_printf);
	printf("\n----- %d ----- %d ----- %d ----- %d -----\n", g_flag, g_minfield, g_period, g_maxfield);
	return (0);
}
