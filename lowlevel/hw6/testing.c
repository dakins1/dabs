#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("figuring this shit out\n");
    char* lc = "abcdefghijklmnopqrstuvwxyz";    
    char c = lc[2];
    printf("%c\n",c);
    printf("%s\n", &lc[9]);
}
