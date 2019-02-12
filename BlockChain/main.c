///////////////////////////////////////////////////////////////
//FileName : main.c
//Author: Hanaset;
//Date: 2019.01.31;
///////////////////////////////////////////////////////////////
#pragma warning(disable : 4996)

#include "sha256.h"
#include "blockchain.h"

int main()
{
	char input[] = { "abc" };
	BYTE private_key[SHA256_BLOCK_SIZE] = { 0, };
	char privkey_string[65] = { 0, };
	
	int i;

	printf("Source :\t%s\n", input);
	sha256_conversion(input, private_key);
	printf("Private Key :\t");
	sha256_print(private_key);

	//hex2char(private_key, privkey_string);

	BYTE* public_key = priv2pub(private_key, POINT_CONVERSION_UNCOMPRESSED);

	printf("Public Key :\t");
	sha256_print(public_key);
	getch();
	return(0);
}
