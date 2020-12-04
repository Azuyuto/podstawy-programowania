#include <stdio.h>
#include <stdlib.h>
#include "cJSON-master/cJSON.h"

int main()
{
    FILE *fp;
    char buffer[1024];

    fp = fopen("Zajêcia 9 - Wczytywanie pliku json.json", "r");
    fread(buffer, 1024, 1, fp);
    fclose(fp);

    cJSON *json = cJSON_Parse(buffer);
    char *string = cJSON_Print(json);

    printf("%s\n", string);
    return 0;
}
