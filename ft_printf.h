/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:01:43 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/27 23:18:27 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct		s_options
{
	int			flag;
	int			width;
	int			w_src;
	int			dot;
	int			precision;
	int			p_src;
	char		conversion;
}					t_options;

t_options		g_opts;
int				g_nb_char;
va_list			g_ap;

int					ft_printf(const char *format, ...);
void				flag_zero_hex(int nb_bits, int upper, unsigned long long x);
void				flag_zero_i_d(int i, int neg, int nb_bits);
int					ft_isdigit(int c);
int					ft_toupper(int c);
int					ft_max_of(int i, int j);
int					ft_atoi(const char *str);
int					ft_skip_digit(const char *str, int i);
void				ft_putchar_fd(int fd, char c);
void				ft_init(void);
int					ft_manip(const char *format, int i);
long long			ft_vabs(long i);
void				ft_nb_putchar_fd(int fd, char c, int nb);
size_t				ft_strlen(const char *str);
void				ft_conversion_s(void);
void				ft_conversion_c(void);
int					ft_conversion_i_d(void);
void				ft_conversion_u(void);
void				flag_zero_u(unsigned int u, int nb_bits);
void				ft_conversion_prct(void);
void				ft_conversion_p(void);
void				ft_conversion_hex(int i);
void				ft_nb_putstr_fd(int fd, char *str, int nb);
void				redirection(void);
void				ft_putstr_fd(int fd, char *str);
int					nb_bits(long long i);
void				ft_putnbr_fd(int fd, long n);
int					ft_nb_bits(long long i);
int					ft_nb_bits_x_p(unsigned long long value);
void				ft_puthex_fd(int fd, unsigned long long value);
void				ft_puthex_upper_fd(int fd, unsigned long long value);

#endif
