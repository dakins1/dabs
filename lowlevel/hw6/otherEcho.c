#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("arg %d is %s\n", i, argv[i]);
        char *endptr;
        int n = strtol(argv[i], &endptr, 10);
        if (*endptr == '\0') {
            printf("integer:  %d\n", n);
        }
        else {
            printf("not integer -- stopped at char '%c'\n", *endptr);
        }
        double d = strtod(argv[i], &endptr);
        if (*endptr == '\0') {
            printf("double:  %g\n", d);
        }
        else {
            printf("not double -- stopped at char '%c'\n", *endptr);
        }
        printf("\n");
    }
    return 0;
}
