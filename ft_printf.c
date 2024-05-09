/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:15:03 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/09 07:37:09 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		lenght;
	va_list	ptr;

	i = 0;
	lenght = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && ++i)
			lenght += ft_conversion(str[i], ptr);
		else
			lenght += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (lenght);
}

int	ft_conversion(char str, va_list ptr)
{
	if (str == 'c')
		return (ft_putchar_fd(va_arg(ptr, int), 1));
	if (str == '%')
		return (write (1, "%", 1));
	if (str == 'd' || str == 'i')
		return (ft_putnbr_fd(va_arg(ptr, int), 1));
	if (str == 'u')
		return (ft_putnbr_u(va_arg(ptr, int), 1));
	if (str == 's')
		return (ft_putstr_fd(va_arg(ptr, char *)));
	if (str == 'x' || str == 'X')
		return (ft_print_hex(va_arg(ptr, unsigned int), str));
	if (str == 'p')
		return (ft_print_p(va_arg(ptr, long int), str));
	return (0);
}

int	ft_putchar_fd(char c, int fd)
{
	size_t	i;

	i = 0;
	if (fd > 0)
		i += write(1, &c, 1);
	return (i);
}
