/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:15:03 by rusoares          #+#    #+#             */
/*   Updated: 2023/11/27 22:21:42 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
/* OK *Criar a rotina de verificar se existe algum % na string que le*/
/* IN *Quando encontrar usar a funcao para alterar o parametro*/
/* Criar a verificacao das flags antes de usar os specifiers*/
/* Criar IF's para cada caso cspdiuxX% */

int	decimal(char *value);

int ft_printf(const char *str, ...)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
			{
				decimal("1024");
			i++;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int	decimal(char *value)
{
	//int	i;

	//i = 0;
	//while (value)
	//{
		write (1, value, 1);
	//	i++;
	//}
	return (0);	
}

int	main(void)
{
	ft_printf("Teste %d");
	return (0);
}
