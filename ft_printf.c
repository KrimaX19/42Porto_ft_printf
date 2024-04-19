/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:15:03 by rusoares          #+#    #+#             */
/*   Updated: 2024/04/19 23:57:52 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
//#include "../42Porto_ft_printf/libft/src"

int	ft_putnbr_fd(int n, int fd);
int	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int	ft_print_hex(size_t nb, int flag);
int	countnb(int nb);

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
			if (str[i] == 'c')//ok
				length += ft_putchar_fd(va_arg(ptr, int), 1);
			if (str[i] == '%')//ok
				length += write (1, "%", 1);
			if (str[i] == 'd' || str[i] == 'i' || str[i] =='u')//ok (teste u needed)
				length += countnb(va_arg(ptr, int));
			if (str[i] == 's')//ok
				length += ft_putstr_fd(va_arg(ptr, char *), 1);
			if (str[i] == 'x' || str[i] == 'X' || str[i] == 'p')//ok
				length += ft_print_hex(va_arg(ptr, unsigned int), str[i]);
		}
		else
			length += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (length);
}

//int	main(void)
//{
//	int x = ft_printf("%d", 0);
//	printf("%d", x);
//	return (0);
//}

int	ft_putnbr_fd(int n, int fd)
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
	{
		ret += ft_putchar_fd(nb + '0', fd);
	}
	return (ret);
}

int	countnb(int nb)
{
	return (ft_putnbr_fd(nb, 1));
}

int	ft_putchar_fd(char c, int fd)
{
	size_t	i;

	i = 0;
	if (fd > 0)
	{
		i += write(1, &c, 1);
	}
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (fd >= 0)
	{
		while (*s)
		{
			i += write (1, s, 1);
			s++;
			
		}
	}
	return (i);
}
int	ft_print_hex(size_t nb, int flag)
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
		i = write(1,"0x",2);
		flag = 'x';
	}
	if (nb >= 16)
		ft_print_hex(nb / 16, flag);
	return (i + ft_putchar_fd(str[nb % 16], 1));
	
}
