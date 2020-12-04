#include <stdio.h>
#include <stdlib.h>

void swapText(char *a, char *b, int size)
{
    char t;
    for(int i=0;i<size;i++)
    {
        t=a[i];
        a[i]=b[i];
        b[i]=t;
    }
}

int main()
{
    // 1.5 pkt
    char a[7] = "Trumpp";
    char b[7] = "Bidden";
    printf("Text a: %s, Text b: %s\n", a, b);
    swapText(a,b,7);
    printf("Text a: %s, Text b: %s", &a, &b);
    return 0;
}
