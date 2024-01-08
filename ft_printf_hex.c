/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:22:31 by rusoares          #+#    #+#             */
/*   Updated: 2024/01/08 19:10:39 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		conta(int n);
int		negativo(int n);
long	conver(long n);
char	*ft_itoa(unsigned int n, int base);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		reverse(int n);

int	ft_printf_hex(int number)
{
	int	resto;
	int	result;
	int	rev;

	rev = 0;
	result = 0;
	resto = 1;
	while (resto != 0)
	{
		resto = number % 16;
		if (resto != 0)
			result *= 10;
		if (resto > 10)
			resto = resto + 55;
		else
			resto = resto;
		result += resto;
		number /= 16;
	}
	rev = reverse(result);
	ft_putnbr_fd(rev, 1);
	ft_putchar_fd('\n', 1);
	return (result);
}

int	reverse(int n)
{
	int	resto;
	int	resultado;

	resto = 0;
	while (n < 0)
	{
	}
	return (resultado);
}
/*
int	main()
{
	int i;
	int	vteste;
	int t = 65;

	vteste = 666;
	i =1 ;
	while (i <= vteste)
	{
		//ft_printf_hex(i);
		printf("Decimal: %d\n", i);
		printf("         itoa: %s\n", ft_itoa(i, 16));
		printf("       Printf: %X\n", i);
		printf("ft_printf_hex: %d\n", ft_printf_hex(i));
		i++;
	}
	write (1, &t, 1);
	return (0);
}
*/

char	*ft_itoa(unsigned int n, int base)
{
	int		i;
	long	nb;
	char	*conv;

	nb = conver(n);
	i = conta(n);
	if (n == 0)
		i = 1;
	conv = malloc (sizeof (char) * i + 1);
	if (!conv)
		return (NULL);
	conv[i] = '\0';
	while (i != 0)
	{
		if (nb % base < 10)
		{
			conv[--i] = '0' + (nb % base);
		}
		else
		{
			conv[--i] = '7' + (nb % base);
		}
		nb /= base;
	}
	return (conv);
}

int	conta(int n)
{
	long	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

long	conver(long n)
{
	long	nb;

	if (n < 0)
	{
		nb = n * -1;
		return (nb);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -1 * nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + 48, fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd > 0)
	{
		write(fd, &c, 1);
	}
}
