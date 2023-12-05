/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusoares <rusoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:15:03 by rusoares          #+#    #+#             */
/*   Updated: 2023/12/04 19:17:54 by rusoares         ###   ########.fr       */
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
Resolvido:

- Flag + no especificador d, funciona
- Flag ' ' no especificador d, funciona
- Especificadores sem espacos entre eles (ex: %d%d%d%d)
	- R: resolvido com um while loop

Problemas a resolver:

- Field minimum with nao funciona
	- Tenho de aprender a fazer com uma rotina para executar x vezes.
	- Posso usar um contador de numeros para ver o comprimento do numero e fazer um putnbr com tamanho
		- Se o numero for maior que o fmw coloco os espaco que manda e depois 
- criar link entre as funcoes do libft e o printf
- criar o makefile
- criar funcao para converter de decimal para hexadecimal


*/

//int	decimal(char *value);
void	ft_putnbr_fd(int n, int fd, int flg, unsigned long count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
//int	ft_tolower(int c);/*nao preciso pois no momento de escrever basta escolher o caracter a*/
//int	ft_toupper(int c);/*nao preciso pois no momento de escrever basta escolher o caracter A*/

int	test(int c)
{
	write(1, &c, 1);
	return (1);
}

int	testd(int d, int flgplus)
{
	ft_putnbr_fd(d, 1, flgplus,0);
	return(2);
}

int	tests(char *s)
{
	ft_putstr_fd(s, 1);
	return(3);
}
int	testX(unsigned int x)
{
	ft_putnbr_fd(x, 0, 0,0);
	return (4);
}

int	testx(unsigned int x)
{
	ft_putnbr_fd(x, 0, 0, 0);
	return (4);
}

int ft_printf(const char *str, ...)
{
	int	i;
	int	length;
	va_list	ptr;
	int	flgplus;

	i = 0;
	length = 0;
	flgplus = 0;
	va_start(ptr, str);
	while (str[i])
	{
		while(str[i] == '%')
		{
			i++;
			if(str[i] == '+')
			{
				flgplus = '+';
				i++;
			}
			if(str[i] == ' ')
			{
				flgplus = ' ';
				i++;
			}
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
				length = testd(va_arg(ptr, int), flgplus);
			}
			if(str[i] == 's')
			{
				length = tests(va_arg(ptr, char *));
			}
			if(str[i] == 'x')
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
	ft_printf("FT_PRINTF: %d %d %d %d\n", 1102515,12354,98756,-15131);/*teste de numeros decimais*/
	printf("   PRINTF: %d %d %d %d\n", 1102515,12354,98756,-15131);
	ft_printf("FT_PRINTF: %+d %+d %+d %+d\n", 1102515,12354,98756,-15131);/*teste de numeros decimais com sinal de +*/
	printf("   PRINTF: %+d %+d %+d %+d\n", 1102515,12354,98756,-15131);
	ft_printf("FT_PRINTF: % d % d % d % d\n", 1102515,12354,98756,-15131);/*teste de numeros decimais com espaco*/
	printf("   PRINTF: % d % d % d % d\n", 1102515,12354,98756,-15131);
	ft_printf("FT_PRINTF: %5d %5d %5d %5d\n", 15,154,9756,-15131);/*teste de numeros decimais com fmw de 5*/
	printf("   PRINTF: % 5d %5d %5d %5d\n", 15,154,9756,-15131);/*faz while enquanto este numero ou aloca so 5 espacos*/
	ft_printf("FT_PRINTF: %s:\n", "Teste string");
	printf("   PRINTF: %s:\n", "Teste string");
	ft_printf("FT_PRINTF: X %X:\n", 42);
	printf("   PRINTF: X %X:\n", 42);
	ft_printf("FT_PRINTF: x %x:\n", 42);
	printf("   PRINTF: x %x:\n", 42);
	//printf("%sx%d");
	return (0);
}

void	ft_putnbr_fd(int n, int fd, int flg, unsigned long count)
{
	unsigned long	nb;

	nb = n;
	if (flg == '+' || flg == ' ')
	{
		if (nb > 1)
		{
		ft_putchar_fd(flg,fd);
		}
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -1 * nb;
	}
	while(nb == count)
	{
		while (nb >= 10)
		{
			n = nb / 10;
			n = nb % 10;
		}
	}
}

/* alterar o putnbr para nao fazer recusrsiva 
e so fazer durante o count number ou o numero de vezes que disser
que sera dado pelo fmw ou pelo count number*/

int	countnb(int nb)
{
	int	i;
	int n;

	i = 0;
	n = nb;
	while (n)
	{
		n = n/10;
		i++;
	}
	return (i);
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
/*
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

*/
/*
codigo esta criado de forma a poder verificar se a string tem o sinal % e apos
verificar qual e o especificador. Depois disso executa uma funcao associada ao especificador.
Posso usar funcoes ja criadas como tambem terei de usar funcoes para casos especiais.

Proximos passos:
- Avaliar como posso integrar as flags de bonus
	verificar se ira mudar muito o codigo u se sera de facil implementacao
		Usar um especificador como exemplo
*/

/*
Se for %, verificar se tem alguma flag
se tiver flag, fazer alguma coisa ou executar a funcao com mais um parametro
*/