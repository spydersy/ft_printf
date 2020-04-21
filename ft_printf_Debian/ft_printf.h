/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:29:42 by abelarif          #+#    #+#             */
/*   Updated: 2020/04/10 00:19:19 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>

# include <stdio.h>

# include <unistd.h>

# include "libft_src/libft.h"

va_list	g_ap;
int		g_return_value;
int		g_flag;
int		g_minfield;
int		g_period;
int		g_maxfield;
char	g_argument;
int		g_indexmax;
int		g_indexmin;

int		ft_vabs(int nbr);
int	    ft_max_of(int var1, int var2);
int     ft_atoi(const char *str);
int		ft_isdigit_or_signe(int c);
size_t	ft_strlen(const char *str);
void	init_global(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_calcul_nbr(int nbr, unsigned long binf, unsigned long bsup);
void	ft_putchar(char c);
void    init_return_value(void);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_putchar_while(char c, int i);
void	ft_c_argument(void);
void    ft_u_argument(void);
void    ft_prct_argument(void);
void	ft_s_argument(void);
void	ft_d_argument(void);
void    ft_hexa_argument(void);
int		ft_checkpercent(const char *format);
int		ft_printf(const char *format, ...);
int		ft_checkflags(const char *format);
int		ft_checkmaxfield(const char *format);
int		ft_checkperiod_maxfield(const char *format);
int		ft_go_to_argument(char g_argument);
int		ft_checkminfield(const char *format);
int		ft_checkargument(const char *format);
int		ft_check_after_percent(const char *format);
void	ft_putnbr_unsigned(unsigned int n);
int		ft_calcul_nbr_u(unsigned int nbr, unsigned long binf, unsigned long bsup);
void	ft_p_argument(void);

#endif
