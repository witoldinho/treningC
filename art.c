
#include <stdio.h>
#include <stdlib.h>
#include "art.h"


void konv(uint8_t *pakiet)
{
//ArtDmxPack_t st;
//unia_t *blok;
uint8_t i;
char * napisik="napisal";

blok->st.x=10;
blok->st.y=55;
sprintf((char *)blok->st.napis,napisik,sizeof(napisik));
//memcpy(pakiet,blok->tab,sizeof(blok));
//pakiet=&(uint8_t)blok->tab;
for(i=0;i<24;i++)
{
*(pakiet+i)=blok->tab[i];
}
//blok.tab[0]=blok.st;
//&blok->tab[0]=(st;
}
