/************************************************************************************************
Dato un intero positivo n, si scriva una funzione C che, ricevendo tale numero come parametro, 
ne determini la codifica binaria sul minimo numero di bit.
************************************************************************************************/

void binario(int n)
{
    int p;

    for (p = 1; 2 * p <= n; p = p * 2);
    
    while (p > 0)   
    {
        if (p <= n)
        {
            printf("1");
            n = n - p;
        }
        else
            printf("0");
        p = p / 2;
    }
}
