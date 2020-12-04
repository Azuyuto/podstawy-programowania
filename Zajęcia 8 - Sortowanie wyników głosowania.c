#include <stdio.h>
#include <stdlib.h>

#define IloscWynikow 5

typedef struct
{
    char * nazwisko;
    int glosy;
} Wynik;

void wypelnijWyniki(Wynik* wyniki)
{
    wyniki[0].nazwisko = "Joe Biden";
    wyniki[0].glosy = 67000000;

    wyniki[1].nazwisko = "Donald Trump";
    wyniki[1].glosy = 63000000;

    wyniki[2].nazwisko = "Kayne West";
    wyniki[2].glosy = 56000;

    wyniki[3].nazwisko = "Andrzej Duda";
    wyniki[3].glosy = 9500000;

    wyniki[4].nazwisko = "Rafal Trzaskowski";
    wyniki[4].glosy = 63000000;
}

int compare (const void * a, const void * b)
{
    const Wynik *wynikA = a;
    const Wynik *wynikB = b;

    return (wynikB->glosy - wynikA->glosy);
}

void sortujWynikiWyborcze(Wynik* wyniki)
{
    qsort(wyniki, IloscWynikow, sizeof(Wynik), compare);
}

void wypisz(Wynik* wyniki)
{
    for(int i=0; i<IloscWynikow; i++)
    {
        printf("%s - %d\n",wyniki[i].nazwisko, wyniki[i].glosy);
    }
}

int main()
{
    // 2.5pkt
    Wynik wyniki[IloscWynikow];
    wypelnijWyniki(wyniki);
    sortujWynikiWyborcze(wyniki);
    wypisz(wyniki);
    return 0;
}
