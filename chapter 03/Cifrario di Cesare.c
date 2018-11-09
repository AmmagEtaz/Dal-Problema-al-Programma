/*********************************************************************************************************
Sia dato un file di testo. Si modifichi la codifica dei suoi caratteri secondo il cifrario di Cesare.
Il nome del file di testo viene dato su linea di comando dall'utente. 
Il file è codificato secondo lo standard ASCII, che non prevede le lettere accentate.
Si ricordi che il cifrario di Cesare è uno dei più antichi algoritmi criptografici: è un cifrario
a sostituzione monoalfabetica, in cui ogni lettera del testo in chiaro è sostituita nel testo
cifrato dalla lettera che si trova ad un certo numero di posizioni prima/dopo nell'alfabeto;
la sostituzione viene effettuata lettera per lettera, scorrendo il testo dall'inizio alla fine.
*********************************************************************************************************/

#include <stdio.h>
#include <ctype.h>

#define N_LETTERE 26 //alfabeto inglese

int main(int argc, char* argv[])
{
    int i, passo;
    char carattere;

    FILE *fp_in = NULL;
    FILE *fp_out = NULL;

    if (argc != 3) {
        printf("Errore, numero errato di parametri\n");
        return -1;
    }

    fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        printf("Errore, impossibile aprire il file %s\n", argv[1]);
    }

    fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Errore, impossibile aprire il file %s\n", argv[2]);
        return -1;
    }

    printf("Inserire lo spostamento della codifica: ");
    scanf("%d", &passo);

    if (passo == 0 || passo == N_LETTERE) {
        printf("Con il passo inserito il testo resta in chiaro!\n");
    }

    if (passo < 0) {
        passo = N_LETTERE + passo;
    }

    while( (carattere = fgetc(fp_in)) != EOF) {
        if (isalpha(carattere) != 0) {
            if (islower(carattere) != 0) {
                carattere = ((carattere - 'a' + passo) % N_LETTERE) + 'a';
            }
            else {
                carattere = ((carattere - 'A' + passo) % N_LETTERE) + 'A';
            }
        }
        fputc(carattere, fp_out);
    }

    printf("Cifrato con passo %d salvato nel file %s\n", passo, argv[2]);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
