/**********************************************************************
 * Copyright (c) 2013, 2014, 2015 Thomas Daede, Cory Fields           *
 * Distributed under the MIT software license, see the accompanying   *
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/

#define USE_BASIC_CONFIG 1

#include "basic-config.h"
#include "include/secp256k1.h"
#include "field_impl.h"
#include "scalar_impl.h"
#include "group_impl.h"
#include "ecmult_gen_impl.h"

static void default_error_callback_fn(const char* str, void* data) {
    (void)data;
    fprintf(stderr, "[libsecp256k1] internal consistency check failed: %s\n", str);
    abort();
}

static const secp256k1_callback default_error_callback = {
    default_error_callback_fn,
    NULL
};

int main(int argc, char **argv) {
    secp256k1_ecmult_gen_context ctx;
    int inner;
    int outer;
    FILE* fp;

    (void)argc;
    (void)argv;

    fp = fopen("ecmult_static_context.hex","w");
    if (fp == NULL) {
        fprintf(stderr, "Could not open ecmult_static_context.hex for writing!\n");
        return -1;
    }
    
    secp256k1_ecmult_gen_context_init(&ctx);
    secp256k1_ecmult_gen_context_build(&ctx, &default_error_callback);

    unsigned char *ptr = (unsigned char *)ctx.prec;
    for (int i = 0; i < sizeof(*ctx.prec) ; ++i) {
        fprintf(fp, "%02x", ptr[i]);
    }

    secp256k1_ecmult_gen_context_clear(&ctx);    
    fclose(fp);

    return 0;
}
