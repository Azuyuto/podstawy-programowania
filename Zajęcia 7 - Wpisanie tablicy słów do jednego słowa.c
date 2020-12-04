#include <stdlib.h>
#include <string.h>

char* append(const char *s, char c) {
    int len = strlen(s);
    char buf[len+2];
    strcpy(buf, s);
    buf[len] = c;
    buf[len + 1] = 0;
    return strdup(buf);
}

char* writeArrayToOneWord(char* arrayString[], int sizeArray)
{
    char *newText = "";
    for(int i=0;i<sizeArray;++i)
    {
        for(int j=0;j<strlen(arrayString[i]);++j)
        {
            newText = append(newText, arrayString[i][j]);
        }
    }
    return newText;
}

int main()
{
    // 2pkt
    const char *arrayString[] = {"Br", "ze", "cz", "ys", "zc", "zy", "ki", "ew", "icz" };
    int rozmiar = sizeof(arrayString) / sizeof(arrayString[0]);
    char *text = writeArrayToOneWord(arrayString, rozmiar);
    printf("%s", text);
    return 0;
}
