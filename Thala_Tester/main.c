#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	ft_printf(const char *, ...);

#ifdef _FT_USER__
#	define PRINTF_MACRO ft_printf
#else
#	define PRINTF_MACRO printf
#endif

static unsigned int my_strlen(char *str)
{
	unsigned int i = 0;
	while (str[i])
		i++;
	return i;
}

static void	print_test(char *str)
{
#ifdef _FT_USER__
	write(1, str, my_strlen(str));
	write(1, " : ", 3);
#else
	printf("%s : ", str);
#endif
}

static void	my_put_nbr(int nb)
{
	int		div = 1;
	char	c;
	
	while (nb / div >= 10 || nb / div <= -10)
		div = div * 10;
	if (nb < 0)
		write(1, "-", 1);
	while (div)
	{
		if (nb < 0)
			c = ((nb / div) % 10) * -1 + '0';
		else
			c = ((nb / div) % 10) + '0';
		write(1, &c, 1);
		div = div / 10;
	}
}

static void	print_ret(int ret)
{
#ifdef _FT_USER__
	write(1, " ", 1);
	my_put_nbr(ret);
	write(1, "\n", 1);
#else
	printf(" %d\n", ret);
#endif
}

int	main(void)
{
	#include "tests.c"
	return (0);
}

