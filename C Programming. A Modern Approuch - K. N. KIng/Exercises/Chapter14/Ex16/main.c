#include <stdio.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)
int main() {

    IDENT(foo); ///answer: #pragma ident "foo"
    return 0;
}
