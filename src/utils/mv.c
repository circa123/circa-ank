/*
 circa utilites
 mv
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    /*
     stealing more code from cat
     */
    if (argc < 3) {
        printf("mv: usage: mv [FILE] [NEW_NAME]\ne.g. mv file new_file");
    }
    FILE *fptr;                                                            // file pointer
    FILE *sndptr;                                                          // second file pointer, for writing
    int ctr;                                                               // counter for reading
    char chr;                                                              // char for reading
    char FILE_READ[1024];                                                  // read buffer
    
    /*
     debugging
    for (int i = 0; i < strlen(args[2]); i++) {
        printf("%x", args[2][i]);
    };
    printf("\n");
     */

    fptr   = fopen(argv[1], "r");                                          // open file, for reading
    sndptr = fopen(argv[2], "w");                                          // open file, for writing
    if (fptr == NULL) {
        printf("error opening file 1 :(\n");                               // lol rip
        return 1;                                                          // fail
    }
    if (sndptr == NULL) {
        printf("error opening file 2 :(\n");                               // lol rip
        return 1;                                                          // fail
    }
    chr = fgetc(fptr);                                                     // get next character
    while (chr != EOF) {
        fputc(chr, sndptr);                                                // write file
        chr = fgetc(fptr);                                                 // get next char
        ctr++;                                                             // up counter
    }
    fclose(fptr);                                                          // close file
    fclose(sndptr);                                                        // close writing file
    remove(argv[1]);                                                       // bye
    return 0;                                                              // success
}
