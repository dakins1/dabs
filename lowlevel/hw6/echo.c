/*
on of echo-text.c that copies from input file to output file,
 * counting characters.
 *
 * Filenames are specified with command-line arguments.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotate(int inchar, int positions_to_rotate);

int main(int argc, char *argv[]) {
    if (argc != 4) { 
        //printf("usage:  %s infile outfile\n", argv[0]);
        printf("You dun goofed, need more command line arguments\n");
        return 1;
    }

    char *endptr;
    int rotateValue = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        printf("Non-numeric value\n");
        return 1;
    }

    FILE * instream = fopen(argv[2], "r");
    if (instream == NULL) { 
        printf("cannot open file %s\n", argv[1]);
        return 1;
    }
    FILE * outstream = fopen(argv[3], "w");
    if (outstream == NULL) { 
        printf("cannot open file %s\n", argv[2]);
        return 1;
    }
    /*This is where your code will go*/

    int ch;
    int count = 0;
    while ((ch = fgetc(instream)) != EOF) {
        //rotate(ch, rotateValue);
        fputc(rotate(ch, rotateValue),outstream); 
        count += 1;
    }
    fprintf(stdout, "%d characters echoed\n", count);
    fclose(instream);
    fclose(outstream);
    return 0;

}
    int rotate(int inchar, int positions_to_rotate) {
        char* lc_alphabet = "abcdefghijklmnopqrstuvwxyz";
        char* uc_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        char* in_lc_alphabet = strchr(lc_alphabet, inchar);
        char* in_uc_alphabet = strchr(uc_alphabet, inchar);
        if (in_lc_alphabet != NULL) {
            int position_in_alphabet = in_lc_alphabet - lc_alphabet;
            int new_pos = position_in_alphabet + positions_to_rotate;
            if (new_pos >= strlen(lc_alphabet)) new_pos = new_pos%(strlen(lc_alphabet));
            char new_char = lc_alphabet[new_pos];
            return new_char;
       } else if (in_uc_alphabet != NULL) {
        
            int position_in_alphabet = in_uc_alphabet - uc_alphabet;
            int new_pos = position_in_alphabet + positions_to_rotate;
            if (new_pos >= strlen(uc_alphabet)) new_pos = new_pos%(strlen(uc_alphabet));
            char new_char = uc_alphabet[new_pos];
            return new_char;
        } else return inchar;

    }

