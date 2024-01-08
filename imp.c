/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:13:55 by rusoares          #+#    #+#             */
/*   Updated: 2024/01/08 19:13:55 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_putchar(char s);
void	ft_putchar_esp(int nb);
int		prtf(char *s );
/*
int	main(void)
{
	int		i = 0;
	char	*s = "teste";
	int		inv = 0;
	int 	lenght = 10;
	int 	caracteres = 2;
	int		totalimp = lenght - caracteres;


	/*primeiro imprimir a string depois os espacos*//*
	if (inv == 0)
	{
		while (caracteres != 0)
		{
			ft_putchar(s[i]);
			i++;
			caracteres--;
		}
		ft_putchar_esp(totalimp);
		ft_putchar(':');
		ft_putchar('\n');
	}
	/*imprimir primeiro so espacos depois a string*//*
	inv = 1;
	i = 0;
	caracteres = 2;
	if (inv == 1)
	{
		ft_putchar_esp(totalimp);
		while (caracteres != 0)/*while dif Null ou o com dos espacos - o com da str*//*
		{
			ft_putchar(s[i]);
			i++;
			caracteres--;
		}
		ft_putchar(':');
		ft_putchar('\n');
	}
	printf("%-10.2s:\n", "teste");
	printf("%10.2s:\n", "teste");
	return (0);
}
*/

void	ft_putchar(char s)
{
	write (1, &s, 1);
}

void	ft_putchar_esp(int nb)
{
	while (nb != 0)
	{
		write (1, " ", 1);
		nb--;
	}
}

/*
Se for para justificar imprimir primeiro a string e depois os espacos
se for para nao justificar imprimir primeiro os espacos e depois a string
*/
/*
Exemplo:

%10.2s
tenho de ler a string ate encontrar o especificador (s)
enquanto leio a string aloco as variaveis 
	fmw (10)
	precision(2)

depois:
	faco a conta de imprimir os espacos (fmw - precision) (10-2)
	imprimo os espacos (8)
	imprimo os caracteres (2)

*/