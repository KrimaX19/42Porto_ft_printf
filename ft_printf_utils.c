/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:33:52 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/09 08:50:58 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(long int n, int fd)
{
	unsigned long	nb;
	int				ret;

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

int	ft_putstr_fd(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i + write (1, "(null)", 6));
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
	int		i;

	i = 0;
	if (flag == 'x' || flag == 'p')
		str = "0123456789abcdef";
	if (flag == 'X')
		str = "0123456789ABCDEF";
	if (flag == 'p')
	{
		i += write (1, "0x", 2);
		flag = 'x';
	}
	if (nb >= 16)
		i += ft_print_hex(nb / 16, flag);
	return (i + ft_putchar_fd(str[nb % 16], 1));
}

int	ft_putnbr_u(unsigned int n, int fd)
{
	unsigned long	nb;
	int				ret;

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
	char						*str;
	unsigned long long int		i;

	i = 0;
	if (flag == 'x' || flag == 'p')
		str = "0123456789abcdef";
	if (nb == 0)
		return (i + write (1, "(nil)", 5));
	if (flag == 'p')
	{
		i += write (1, "0x", 2);
		flag = 'x';
	}
	if (nb >= 16)
		i += ft_print_hex(nb / 16, flag);
	return (i + ft_putchar_fd(str[nb % 16], 1));
}
