#include <stdarg.h>

int	add(int n, ...)
{
	int	sum;
	int i;

	sum = 0;
	i = 0;
	va_list	ptr;
	va_start(ptr, n);

	while (i < n)
	{
		sum += va_arg(ptr, int);
		i++;
	}
	va_end(ptr);

	return (sum);
}

int	main()
{
	add(2,1,2);
	add(3,3,4,5);
	add(4,6,7,8,9);
	return (0);
}

/*
- va_list(ptr) cria um ponteiro para a list da funcao variavel (...)
- va_start(ptr, n) inicializa o ponteiro para a primeira posicao do pointer
	- Colocar a variavel na mesma 
- va_arg (ptr, int) aponta para o pontiero de um tipo de variavel
- va_end (ptr) encerra a lista
*/