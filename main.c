#include <stdio.h>
#include <stdlib.h>
#include "art.h"

uint8_t * bufor;

int main()
{
    printf(" %s \n",(char *)bufor);
    konv(bufor);

    //printf(" %s \n",(char *)bufor);



    return 0;
}
