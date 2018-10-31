/*
 * to output file.
 *
 * Command-line arguments:
 * input file
 * output file
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 100

int find_out_of_order(int a[], int size);
void sort(int a[], int size);

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

    int data[MAX_COUNT];
    int sum = 0;
    int n;
    /* slightly cryptic but C-idiomatic .... */
    int cnt = 0;
    while (fscanf(infile, "%d", &n) == 1) {
        data[cnt] = n;
        cnt++;
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
    sort(data, cnt);
    int out_of_order = find_out_of_order(data, cnt);
    if (out_of_order < 0) {
        printf("sorted\n");
    } else {
        printf("not sorted\n");
        printf("first out-of-order element at index %d\n", out_of_order);
    }
    
    for (int i=0; i!=cnt; i++) {
        fprintf(outfile, "%d\n", data[i]);
    } 

    fclose(infile);
    fclose(outfile);
    return EXIT_SUCCESS;
    /* uncomment if you want to print */
    /* print(data, count) */
    
}

void print(int a[], int size) {
    for (int i=0; i < size; ++i) {
        printf("%d\n", a[i]);
    }
}

/* 
 *  * check whether array is sorted:
 *   * returns index of first out-of-order element, or -1 if all are in order
 *    */
int find_out_of_order(int a[], int size) {
    for (int i = 0; i < size-1; ++i) {
        if (a[i] > a[i+1]) { 
            return i;
        }
    }
    return -1;
}

/* sort array */
void sort(int a[], int size) {
    for (int i=0; i!=size-1; i++) {
        for(int j=0; j!=size-1; j++) {
            if (a[j] > a[j+1]) {
                int tmp;
                tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                
            }
        }
    }
}

