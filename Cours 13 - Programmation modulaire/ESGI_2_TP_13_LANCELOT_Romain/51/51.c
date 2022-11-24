#include <stdio.h>
#include <stdlib.h>

#define DO_PROFILE
#include "profile.h"

#ifdef DO_PROFILE

START_FUNCTION(int, f, int x)
END_FUNCTION(x * x)

START_FUNCTION(int, main)
    int a = 42;
    a = f(a);
    printf("a = %d\n", a);
    exit(EXIT_SUCCESS);
END_FUNCTION(0)

#else

int f(int x) {
    return x * x;
}

int main() {
    int a = 42;
    a = f(a);
    printf("a = %d\n", a);
    exit(EXIT_SUCCESS);
    return 0;
}

#endif