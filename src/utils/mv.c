/*
  mv
  circa v0.0.1.1a
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
    remove(argv[1]);                                                       // bye
    return 0;                                                              // success
}
