#include <stdlib.h>
#include <string.h>
#include "../src/crypt.h"

#include "unity.h"


const unsigned int input[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

const unsigned int key_4[4] = {
   0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
};
const unsigned int key_6[6] = { 
   0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
   0xDEADBEEFL, 0x01234567L
};
const unsigned int key_8[8] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
  };

const unsigned int XTEA_encoded[4] = {0x089975E9L, 0x2555F334L, 0xCE76E4F2L, 0x4D932AB3L};


const unsigned int AES_128_encoded[4] = {0x237549D4L, 0xCDCEA7BEL, 0x0FE7D162L, 0xCC9161D3L};


const unsigned int AES_192_encoded[4] = {0xEBB4CD9EL, 0xDA7CBDE0L, 0x9E520F4CL, 0x54BE5A98L};


const unsigned int AES_256_encoded[4] = {0x206BF119L, 0x7A085AC8L, 0xB31B2AD0L, 0x4843FFC1L};


const unsigned int BLOWFISH_128_encoded[4] = {0x24B9C5E1L, 0xB06FBF71L, 0x5527E5FAL, 0x3502EE1AL};


const unsigned int BLOWFISH_192_encoded[4] = {0xA5E31925L, 0x25FE7048L, 0x4254F298L, 0x4B71D955L};


const unsigned int BLOWFISH_256_encoded[4] = {0x24B9C5E1L, 0xB06FBF71L, 0x5527E5FAL, 0x3502EE1AL};









TEST_SETUP(Crypt)
{
}

TEST_TEAR_DOWN(Crypt)
{
}

// void crypt (unit32_t* key, uint32_t* input, uint8_t type, uint8_t enc_dec, uint32_t* output);
//
// type 
// 0 = XTEA
// 1 = AES-128
// 2 = AES-192
// 3 = AES-256
// 4 = BLOWFISH-128
// 5 = BLOWFISH-192
// 6 = BLOWFISH-256
//
// enc_dec
// 0 = decoder
// 1 = encoder

//These test should pass
void XTEA_test_encoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4);   
   unsigned int output[4];
   crypt(key_4, local_input, 0, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(XTEA_encoded, output, 4);
}

void XTEA_test_decoding(){
   unsigned int local_input[4];
   memcpy(local_input, XTEA_encoded, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_4, local_input, 0, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void AES_128_test_encoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 1, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(AES_128_encoded, output, 4);
}

void AES_128_test_decoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_4, local_input, 1, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_4, result, 1, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void AES_192_test_encoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 2, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(AES_192_encoded, output, 4);
}

void AES_192_test_decoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_6, local_input, 2, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_6, result, 2, 0, output);   
   TEST_ASSERT_EQUAL_INT32_ARRAY(input, output, 4);
}

void AES_256_test_encoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_8, local_input, 3, 1, output);
   TEST_ASSERT_EQUAL_INT32_ARRAY(AES_256_encoded, output, 4);
}

void AES_256_test_decoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_8, local_input, 3, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_8, result, 3, 0, output);   
   TEST_ASSERT_EQUAL_INT32_ARRAY(input, output, 4);
}

void BLOWFISH_128_test_encoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_4, local_input, 4, 1, output);
   TEST_ASSERT_EQUAL_INT32_ARRAY(BLOWFISH_128_encoded, output, 4);
}

void BLOWFISH_128_test_decoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_4, local_input, 4, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_4, result, 4, 0, output);   
   TEST_ASSERT_EQUAL_INT32_ARRAY(input, output, 4);
}

void BLOWFISH_192_test_encoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 5, 1, output);
   TEST_ASSERT_EQUAL_INT32_ARRAY(BLOWFISH_192_encoded, output, 4);
}

void BLOWFISH_192_test_decoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_6, local_input, 5, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_6, result, 5, 0, output);   
   TEST_ASSERT_EQUAL_INT32_ARRAY(input, output, 4);
}

void BLOWFISH_256_test_encoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_8, local_input, 6, 1, output);
   TEST_ASSERT_EQUAL_INT32_ARRAY(BLOWFISH_256_encoded, output, 4);
}

void BLOWFISH_256_test_decoding(){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_8, local_input, 6, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_8, result, 6, 0, output);   
   TEST_ASSERT_EQUAL_INT32_ARRAY(input, output, 4);
}

















