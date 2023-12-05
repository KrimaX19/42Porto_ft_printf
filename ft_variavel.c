#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
funcao para ler o argumento e alocar nas variaveis corretas
Exemplo: %10.2s
*/
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
		if (s[i] == '%') // comecar a fazer a leitura 
		{
			fmw = atoi(&s[i+1]);
			while (s[i] != '.')
			{
				i++;
			}
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
	printf("\nfmw:%d:\n", fmw);
	printf("Pre:%d:\n", precision);
	return (0);
}
int	main()
{
	variavel("Teste:%10.2s:");
	return (0);
}



/*
Enquanto for diferente do especificador.
	Condicoes:
		Se for digito (Atoi so no primeiro)
		Se tiver ponto ()
		Se tiver digito depois do ponto (atoi so no primeiro)
*/