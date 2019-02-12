#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha256.h"
#include <openssl/ec.h>
#include <openssl/bn.h>
#include <openssl/obj_mac.h>

void sha256_conversion(const char input[], BYTE private_key[SHA256_BLOCK_SIZE]);
void hex2char(BYTE* key, char* key_string);
BYTE* priv2pub(const BYTE* private_key, point_conversion_form_t form);
BYTE* priv2pub_bytes(const BYTE* priv_hex, point_conversion_form_t form, BYTE* ret);
