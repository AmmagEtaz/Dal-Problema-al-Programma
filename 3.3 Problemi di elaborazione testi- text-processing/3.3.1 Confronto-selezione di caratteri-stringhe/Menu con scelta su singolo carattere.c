/********************************************************************************
Si scriva una funzione C che, ripetutamente, acquisisca da tastiera una stringa
(al massimo di 50 caratteri, contenente eventuali spazi). In questa stirnga il
primo carattere diverso da spazio costituisce il selettore. I casi da prevedere
sono i seguenti:

- il carattere selettore è 'U' o 'u'(uscita): uscire dal menu, terminando
  l'iterazione.
- il carattere selettore è 'A' o 'a': chiamare la funzione fA, passando come 
  parametro il resto della stringa
- il carattere selettore è 'L' o 'l': chiamare la funzione fL, passando come
  parametro il resto della stringa
- il carattere selettore è 'T' o 't': chiamare la funzione fT, passando come
  parametro il resto della stringa
- ogni altro carattere selettore va segnalato come errato
*********************************************************************************/

#include <stdio.h>
#include <ctype.h>

void menuCarattere(void);
void fA(char s[]);
void fL(char s[]);
void fT(char s[]);

int main(void)
{
    menuCarattere();
}

void menuCarattere(void)
{
    const int MAXL = 51;
    char riga[MAXL];
    int i, continua = 1;

    while(continua)
    {
        printf("comando (A/L/T, U=uscita): ");
        gets(riga);
        for(i = 0; riga[i] == ' '; i++)
        {
            switch(toupper(riga[i]))
            {
                case 'A': fA(&riga[i+1]);
                    break;
                case 'L': fL(&riga[i+1]);
                    break;
                case 'T': fT(&riga[i+1]);
                    break;
                case 'U': continua = 0;
                    break;
                default: printf("comando errato\n");
            }
        }
    }
}

void fA(char s[])
{
    printf("Questa è la funzione fA\n");
}

void fL(char s[])
{
    printf("Questa è la funzione fL\n");
}

void fT(char s[])
{
    printf("Questa è la funzione fT\n");
}
