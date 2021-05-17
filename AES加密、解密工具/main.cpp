
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include"table.h"
#include"init_key.h"
#include"encrypt.h"
#include"decrypt.h"
int main()
{
	unsigned char key[4][4] = { 0 };
	for (char i = 0; i < 16; i++)key[0][i] = 'a' + i;
	unsigned char sub_key[4][44] = { 0 };
	generate_subkey(key, sub_key);
	unsigned char plaintext[4][4] = { 0 };
	for (char i = 0; i < 16; i++)plaintext[0][i] = 'a' + i;
	plaintext[0][0] = '1';
	unsigned char cipher[4][4] = { 0 };
	encrypt(plaintext, sub_key, cipher);
	printf("cipher:\n");
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("%02x ", cipher[i][j]);
		}
	}
	printf("\n");
	unsigned char dec[4][4];
	decrypt(cipher, sub_key, dec);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("%c ", dec[j][i]);
		}
	}
	printf("\n");
}