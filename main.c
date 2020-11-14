/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:35:11 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/14 17:38:43 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define S ">><<\n"
int main()
{
    int     sys, usr;

    sys = printf(S);
    usr = ft_printf(S);
    printf("sys : %d\nusr : %d\n", sys, usr);
    return (0);
}