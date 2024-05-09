/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 07:48:52 by rusoares          #+#    #+#             */
/*   Updated: 2024/05/09 07:48:52 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*librarias*/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

/*Struct*/

/*Funcoes*/
int	ft_putnbr_fd(long int n, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s);
int	ft_print_hex(long long int nb, int flag);
int	ft_putnbr_u(unsigned int n, int fd);
int	ft_print_p(unsigned long long int nb, int flag);
int	ft_conversion(char str, va_list ptr);
int	ft_printf(const char *str, ...);

#endif