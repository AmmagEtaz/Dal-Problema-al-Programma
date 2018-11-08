/********************************************************************************
Date 2 basi b0 e b1 entrambe comprese tra 2 e 9, convertire un numero intero
senza segno espresso in base0 in base b1.
Si scriva un programma C che applichi la conversione precedente a una 
sequenza in ingresso di numeri interi senza segno in case b0 visualizzando
in uscita i corrispondenti numeri in base b1.
Detti numero sono composti da un numero arbitrario di cifre e sono separati
tra di loro o da spazi o da a-capo. 
La sequenza termina quando si immette una cifra non ammessa nella base b0,
cioè non compresa nell'intervallo [0...b0-1].
*********************************************************************************/

#include <stdio.h>

void converti(int n, int b);

int main(void)
{
    int b0, b1, n, p, cifra, fine = 0;
    char c;

    printf("b0 (2..9): ");
    scanf("%d", &b0);
    printf("(b1 (2..9): ");
    scanf("%d\n", &b1);

    n = 0;
    while (!fine)
    {
        scanf("%c", &c);
        if (c ==' ' || c == '\n')
        {
            converti(n, b1);
            n = 0;
        }
        else
        {
            cifra = c - '0';
            if (cifra >= 0 && cifra < b0)
                n = b0 * n + cifra;
            else
                fine = 1;
        }
    }
}

void converti(int n, int b)
{
    int p;

    for (p = 1; b * p <= n; p = p * b);

    while (p > 0)
    {
        if(p <= n)
        {
            printf("%d", n / p);
            n = n % p;
        }
        else
            printf("0");
        p = p / b;
    }

    printf("\n");
}


