// FILE NAME  : crypt.h
// AUTHOR     : Rafael Garibotti
// DEVELOPERS : Rafael Garibotti
// E-mail     : rafael.garibotti@pucrs.br
//-----------------------------------------------------------------------------
// RELEASE HISTORY
// VERSION   DATE         DESCRIPTION
// 1.0       2021-06-08   Initial version.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdint.h>

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
void aes(uint32_t* key, uint32_t* input, uint8_t type, uint8_t enc_dec, uint32_t* output);

void blowfish_128(unsigned int* key, unsigned int* input, int type, int enc_dec, unsigned int *output);

void xtea(unsigned int* key, unsigned int* input, int enc_dec, unsigned int *output);

void crypt(uint32_t* key, uint32_t* input, uint8_t type, uint8_t enc_dec, uint32_t* output);
