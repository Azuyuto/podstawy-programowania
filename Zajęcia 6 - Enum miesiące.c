#include <stdio.h>
#include <stdlib.h>

enum Miesiace
{
    Styczen = 1,
    Luty = 2,
    Marzec = 3,
    Kwiecien = 4,
    Maj = 5,
    Czerwiec = 6
};

enum Miesiace podajLP(char slowo[])
{
    enum Miesiace miesiac;
    if(strcmp(slowo, "Styczen") == 0)
        miesiac = Styczen;
    else if(strcmp(slowo, "Luty") == 0)
        miesiac = Luty;
    else if(strcmp(slowo, "Marzec") == 0)
        miesiac = Marzec;
    else if(strcmp(slowo, "Kwiecien") == 0)
        miesiac = Kwiecien;
    else if(strcmp(slowo, "Maj") == 0)
        miesiac = Maj;
    else if(strcmp(slowo, "Czerwiec") == 0)
        miesiac = Maj;
    else
        return 0;
    return miesiac;
}

int main()
{
    // 1.5pkt
    char slowo[100];
    scanf("%s", slowo);
    printf("%d\n", podajLP(slowo));

    // 2pkt
    for(int i=Styczen;i<=Czerwiec;++i)
    {
        printf("%d ", i);
    }
    return 0;
}
