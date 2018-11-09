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

    printf("Lati del triangolo (a b c): ");
    scanf("%d%d%d", &a, &b, &c);

    if(a > b && a > c)
    {
        printf("L'ipotenusa e' a\n");
        area = b * c / 2.0;
    }
    else if(b > a && b > c)
    {
        printf("L'ipotenusa e' b\n");
        area = a * c / 2.0;
    }
    else if(c > a && c > b)
    {
        printf("L'ipotenusa e' c\n");
        area = b * c / 2.0;
    }
    printf("L'area e': %f\n", area);
}
