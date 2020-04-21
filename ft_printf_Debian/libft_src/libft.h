/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:53:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/01/10 20:50:23 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_itoa(int nbr);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s, char const *set);

#endif
