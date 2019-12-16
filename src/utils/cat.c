/*
  cat.c
  circa v0.0.1.1a
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("cat: usage cat [FILE]\ne.g. cat example\nor cat example1 example2... etc\n");
    }

    else if (argc == 2) {
        FILE *fptr;                                                        // file pointer
        char chr;                                                          // char for printing
        fptr = fopen(argv[1], "r");                                        // open file, for reading
        
        if (fptr == NULL) {
            printf("error. could not open file. :(\n");                    // lol rip
            return 1;                                                      // fail
        }

        int size;                                                          // size of file
        fseek(fptr, NULL, SEEK_END);                                       // go to end of file
        size = ftell(fptr);                                                // check where we are and save
        fseek(fptr, NULL, 0);                                              // go back to start

        chr = fgetc(fptr);                                                 // get next character
        int cnt = 0;                                                       // counter for file read
        while (cnt < size) {                                               // read until file over
            printf("%c", chr);
            chr = fgetc(fptr);                                             // get next char
            cnt++;                                                         // up counter
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
