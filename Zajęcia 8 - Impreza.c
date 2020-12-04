#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IloscImp 10
#define IloscAlk 5
#define AlkMl 1000

typedef struct{
    char* imie;
    int waga;
    double promileAlkoholu;
} imprezowicz;

typedef struct{
    double procent;
    char* nazwa;
} alkohol;

void wypelnijDane(imprezowicz* imp)
{
    for(int i=0;i<IloscImp;i++)
    {
        imp[i].promileAlkoholu = 0;
    }
    imp[0].imie = "Jacek";
    imp[0].waga = 75;

    imp[1].imie = "Krystian";
    imp[1].waga = 73;

    imp[2].imie = "Dawid";
    imp[2].waga = 93;

    imp[3].imie = "Pawel";
    imp[3].waga = 77;

    imp[4].imie = "Mikolaj";
    imp[4].waga = 70;

    imp[5].imie = "Jacek";
    imp[5].waga = 75;

    imp[6].imie = "Daniel";
    imp[6].waga = 94;

    imp[7].imie = "Tomek";
    imp[7].waga = 83;

    imp[8].imie = "Wojtek";
    imp[8].waga = 92;

    imp[9].imie = "Julek";
    imp[9].waga = 73;
}

void wypelnijDaneAlkohol(alkohol* alk)
{
    alk[0].procent = 40;
    alk[0].nazwa = "Czysta Vodka";

    alk[1].procent = 8;
    alk[1].nazwa = "Piwo";

    alk[2].procent = 12;
    alk[2].nazwa = "Wino";

    alk[3].procent = 40;
    alk[3].nazwa = "Whiskey";

    alk[4].procent = 30;
    alk[4].nazwa = "Rum";
}

double GetBloodByKg(int kg)
{
    return kg*0.75;
}

void kolejka(imprezowicz* imp, alkohol alk, int ilosc)
{
    for(int i=0;i<IloscImp;i++)
    {
        imp[i].promileAlkoholu += (((alk.procent/100)*ilosc*AlkMl)/IloscImp)/GetBloodByKg(imp[i].waga);
    }
}

int odplyneli(imprezowicz* imp)
{
    int r=0;
    for(int i=0;i<IloscImp;i++)
    {
        if(imp[i].promileAlkoholu > 2)
        {
            r++;
        }
    }
    return r;
}

void impreza(imprezowicz* imp, alkohol* alk)
{
    while(odplyneli(imp) != IloscImp)
    {
        alkohol a = alk[rand() % 5];
        int ilosc = rand() % 2 + 1;
        kolejka(imp, a, ilosc);
        printf("Wszyscy pija %s, w ilosci %d. \n", a.nazwa, ilosc);
        printf("Ilosc wstaniowych: %d.\n", odplyneli(imp));
    }

    printf("\n === Wszyscy zezgonowali. === \n\n");
}

int main()
{
    // 2.5pkt
    srand(time(NULL));
    imprezowicz imp[IloscImp];
    alkohol alk[IloscAlk];
    wypelnijDane(imp);
    wypelnijDaneAlkohol(alk);

    impreza(imp, alk);

    printf("Tablica wynikow w promilach:\n");
    for(int i=0;i<IloscImp;i++)
    {
        printf("%s %.3f \n", imp[i].imie, imp[i].promileAlkoholu);
    }
    return 0;
}
