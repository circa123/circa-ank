/*
  xxd
  circa v0.0.1.1a
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    /*
     primitive xxd
     hex dump
     stealing code from cat AGAIN
     */
    if (argc == 1) {
        printf("xxd: usage: xxd [FILE]\n");
        return 0;
    }
    FILE *fptr;                                                            // file pointer
    char chr;                                                              // char for printing

    fptr = fopen(argv[1], "r");                                            // open file, for reading
    if (fptr == NULL) {
        printf("error opening file :(\n");                                 // lol rip
        return 1;                                                          // fail
    }

    chr = fgetc(fptr);                                                     // get next character
    while (1) {                                                            // read until file over
        printf("%0x", chr);                                                // print character in hex, padded
        chr = fgetc(fptr);                                                 // get next character
    }

    fclose(fptr);                                                          // close file
    return 0;                                                              // success
}
