///////////////////////////////////////////////////////////////
//FileName : blockchain.c
//Author: Hanaset;
//Date: 2019.01.31;
///////////////////////////////////////////////////////////////

#pragma warning(disable : 4996)

#include "blockchain.h"

void sha256_conversion(const char input[], BYTE private_key[SHA256_BLOCK_SIZE])
{
	SHA256_CTX ctx;
	int idx;
	int pass = 1;

	sha256_init(&ctx);
	sha256_update(&ctx, input, strlen(input));
	sha256_final(&ctx, private_key);
}

BYTE* priv2pub(const BYTE* private_key, point_conversion_form_t form)
{
	EC_GROUP *ecGrp = EC_GROUP_new_by_curve_name(NID_secp256k1);
	BIGNUM *priv_bn = BN_new();
	BN_hex2bn(&priv_bn, private_key);

	EC_POINT *pub = EC_POINT_new(ecGrp);
	EC_POINT_mul(ecGrp, pub, priv_bn, NULL, NULL, NULL);
	unsigned char *ret = EC_POINT_point2hex(ecGrp, pub, form, NULL);

	EC_GROUP_free(ecGrp);
	BN_free(priv_bn);
	EC_POINT_free(pub);
	return ret;
}

BYTE *priv2pub_bytes(const BYTE *priv_hex, point_conversion_form_t form, BYTE *ret)
{
	EC_GROUP *ecgrp = EC_GROUP_new_by_curve_name(NID_secp256k1);

	BIGNUM *priv_bn = BN_new();
	BN_hex2bn(&priv_bn, priv_hex);

	EC_POINT *pub = EC_POINT_new(ecgrp);
	EC_POINT_mul(ecgrp, pub, priv_bn, NULL, NULL, NULL);

	size_t len = EC_POINT_point2oct(ecgrp, pub, form, NULL, 0, NULL);
	EC_POINT_point2oct(ecgrp, pub, form, ret, len, NULL);

	EC_GROUP_free(ecgrp); BN_free(priv_bn); EC_POINT_free(pub);

	return ret;
}

void hex2char(BYTE* key, char* key_string)
{
	char temp[65] = { 0, };
	//memcpy(key_string, key, SHA256_BLOCK_SIZE);
	for (int i = 0; i < SHA256_BLOCK_SIZE; i++)
	{
		sprintf(temp, "%02x", key[i]);
		strcat(key_string, temp);
	}
	printf("hex2Char Text :\t%s\n", key_string);
}
