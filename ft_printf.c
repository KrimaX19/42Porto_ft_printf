/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:15:03 by rusoares          #+#    #+#             */
/*   Updated: 2023/11/28 22:10:55 by rusoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/* OK *Criar a rotina de verificar se existe algum % na string que le*/
/* IN *Quando encontrar usar a funcao para alterar o parametro*/
/* Criar a verificacao das flags antes de usar os specifiers*/
/* Criar IF's para cada caso cspdiuxX% */



/*
- va_list(ptr) cria um ponteiro para a list da funcao variavel (...)
- va_start(ptr, n) inicializa o ponteiro para a primeira posicao do pointer
	- Colocar a variavel na mesma que o especificador (ex: %d - int)
- va_arg (ptr, int) aponta para o pontiero de um tipo de variavel
- va_end (ptr) encerra a lista

INIT - %c - putchar (int)
INIT - %s - putstr (char *)
INIT - %% (print percent) (write %)
INIT - %d ou i (printnbr) (int)
INIT - %x ou X (print Hex com to upper ou tolower (unsigned int)
	Preciso de fazer a conversao e usar o especificador parafazer x ou X
%p - (print pointer) (unsigend long long)
	Usar itoa para passar o numero para char*
%u (print unsigned) (unsigned int)

em cada uma das funcoes tenho de alocar memoria para as variaveis que vou manipular e dar free.

Problemas a resolver:

- especificadores sem espacos entre eles (ex: %d%d%d%d)
	- R: resolvido com um while loop
- criar link entre as funcoes do libft e o printf
- criar o makefile
- criar funcao para converter de decimal para hexadecimal


*/

int	decimal(char *value);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int	ft_tolower(int c);/*nao preciso pois no momento de escrever basta escolher o caracter a*/
int	ft_toupper(int c);/*nao preciso pois no momento de escrever basta escolher o caracter A*/

int	test(int c)
{
	write(1, &c, 1);
	return (1);
}

int	testd(int d)
{
	ft_putnbr_fd(d, 1);
	return(2);
}

int	tests(char *s)
{
	ft_putstr_fd(s, 1);
	return(3);
}
int	testX(unsigned int x)
{
	ft_putnbr_fd(ft_tolower(x), 1);
	return (4);
}

int	testx(unsigned int x)
{
	ft_putnbr_fd(ft_toupper(x), 1);
	return (4);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int	length;
	va_list	ptr;

	i = 0;
	length = 0;
	va_start(ptr, str);
	while (str[i])
	{
		while(str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				length = test(va_arg(ptr, int));
			}
			if (str[i] == '%')
			{
				write(1, "%" , 1);
			}
			if (str[i] == 'd')
			{
				length = testd(va_arg(ptr, int));
			}
			if(str[i] == 's')
			{
				length = tests(va_arg(ptr, char *));
			}
			if(str[i] == 'x')
			{
				length = testx(va_arg(ptr, unsigned int));
			}
			if(str[i] == 'X')
			{
				length = testx(va_arg(ptr, unsigned int));
			}
			i++;			
		}
		write(1, &str[i], 1);
		i++;
	}
	return (length);
}

int	main(void)
{
	ft_printf("FT_PRINTF: %c, %c, %%:\n", 'A','b');
	printf("   PRINTF: %c, %c, %%:\n", 'A','b');
	ft_printf("FT_PRINTF: %%:\n");
	printf("   PRINTF: %%:\n");
	ft_printf("FT_PRINTF: %d%d%d%d\n", 1102515,12354,98756,-15131);/*verificar como fazer para nao ver os espacos*/
	printf("   PRINTF: %d%d%d%d\n", 1102515,12354,98756,-15131);
	ft_printf("FT_PRINTF: %s:\n", "Teste string");
	printf("   PRINTF: %s:\n", "Teste string");
	ft_printf("FT_PRINTF: X %X:\n", 42);
	printf("   PRINTF: X %X:\n", 42);
	ft_printf("FT_PRINTF: x %x:\n", 42);
	printf("   PRINTF: x %x:\n", 42);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -1 * nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd > 0)
	{
		write(fd, &c, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		return (c);
	}
	return (c);
}
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	return (c);
}
