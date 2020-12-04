#include <stdio.h>
#include <stdlib.h>

typedef enum{
    WIADOMOSC_DO_WYBORCOW_PIS = 1,
    WIADOMOSC_DO_WYBORCOW_PO = 2,
    WIADOMOSC_DO_WYBORCOW_KONFEDERACJI = 3
} WiadomosciDoWyborcow;

typedef struct {
    char* Tresc;
    int Liczba;
} Wiadomosc;

typedef union{
    Wiadomosc pis;
    Wiadomosc po;
    Wiadomosc konfederacja;
} Wiadomosci;

typedef struct{
    WiadomosciDoWyborcow enumWiadomosc;
    Wiadomosci wiadomosci;
} WiadomoscDoWyborcow;

void Initialize(WiadomoscDoWyborcow* wdw, Wiadomosci w)
{
    w.pis.Liczba = 1;
    w.pis.Tresc = "Podnosimy podatki! 500+! Andrzej Duda!\n";
    w.po.Liczba = 2;
    w.po.Tresc = "Tylko Trzaskowski! Zna ponad 10 jezykow!\n";
    w.konfederacja.Liczba = 3;
    w.konfederacja.Tresc = "Korwin jest krolem! Gdyby to bylo zle, Bog by inaczej swiat stworzyl!\n";

    wdw[0].enumWiadomosc = 1;
    wdw[1].enumWiadomosc = 2;
    wdw[2].enumWiadomosc = 3;
    for(int i=0;i<3;i++)
    {
        wdw[i].wiadomosci = w;
    }
}

void przekazWiadomoscWyborcomPIS(WiadomoscDoWyborcow* wdw)
{
    printf("Wiadomosci do wyborcow PIS:\n %s \n", wdw[0].wiadomosci.konfederacja.Tresc);
}

void przekazWiadomoscWyborcomPO(WiadomoscDoWyborcow* wdw)
{
    printf("Wiadomosci do wyborcow PO:\n %s \n", wdw[1].wiadomosci.konfederacja.Tresc);
}

void przekazWiadomoscWyborcomKONFEDERACJI(WiadomoscDoWyborcow* wdw)
{
    printf("Wiadomosci do wyborcow Konfederacji:\n %s \n", wdw[2].wiadomosci.konfederacja.Tresc);
}

int main()
{
    // 3pkt
    WiadomoscDoWyborcow* wdw = malloc(sizeof(WiadomoscDoWyborcow)*3);
    Wiadomosci w;
    Initialize(wdw, w);

    przekazWiadomoscWyborcomPIS(wdw);
    przekazWiadomoscWyborcomPO(wdw);
    przekazWiadomoscWyborcomKONFEDERACJI(wdw);
    return 0;
}
