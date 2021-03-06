#include <stdlib.h>
#include <string.h>
#include "../src/crypt.h"

#include "unity.h"
#include "unity_fixture.h"

char fail_message[40] = "This test was meant to fail";


unsigned int input[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

unsigned int key_4[4] = {
   0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
};
unsigned int key_6[6] = { 
   0x78BF328FL, 0x7D52C3A9L, 0x2C937A9FL, 0x5218F39EL,
   0x3F72A512L, 0x3B4C26A6L
};
unsigned int key_8[8] = {
    0x3F72A512L, 0x2C937A9FL, 0xDEADBEEFL, 0x5218F39EL,
    0x3B4C26A6L, 0x01234567L, 0xA2376CFBL, 0x25C3D7A0L
  };

unsigned int XTEA_encoded[4] = {0x089975E9L, 0x2555F334L, 0xCE76E4F2L, 0x4D932AB3L};


unsigned int AES_128_encoded[4] = {0x237549D4L, 0xCDCEA7BEL, 0x0FE7D162L, 0xCC9161D3L};


unsigned int AES_192_encoded[4] = {0x5C69F75CL, 0x7BD3C3EBL, 0xAAD816BEL, 0xB05A9785L};


unsigned int AES_256_encoded[4] = {0x2E3D06DDL, 0x333C7DC3L, 0x8FE99503L, 0x00EACE54L};


unsigned int BLOWFISH_128_encoded[4] = {0x24B9C5E1L, 0xB06FBF71L, 0x5527E5FAL, 0x3502EE1AL};


unsigned int BLOWFISH_192_encoded[4] = {0x57A73CF1L, 0xE9F5774EL, 0x9F46D5CFL, 0x8CF3A0C0L};


unsigned int BLOWFISH_256_encoded[4] = {0x4D0B2FD6L, 0x9C5BEB43L, 0xD5857AB7L, 0x4882A23BL};

  void XTEA_test_encoding(void);
  void XTEA_test_decoding(void);
  void AES_128_test_encoding(void);
  void AES_128_test_decoding(void);
  void AES_192_test_encoding(void);
  void AES_192_test_decoding(void);
  void AES_256_test_encoding(void);
  void AES_256_test_decoding(void);
  void BLOWFISH_128_test_encoding(void);
  void BLOWFISH_128_test_decoding(void);
  void BLOWFISH_192_test_encoding(void);
  void BLOWFISH_192_test_decoding(void);
  void BLOWFISH_256_test_encoding(void);
  void BLOWFISH_256_test_decoding(void);

  //Devem falhar
  void AES_128_encoding_bad_input(void);
  void BLOWFISH_128_encoding_bad_input(void);
  void AES_256_encoding_bad_type(void);
  void AES_192_encoding_bad_type(void);
  void AES_192_encoding_bad_key(void);
  void BLOWFISH_256_decoding_bad_key(void);
  void XTEA_encoding_empty_key(void);
  void XTEA_decoding_empty_input(void);
  void XTEA_decoding_bad_input(void);
  void AES_192_bad_enc_dec(void);
  void BLOWFISH_128_bad_enc_dec(void);











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
void XTEA_test_encoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4);   
   unsigned int output[4];
   crypt(key_4, local_input, 0, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(XTEA_encoded, output, 4);
}

void XTEA_test_decoding(void){
   unsigned int local_input[4];
   memcpy(local_input, XTEA_encoded, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_4, local_input, 0, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void AES_128_test_encoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_4, local_input, 1, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(AES_128_encoded, output, 4);
}

void AES_128_test_decoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_4, local_input, 1, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_4, result, 1, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void AES_192_test_encoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 2, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(AES_192_encoded, output, 4);
}

void AES_192_test_decoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_6, local_input, 2, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_6, result, 2, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void AES_256_test_encoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_8, local_input, 3, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(AES_256_encoded, output, 4);
}

void AES_256_test_decoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_8, local_input, 3, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_8, result, 3, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void BLOWFISH_128_test_encoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_4, local_input, 4, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(BLOWFISH_128_encoded, output, 4);
}

void BLOWFISH_128_test_decoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_4, local_input, 4, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_4, result, 4, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void BLOWFISH_192_test_encoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 5, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(BLOWFISH_192_encoded, output, 4);
}

void BLOWFISH_192_test_decoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_6, local_input, 5, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_6, result, 5, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

void BLOWFISH_256_test_encoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_8, local_input, 6, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY(BLOWFISH_256_encoded, output, 4);
}

void BLOWFISH_256_test_decoding(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_8, local_input, 6, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_8, result, 6, 0, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY(input, output, 4);
}

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

//These tests should fail
//Input smaller than expected
//Doesnt get called, gives out error on Valgrind pass
void AES_128_encoding_bad_input(void){
   unsigned int local_input[3] = {0, 0, 0};
   memcpy(local_input, input, sizeof(unsigned int)*3); 
   unsigned int output[4];
   crypt(key_4, local_input, 1, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(AES_128_encoded, output, 4, fail_message);
}
//Input smaller than expected
void BLOWFISH_128_encoding_bad_input(void){
   unsigned int local_input[3] = {0, 0, 0};
   memcpy(local_input, input, sizeof(unsigned int)*3); 
   unsigned int output[4];
   crypt(key_4, local_input, 4, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(BLOWFISH_128_encoded, output, 4, fail_message);
}
//Type is different than expected for this algorithm
void AES_256_encoding_bad_type(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_8, local_input, 2, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(AES_256_encoded, output, 4, fail_message);
}
//Type value is invalid
//Doesnt get called, gives out error on Valgrind pass
void AES_192_encoding_bad_type(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 9, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(AES_192_encoded, output, 4, fail_message);
}
//Key is smaller than required for this algorithm
void AES_192_encoding_bad_key(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_4, local_input, 2, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(AES_192_encoded, output, 4, fail_message);
}
//Key is smaller than required for this algorithm
void BLOWFISH_256_decoding_bad_key(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 6, 0, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(input, output, 4, fail_message);
}
//Key is an empty array
void XTEA_encoding_empty_key(void){
   unsigned int local_input[4];
   unsigned int key[4] = {0, 0, 0, 0};
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key, local_input, 0, 1, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(input, output, 4, fail_message);
}
//Input is an empty array
void XTEA_decoding_empty_input(void){
   unsigned int local_input[4] = {0, 0, 0, 0};
   unsigned int output[4];
   crypt(key_4, local_input, 6, 0, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(input, output, 4, fail_message);
}
//Input is different from what will be decoded
void XTEA_decoding_bad_input(void){
   unsigned int local_input[4] = {0xAB3225FDL, 0xB42CF926L, 0xB642A0C2L, 0xE67B23C8L};
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_4, local_input, 6, 1, output);
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   crypt(key_4, output, 6, 0, result);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(local_input, result, 4, fail_message);
}
//Enc_dec is not set to encoder
void AES_192_bad_enc_dec(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   crypt(key_6, local_input, 2, 0, output);
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(AES_192_encoded, output, 4, fail_message);
}
//Enc_dec is invalid
void BLOWFISH_128_bad_enc_dec(void){
   unsigned int local_input[4];
   memcpy(local_input, input, sizeof(unsigned int)*4); 
   unsigned int output[4];
   unsigned int result[4];
   crypt(key_4, local_input, 4, 1, output);
   memcpy(result, output, sizeof(unsigned int)*4);
   crypt(key_4, result, 4, 10, output);   
   TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE(input, output, 4, fail_message);
}
