Erros:
    - Francinette nao esta a dar ok, apesar de a funcao estar a mostrar os valores corretos
        *- Verificar a contagem de caracteres, pois o printf retorna o numero de caracteres,

        

Conversões

%c - Imprime um caracter
%s - Imprime uma string
%p - Um ponteiro void impresso em hexadecimal
%d - Imprime um numero em decimal
%i - Imprime um inteiro em base 10
%u - Imprime um unsigned decimal (base 10) 
%x - imprime um numero em hexadecimal (base 16) em lowercase
%X - Imprime um numero em hexadecimal (base 16) em Uppercase
%% - Imprime um sinal de percentagem


Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flag
s: ’# +’ (Yes, one of them is a space)


/*

%[flags][width][.precision][length]specifier 

Flags:
'-' - justifica o texto á esquerda (default direita) 

'+' - Forca a colocação do sinal de + nos numero positivos
    %+d - %+f coloca sempre o sinal no numero

' ' - Adiciona espaço se nenhum sinal antes do valor
    % d - Serve para alinhar numeros por varios motivos, sendo um dos sinais dos numeros
    Exemplo: 
    printf("Numero: %+d", 42) R: +42, 
    printf("Numero: %+d", -42) R: -42,
    Para conseguir colocar os numeros alinhados sem mostrar o sinal de positivo uso o % d.
    Assim se o numero for positivo ja aparece com um espaço no lugar do sinal e alinha os 2 valores
    Se o sinal for negativo o % d , é ignorado e não coloca nenhum espaço.

'#' - antecede o, x ou X com 0
    %#_ : Depende doespecificador do formato utilizado.
    o # ativa modificações especificas ou alternativas para alguns tipos de dados
    Especificadores:

'#' - OK    %#p - o resultado é sempre de 0x á frente para indicar que está em hexadecimal
'#' - OK    %#x ou %X - mostra o valor precedido de 0x ou 0X (x ou X), para indicar que está em hexadecimal
'#' - NA    %#o - Faz com que o valor seja precedido de 0 (zero), mostra em base octal
'#' - NA    %#a ou %A - o resultado é sempre em hexadecimal
'#' - NA    %#e ou %E - o resultado é sempre impresso em notação cientifica
'#' - NA    %#g ou %G - o resultado é smpre em notação cientifica mesmo que não seja necessário
'#' - NA    %#f - o resultado é sempre com o ponto decimal mesmo com valores inteiro
'#' - NA    %#u - não tem impacto
'#' - NA    %#i - nao tem impacto
'#' - NA    %#s - não tem impacto
'#' - NA    %#c - não tem impacto
'#' - NA    %#d - não tem impacto


'O' - adiciona zero á esquerda
    %05d - (printf("Numero: %05d", -42) Resultado: -0042 (5 caracteres, como seria -42, preenche o resto com zeros))
    se for : (printf("Numero: %05d", -42) Resultado : 00042 (5 caracteres)

Width:
(numero) numero minimo de caracteres a imprimir


.precision:
.numero - especifica o numero de digitos a escrever

length:

Specifier:
    %c - Imprime um caracter
*(Usar o ft_putchar para imprimir um só caracter)
    %s - Imprime uma string
*(usar o ft_putstr)
    %p - Um ponteiro void impresso em hexadecimal
*(verificar se ponteiros já estão em hexadecimal)
    %d - Imprime um numero em decimal
*(usar o ft_putnbr para imprimir um numero)
    %i - Imprime um inteiro em base 10
*(Valor pode ser positivo ou negativo)
    %u - Imprime um unsigned decimal (base 10) 
*(Valor sempre positivo)
    %x - imprime um numero em hexadecimal (base 16) em lowercase
*(converter o numero para hexadecimal e converte as letras para lowercase)
    %X - Imprime um numero em hexadecimal (base 16) em Uppercase
*(Converte o numero para hexadecimal e converte as letras para Uppercase)
    %% - Imprime um sinal de percentagem
*(Usar o ft_putchar com o simbolo %)


printf("texto a imprimir") - Imprime o que está entre aspas
printf("texto %c", c) - Imprime o caracter 'c' na posição que está no texto
printf("texto %s", str) - Imprime a string na posição que está no texto

O printf escreve sempre o que está entre aspas, assim como garante a posição das variaveis que vai escrever, por isso tenho de acautelar
a situação de ter mais do que uma variavél.


BoNuS:

Manage any combination of the following flags '-0.' and the field minimum width under all conversions

Combinações de flags:
    - = jsutifica
    0 = coloca zeros
    . = ponto para float
    -0 = justifica esquerda, coloca zeros
    -. = justifica esquerda, ponto para float
    0. = coloca zeros, ponto para float
    -0. = justifica esquerda, coloca zeros, ponto para float

Largura minima:
(Field minimum width)
    Se fmw for > ao numero, coloca espaços em branco para completar
    Se fmw for < ao numero, cria o espaço para o numero sem adicionar nada
    Se fmw for = ao numero, não faz nada
    Se fmw com flag 0:
        Se o numero > que o espaçõ, não coloca zeros
        Se o numero < que o espaço coloca o numero de zeros e aloca espaços á direita se necessário
        Se o numero = ao espaço não coloca zeros nem espaços


fmw 


Manage all the following flags: '# +' ("Cardinal, espaço e mais")
'#' = altera as funções conforme os especificadores
'+' = Coloca um sinal em todos os valores sejam positivos ou negativos
' ' = Coloca um espaço quando o sinal é positivo, e ignora quando é negativo




1º passo:

    Criar uma função que vai ler os argumentos que recebe e direcionar para a função pretendida


2ª passo:

    Fazer as funções para os especificadores
    Verificar se consigo integrar com as flags futuramente

3º passo:

    Fazer o codigo das flags para integrar com os especificadores

4º passo:
*/
