#include <stdio.h>
#include <stdlib.h>

int Task_1(int tab[], int rozmiar)
{
    int r = 0;
    for(int i = 0;i < rozmiar; ++i)
    {
        r+=tab[i];
    }
    return r;
}

// 1.5pkt
int Task_2(int ileElementow)
{
    int a = 0, b = 1;
    for(int i=0;i<ileElementow;i++)
    {
        b += a;
        a = b-a;
    }
    return b;
}

// 2pkt
void Task_3(int tab[], int n)
{
    double a = 0;
    for(int i=0;i<n;++i)
    {
        a+=(double)tab[i];
    }
    printf("%.3f", a/n);
}

// 1pkt + 0.5pkt
void Task_4(int tab[], int n)
{
    int temp = 0;;
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<n-i;++j)
        {
            if(tab[j-1]>tab[j])
            {
                temp = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = temp;
            }
        }
    }
    if(n%2 == 1)
    {
        printf("%.3f", (double)tab[(n/2)]);
    }
    else
    {
        double srednia = tab[n/2] + tab[(n/2)-1];
        printf("%.3f", srednia/2);
    }
}

int main(int args, char *arg[])
{
    //Task_1
    //int tab[10] = {0,1,2,3,4,5,6,7,8,9};
    //printf("Suma tablicy: %d", Task_1(tab, sizeof(tab)/ sizeof(int)));

    // Task_2
    //printf("Wyraz n: %d", Task_2(5));

    // Task_3
    //int tab[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //Task_3(tab, sizeof(tab)/ sizeof(int));

    // Task_4
    //int tab[10] = { 10,5,6,3,4,2,9,8,7,1 };
    //Task_4(tab, sizeof(tab)/ sizeof(int));

    for(;;)
    {

    }
    return 0;
}
