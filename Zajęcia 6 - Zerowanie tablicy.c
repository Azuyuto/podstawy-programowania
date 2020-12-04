#include <stdio.h>
#include <stdlib.h>

int* pustaTablica(int rozmiar)
{
    int *tab=calloc(rozmiar,sizeof(int)*8);
    return tab;
}

int main()
{
    // 1.5pkt
    int n = 100;
    int* tab = pustaTablica(n);
    for(int i=0;i<n;++i)
    {
        printf("%d ", tab[i]);
    }

    free(tab);
    return 0;
}
