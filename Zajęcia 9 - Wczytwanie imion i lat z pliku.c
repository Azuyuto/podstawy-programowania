#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeNormal(char *zdanie, int size)
{
    int j=0;
    for(int i=0;i<size;++i)
    {
        if(zdanie[i]==' ')
        {
            j++;
        }
        if((j==1 || j==3) && zdanie[i]!=' ' && zdanie[i]!=',')
        {
            printf("%c", zdanie[i]);
        }
        if(zdanie[i]==',')
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    FILE* file = fopen("Zajêcia 9 - Wczytwanie imion i lat z pliku.txt", "r");
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        writeNormal(line, (int)strlen(line));
    }

    fclose(file);
    return 0;
}
