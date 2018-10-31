on of whilesum.c that reads from file and writes partial sums
 * to output file.
 *
 * Command-line arguments:
 * input file
 * output file
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) { 
        fprintf(stderr, "usage:  %s infile outfile\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE * infile = fopen(argv[1], "r");
    if (infile == NULL) { 
        fprintf(stderr, "cannot open file %s\n", argv[1]);
        return EXIT_FAILURE; 
    }
    FILE * outfile = fopen(argv[2], "w");
    if (outfile == NULL) { 
        fprintf(stderr, "cannot open file %s\n", argv[2]);
        return EXIT_FAILURE; 
    }

    int sum = 0;
    int n;
    /* slightly cryptic but C-idiomatic .... */
    while (fscanf(infile, "%d", &n) == 1) {
        sum += n;
        fprintf(outfile, "partial sum %d\n", sum);
        /* uncomment to see feof() return value 
        printf("eof on infile?  %c\n", feof(infile) ? 'y' : 'n');
        */
    }
    /* check whether loop stopped because of EOF or error */
    if (!feof(infile)) {
        fprintf(stderr, "bad input\n");
        fclose(infile);
        fclose(outfile);
        return EXIT_FAILURE;
    }
    printf("sum %d\n", sum);
    fclose(infile);
    fclose(outfile);
    return EXIT_SUCCESS;
}

