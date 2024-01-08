/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variavel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:30 by rusoares          #+#    #+#             */
/*   Updated: 2024/01/08 19:13:06 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int	variavel(const char *s)
{
	int	i;
	int	fmw;
	int	precision;

	i = 0;
	fmw = 0;
	precision = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			fmw = atoi (&s[i + 1]);
			while (s[i] != '.')
				i++;
		}
		if (s[i] == '.')
		{
			i++;
			precision = atoi(&s[i]);
			i++;
		}
		write(1, &s[i], 1);
		i++;
	}
	return (0);
}
/*
int	main()
{
	variavel ("Teste:%10.2s:");
	return (0);
}
*/
