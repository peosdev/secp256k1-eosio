/**********************************************************************
 * Copyright (c) 2013, 2014, 2015 Thomas Daede, Cory Fields           *
 * Distributed under the MIT software license, see the accompanying   *
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/

#define USE_BASIC_CONFIG 1

#include <stdio.h>
#include "bullet-config.h"
#include "include/secp256k1.h"
#include "group.h"
#include "include/secp256k1_bulletproofs.h"

struct secp256k1_bulletproof_generators
{
    size_t n;
    secp256k1_ge *gens;
    secp256k1_ge *blinding_gen;
};

int main(int argc, char **argv) {
    int inner;
    int outer;
    FILE* fp;

    (void)argc;
    (void)argv;

    fp = fopen("bulletproof_generators.hex","w");
    if (fp == NULL) {
        fprintf(stderr, "Could not open bulletproof_generators.hex for writing!\n");
        return -1;
    }

    secp256k1_context *ctx2 = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);

    int gcount = 128;

    secp256k1_bulletproof_generators *gens = secp256k1_bulletproof_generators_create(ctx2, &secp256k1_generator_const_h, gcount);

    unsigned char *ptr = (unsigned char *)gens->gens;
    size_t count = (gcount + 1) * sizeof(secp256k1_ge);
    for (int i = 0; i < count ; ++i) {
        fprintf(fp, "%02x", ptr[i]);
    }
 
    fclose(fp);

    return 0;
}
