/************************************************************************************************
Problema:
Siano dati i tre coefficienti a, b e c di un'equazione di II grado del tipo ax^2+bx+c = 0.
Si scriva un programma C che legga i 3 coefficienti e determini le soluzioni dell'equazione.
*************************************************************************************************/

#include <math.h>
#include <stdio.h>

int main(void)
{
    float a, b, c, delta, x0, x1, x2, re, im;

    printf("Coefficienti (a, b, c): ");
    scanf("%f%f%f", &a, &b, &c);

    if(a == 0 && b == 0 && c == 0)
        printf("Equazione Indeterminata\n");
    if(a == 0 && b == 0 && c != 0)
        printf("Equazione impossibile\n");
    if(a == 0 && b != 0)
    {
        printf("Equazione di I grado\n");
        printf("Soluzione: %f\n, ");
    }
    if(a != 0) 
    {
        delta = b * b - 4 * a * c;
        if(delta == 0)
        {
            x0 = (-b) / (2 * a);
            x1 = (-b) / (2 * a);
            printf("2 soluzioni reali coincidenti: %f %d\n", x0, x1);
        }
        if(delta > 0)
        {
            x0 = (-b - sqrt(delta)) / (2 * a);
            x1 = (-b + sqrt(delta)) / (2 * a);
            printf("2 soluzioni reali distinte: %f %f\n", x0, x1);
        }
        if(delta < 0)
        {
            re = -b/(2 * a);
            im = sqrt(-delta)/(2 * a);
            printf("\n2 soluzioni complesse coniugate: ");
            printf("\nx0 = %f - i * %f\nx1 = %f + i * %f\n\n", re, im, re, im);
        }           
    }
}
