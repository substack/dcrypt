#include "common.h"
#include "random.h"
#include "hash.h"
#include "sign.h"
#include "verify.h"
#include "keypair.h"
#include "encode.h"

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

#include <openssl/ssl.h>
#include <openssl/err.h>


using namespace v8;
using namespace node;

extern "C" {
  static void init(Handle<Object> target) {
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    OpenSSL_add_all_digests();
    SSL_load_error_strings();
    ERR_load_crypto_strings();
    
    Random::Initialize(target);
    Hash::Initialize(target);
    Sign::Initialize(target);
    Verify::Initialize(target);
    KeyPair::Initialize(target);
    Encode::Initialize(target);
  }
  NODE_MODULE(dcrypt, init);
}

