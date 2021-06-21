#include <stdlib.h>
#include <sys/stat.h>
#include "src/aes.h"
#include "src/blowfish.h"
#include "src/crypt.h"
#include "src/xtea.h"

#include "unity.h"
#include "unity_fixture.h"



TEST_GROUP(identifier);

TEST_SETUP(identifier)
{
}

TEST_TEAR_DOWN(identifier)
{
}

//These test should pass
void Input1(void){
   int result = (system("echo 'a' | ./src/identifier")) >> 8;
   //OK
   TEST_ASSERT_EQUAL_INT(0, result);
}

void Input2(void){
   int result = (system("echo 'ab' | ./src/identifier")) >> 8;
   //OK
   TEST_ASSERT_EQUAL_INT(0, result);
}

void Input3(void){
   int result = (system("echo 'abc' | ./src/identifier")) >> 8;
   //OK
   TEST_ASSERT_EQUAL_INT(0, result);
}

void Input4(void){
   int result = (system("echo 'abcd' | ./src/identifier")) >> 8;
   //OK
   TEST_ASSERT_EQUAL_INT(0, result);
}

void Input5(void){
   int result = (system("echo 'abcde' | ./src/identifier")) >> 8;
   //OK
   TEST_ASSERT_EQUAL_INT(0, result);
}

void NumeroNoMeio(void)
{
   int result = (system("echo 'A123e' | ./src/identifier")) >> 8;
   //OK
   TEST_ASSERT_EQUAL_INT(0, result);
}

//These test should fail
void PrimeiroNumero(void)
{
   int result = (system("echo '123e' | ./src/identifier")) >> 8;
   //Primeiro character é um número
   TEST_ASSERT_EQUAL_INT(1, result);
}

void Numero(void){
   int result = (system("echo '1' | ./src/identifier")) >> 8;
   //Somente numero
   TEST_ASSERT_EQUAL_INT(1, result);
}

void NumeroMaxCh(void)
{
  int result = (system("echo 'a23elKz' | ./src/identifier")) >> 8;
  //Tamanho maior que 6
  TEST_ASSERT_EQUAL_INT(1, result);
}

void StringVazio(void)
{
  int result = (system("echo '      ' | ./src/identifier")) >> 8;
  //Empty string
  TEST_ASSERT_EQUAL_INT(1, result);
}

void CaracterEspecial(void)
{
  int result = (system("echo 'a23%el' | ./src/identifier")) >> 8;
  //String with special characters
  TEST_ASSERT_EQUAL_INT(1, result);
}

void SomenteNumeros(void)
{
  int result = (system("echo '234' | ./src/identifier")) >> 8;
  //String with numbers
  TEST_ASSERT_EQUAL_INT(1, result);
}
















