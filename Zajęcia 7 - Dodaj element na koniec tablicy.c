#include <stdio.h>
#include <stdlib.h>

int* push_back(int* array, int rozmiar, int number)
{
    array = realloc(array, (rozmiar+1) * sizeof(int));
    array[rozmiar-1] = number;
    return array;
}

int main()
{
    // 1.5pkt
    int* array = malloc(sizeof(int));
    array[0] = 1;

    int rozmiar = sizeof(array)/sizeof(int);

    array = push_back(array, ++rozmiar, 2);
    array = push_back(array, ++rozmiar, 3);

    for(int i=0;i<rozmiar;++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
