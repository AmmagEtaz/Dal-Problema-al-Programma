/****************************************************************************
Sia dato un file di testo, il cui nome (stringa di al massimo 30 caratteri,
terminatore incluso) è letto da tastiera. Si scriva un programma C che,
letto il file, modifichi la codifica di ciascuno dei suoi caratteri secondo
le seguenti regole:
- la codifica n di ogni cifra decimale 0...9 viene trasformata nella
codifica complemento-a-9 (9-n)
- ogni lettera minuscola a ... z viene trasformata nella corrispondente 
maiuscola e la codifica ch così ottenuta viene trasformata nella codifica
complemento-a-'Z'
-ogni lettera maiuscola A ... Z viene trasformata nella corrispondente 
minuscola e la codifica ch così ottenuta viene trasformata nella codifica
complement-a-'z'
****************************************************************************/

#include <stdio.h>

#define MAXRIGA 10

int main(void)
{
    char ch, nomefile[MAXRIGA];
    FILE *fpin, *fpout;

    printf("nome file in ingresso: ");
    scanf("%s", nomefile);
    fpin = fopen(nomefile, "r");
    printf("nome file in uscita: ");
    scanf("%s", nomefile);
    fpout = fopen(nomefile, "w");

    while (fscanf(fpin, "%c", &ch) == 1) {
        if (ch >= '0' && ch <= '9')
            ch = '0'+ ('9' - ch);
        else if (ch >= 'a' && ch <= 'z')
            ch = 'A' + ('z' - ch);
        else if (ch >= 'A' && ch <= 'Z')
            ch = 'a' + ('Z' - ch);
        fprintf(fpout, "%c", ch);
    }

    fclose(fpin); fclose(fpout);
}
