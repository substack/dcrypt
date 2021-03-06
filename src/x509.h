#ifndef __NODE_DCRYPT_X509_H__
#define __NODE_DCRYPT_X509_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>
#include <node_buffer.h>

#include <openssl/x509v3.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "common.h"

using namespace v8;
using namespace node;

class x509: node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    static void Initialize(Handle<Object> target);
    int mkcert(X509 **x509p, EVP_PKEY **pkeyp, int bits, int serial, int days);
    int add_ext(X509 *cert, int nid, char *value);
    x509();


  protected:
    static Handle<Value> New(const Arguments &args);

  private:
    ~x509();
}
#endif

