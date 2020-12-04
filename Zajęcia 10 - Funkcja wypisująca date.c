#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900;
}

int main()
{
    // 1.5pkt
    printf("%d", f());
    return 0;
}
