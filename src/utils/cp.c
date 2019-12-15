/*
  cp.c
  circa v0.0.1.1a
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    /*
     stolen code
     from cat, but jankier :D
     also apparently ends at nulls
     */

    FILE *fptr;                                                            // file pointer
    FILE *sndptr;                                                          // second file pointer, for writing
    char chr;                                                              // char for reading

    /*
     debugging
    for (int i = 0; i < strlen(args[2]); i++) {
        printf("%x", args[2][i]);
    };
    printf("\n");
     */

    fptr   = fopen(argv[1], "rb");                                         // open file, for reading
    sndptr = fopen(argv[2], "wb");                                         // open file, for writing
    if (fptr == NULL) {
        printf("error opening file 1 :(\n");                               // lol rip
        return 1;                                                          // fail
    }
    if (sndptr == NULL) {
        printf("error opening file 2 :(\n");                               // lol rip
        return 1;                                                          // fail
    }
    int size;                                                              // size of file
    fseek(fptr, NULL, SEEK_END);                                           // go to end of file
    size = ftell(fptr);                                                    // check where we are and save
    fseek(fptr, NULL, 0);                                                  // go back to start

    chr = fgetc(fptr);                                                     // get next character
    int cnt = 0;                                                           // counter for file read
    while (cnt < size) {                                                   // read until file over
        fputc(chr, sndptr);                                                // write file
        chr = fgetc(fptr);                                                 // get next char
        cnt++;                                                             // up counter
    }
    
    fclose(fptr);                                                          // close file
    fclose(sndptr);                                                        // close writing file
    return 0;                                                              // success
}
