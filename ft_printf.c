/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:15:03 by rusoares          #+#    #+#             */
/*   Updated: 2024/01/08 21:39:13 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putnbr_fd(int n, int fd, int flg, unsigned long count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

int	test(int c)
{
	write (1, &c, 1);
	return (1);
}

int	testd(int d, int flgplus)
{
	ft_putnbr_fd (d, 1, flgplus, 0);
	return (2);
}

int	tests(char *s)
{
	ft_putstr_fd (s, 1);
	return (3);
}
/*
int	test_x (unsigned int x)
{
	ft_putnbr_fd (x, 0, 0, 0);
	return (4);
}
*/

int	testx(unsigned int x)
{
	ft_putnbr_fd (x, 0, 0, 0);
	return (4);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ptr;
	int		flgplus;

	i = 0;
	length = 0;
	flgplus = 0;
	va_start(ptr, str);
	while (str[i])
	{
		while (str[i] == '%')
		{
			i++;
			if (str[i] == '+')
			{
				flgplus = '+';
				i++;
			}
			if (str[i] == ' ')
			{
				flgplus = ' ';
				i++;
			}
			if (str[i] == 'c')
			{
				length = test(va_arg(ptr, int));
			}
			if (str[i] == '%')
			{
				write (1, "%", 1);
			}
			if (str[i] == 'd')
			{
				length = testd(va_arg(ptr, int), flgplus);
			}
			if (str[i] == 's')
			{
				length = tests(va_arg(ptr, char *));
			}
			if (str[i] == 'x')
			{
				length = testx(va_arg(ptr, unsigned int));
			}
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
	return (length);
}

/*
int	main(void)
{
	ft_printf("%c\n", '0');
	printf("%c\n", '0');
	ft_printf(" %c \n", '0');
	printf(" %c \n", '0');
	ft_printf(" %c\n", '0' - 256);
	printf(" %c\n", '0' - 256);
	ft_printf("%c \n", '0' + 256);
	printf("%c \n", '0' + 256);
	ft_printf(" %c %c %c \n", '0', 0, '1');
	printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	printf(" %c %c %c \n", ' ', ' ', ' ');
	ft_printf(" %c %c %c \n", '1', '2', '3');
	printf(" %c %c %c \n", '1', '2', '3');
	ft_printf(" %c %c %c \n", '2', '1', 0);
	printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %c %c %c \n", 0, '1', '2');
	printf(" %c %c %c \n", 0, '1', '2');

	printf("   PRINTF: %%:\n");
	ft_printf("FT_PRINTF: %d %d %d %d\n", 1102515,12354,98756,-15131);
	printf("   PRINTF: %d %d %d %d\n", 1102515,12354,98756,-15131);
	ft_printf("FT_PRINTF: %+d %+d %+d %+d\n", 1102515,12354,98756,-15131);
	printf("   PRINTF: %+d %+d %+d %+d\n", 1102515,12354,98756,-15131);
	ft_printf("FT_PRINTF: % d % d % d % d\n", 1102515,12354,98756,-15131);
	printf("   PRINTF: % d % d % d % d\n", 1102515,12354,98756,-15131);
	ft_printf("FT_PRINTF: %5d %5d %5d %5d\n", 15,154,9756,-15131);
	printf("   PRINTF: % 5d %5d %5d %5d\n", 15,154,9756,-15131);
	ft_printf("FT_PRINTF: %s:\n", "Teste string");
	printf("   PRINTF: %s:\n", "Teste string");
	ft_printf("FT_PRINTF: X %X:\n", 42);
	printf("   PRINTF: X %X:\n", 42);
	ft_printf("FT_PRINTF: x %x:\n", 42);
	printf("   PRINTF: x %x:\n", 42);
	return (0);
}
*/

void	ft_putnbr_fd(int n, int fd, int flg, unsigned long count)
{
	unsigned long	nb;

	nb = n;
	if (flg == '+' || flg == ' ')
	{
		if (nb > 1)
		{
			ft_putchar_fd(flg, fd);
		}
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -1 * nb;
	}
	while (nb == count)
	{
		while (nb >= 10)
		{
			n = nb / 10;
			n = nb % 10;
		}
	}
}

int	countnb(int nb)
{
	int	i;
	int	n;

	i = 0;
	n = nb;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd > 0)
	{
		write(fd, &c, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}
