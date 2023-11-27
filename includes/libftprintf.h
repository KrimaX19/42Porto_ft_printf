/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:42:12 by rusoares          #+#    #+#             */
/*   Updated: 2023/11/27 22:21:45 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>


typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		total_lenght;
	int		sign;
	int		is_zero;
	int		perc;
	int		space;
}	t_print;


