/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:15:03 by rusoares          #+#    #+#             */
/*   Updated: 2024/04/30 22:43:26 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
//#include "../42Porto_ft_printf/libft/src"

int	ft_putnbr_fd(long int n, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s);
int	ft_print_hex(long long int nb, int flag);
int	ft_putnbr_u(unsigned int n, int fd);
int	ft_print_p(unsigned long long int nb, int flag);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ptr;

	i = 0;
	length = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && ++i)
		{
			if (str[i] == 'c')//OK
				length += ft_putchar_fd(va_arg(ptr, int), 1);
			if (str[i] == '%')//OK
				length += write (1, "%", 1);//OK
			if (str[i] == 'd' || str[i] == 'i')
				length += ft_putnbr_fd(va_arg(ptr, int), 1);//OK
			if (str[i] == 'u')
				length += ft_putnbr_u(va_arg(ptr, int), 1);//OK
			if (str[i] == 's')//NOK
				length += ft_putstr_fd(va_arg(ptr, char *));
			if (str[i] == 'x' || str[i] == 'X')//xX = OK
				length += ft_print_hex(va_arg(ptr, unsigned int), str[i]);
			if (str[i] == 'p') //P = OK
				length += ft_print_p(va_arg(ptr, long int), str[i]);
		}
		else
			length += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (length);
}

int	ft_putnbr_fd(long int n, int fd)
{
	unsigned long	nb;
	int		ret;

	nb = n;
	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar_fd('-', fd);
		nb = -1 * nb;
	}
	if (nb >= 10)
	{
		ret += ft_putnbr_fd(nb / 10, fd);
		ret += ft_putnbr_fd(nb % 10, fd);
	}
	else
		ret += ft_putchar_fd(nb + '0', fd);
	return (ret);
}

int	ft_putchar_fd(char c, int fd)
{
	size_t	i;

	i = 0;
	if (fd > 0)
		i += write(1, &c, 1);
	return (i);
}

int	ft_putstr_fd(char *s)
{
	size_t	i;

	i = 0;

	if (s == NULL)
		return(i + write (1, "(null)", 6));
	while (*s)
	{
	i += write (1, s, 1);
	s++;
	}
	return (i);
}
int	ft_print_hex(long long int nb, int flag)
{
	char	*str;
	int 	i;

	i = 0;
	if (flag == 'x' || flag == 'p')
		str = "0123456789abcdef";
	if (flag == 'X')
		str = "0123456789ABCDEF";
	if (flag == 'p')
	{
		i += write(1,"0x",2);
		flag = 'x';
	}
	if (nb >= 16)
		i += ft_print_hex(nb / 16, flag);
	return (i + ft_putchar_fd(str[nb % 16], 1));
}
int	ft_putnbr_u(unsigned int n, int fd)
{
	unsigned long	nb;
	int		ret;

	nb = n;
	ret = 0;
	if (nb >= 10)
	{
		ret += ft_putnbr_fd(nb / 10, fd);
		ret += ft_putnbr_fd(nb % 10, fd);
	}
	else
		ret += ft_putchar_fd(nb + '0', fd);
	return (ret);
}
int	ft_print_p(unsigned long long int nb, int flag)
{
	char	*str;
	unsigned long long int  	i;
	i = 0;
	if (flag == 'x' || flag == 'p')
		str = "0123456789abcdef";
	if (nb == 0)
		return(i + write(1, "(nil)", 5));
	if (flag == 'p')
	{
		i += write(1,"0x",2);
		flag = 'x';
	}
	if (nb >= 16)
		i += ft_print_hex(nb / 16, flag);
	return (i + ft_putchar_fd(str[nb % 16], 1));
}
