/******************************************************************************************************************
Sia dato un triangolo rettangolo di cui sono note le lunghezze (intere) dei tre lati a, b e c.
Si scriva un programma C che legga le lunghezze dei tre lati, determini quale dei lati sia l'ipotenusa e calcoli
l'area del triangolo.
*******************************************************************************************************************/

#include <math.h>
#include <stdio.h>

int main(void)
{
    int a, b, c;
    float area;

    /*lettura da tastiera*/
    printf("Scrivi il primo lato: ");
    scanf("%d", &a);
    printf("Scrivi il secondo lato: ");
    scanf("%d", &b);
    printf("Scrivi il terzo lato: ");
    scanf("%d", &c);

    /*confronti*/
    if(a > b) /*l'ipotenusa non è b*/
    {
        if(a > c)
        {
            printf("L'ipotenusa e' il primo lato\n");
            area = ((float) (b * c)) / 2.0;
        }
        else
        {
            printf("L'ipotenusa e' il terzo lato\n");
            area = ((float) (a * b)) / 2.0;
        }
    }
    else /*l'ipotenusa non è a*/
    {
        if(b > c)
        {
            printf("L'ipotenusa e' il secondo lato\n");
            area = ((float) (a * c) / 2.0);
        }
        else
        {
            printf("L'ipotenusa e' il terzo lato\n");
            area = ((float) (a * b) / 2.0);
        }
    }
    /*Visualizzazione dell'area*/
    printf("Area = %f\n", area);

}
