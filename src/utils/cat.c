/*
  cat.c
  circa v0.0.1.1a
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("cat: usage cat [FILE]\ne.g. cat example\n");
    }

    else if (argc == 2) {
        FILE *fptr;                                                        // file pointer
        char chr;                                                          // char for printing
        fptr = fopen(argv[1], "r");                                        // open file, for reading
        if (fptr == NULL) {
            printf("error. could not open file. :(\n");                    // lol rip
            return 1;                                                      // fail
        }

        chr = fgetc(fptr);                                                 // get next character
        while (chr != EOF) {                                               // read until file over
            printf("%c", chr);                                             // print character
            chr = fgetc(fptr);                                             // get next character
        }

        fclose(fptr);                                                      // close file
    }
    else {
        for (int i = 1; i < argc; i++) {
            FILE *fptr;                                                    // file pointer
            char chr;                                                      // char for printing
            fptr = fopen(argv[i], "r");                                    // open file, for reading
            if (fptr == NULL) {
                printf("error. could not open file. :(\n");                // lol rip
                return 1;                                                  // fail
            }

            chr = fgetc(fptr);                                             // get next character
            while (chr != EOF) {                                           // read until file over
                printf("%c", chr);                                         // print character
                chr = fgetc(fptr);                                         // get next character
            }

            fclose(fptr);                                                  // close file
        }
    }
    return 0;                                                              // success
}
