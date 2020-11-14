# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 16:26:44 by abelarif          #+#    #+#              #
#    Updated: 2020/10/25 16:54:16 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=	conversio_u.c conversion_i_d.c conversion_s.c manipulation.c\
		conversion_c.c conversion_p.c ft_printf.c print.c flag_zero_i_d_u_hex.c\
		conversion_hex.c conversion_prct.c ft_printf_utils.c\

OBJS=	conversio_u.o conversion_i_d.o conversion_s.o manipulation.o\
		conversion_c.o conversion_p.o ft_printf.o print.o flag_zero_i_d_u_hex.o\
		conversion_hex.o conversion_prct.o ft_printf_utils.o\

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all