# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 18:11:29 by abelarif          #+#    #+#              #
#    Updated: 2020/03/11 18:43:43 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=argument_c.c argument_d.c argument_hexa.c argument_s.c ft_print.c \
ft_printf_utils.c ft_printf.c get_parameters_utils.c get_parameters.c  \
argument_prct.c argument_u.c argument_p.c\
 
OBJS=argument_c.o argument_d.o argument_hexa.o argument_s.o ft_print.o \
ft_printf_utils.o ft_printf.o get_parameters_utils.o get_parameters.o  \
argument_prct.o argument_u.o argument_p.o\

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all