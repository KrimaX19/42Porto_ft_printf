/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:57:39 by rusoares          #+#    #+#             */
/*   Updated: 2024/01/08 18:57:39 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*librarias*/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"

/*Struct*/

/*Funcoes*/
int		ft_printf(const char *str, ...);
void	ft_putchar(char s);
int		just(char *str);

#endif