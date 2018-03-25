#ifndef ART_H_INCLUDED
#define ART_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>

#endif // ART_H_INCLUDED

typedef struct
{
int8_t x;
uint8_t y;
char napis[20];
uint16_t zm16;
}ArtDmxPack_t;

union unia_t
{
//ArtDmxPack_t art;
ArtDmxPack_t st;
uint8_t tab[24];
}*blok;
//unia_t blok;
void konv(uint8_t *pakiet);
