/**************************************************************************************************
Si scriva un programma C che legga ripetutamente da tastiera un intero n e, fintanto che n > 0,
calcoli per questo n la ridotta n-esima Hn.
***************************************************************************************************/

#include <math.h>
#include <stdio.h>

int main(void)
{
    int n, i;
    float HN;

    printf("Num. di termini (<=0 per finire): ");
    scanf("%d", &n);

    while (n > 0)
    {
        HN = 0.0;
        for (i = 1; i <= n; i++)
            HN = HN + 1.0 / ((float)i);
        printf("Risultato: %f\n", HN);
        printf("Num. di termini (<=0=FINE): ");
        scanf("%d", &n);
    }
}
