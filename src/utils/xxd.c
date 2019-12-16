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

    int size;                                                              // size of file
    fseek(fptr, 0, SEEK_END);                                              // go to end of file
    size = ftell(fptr);                                                    // check where we are and save
    fseek(fptr, 0, 0);                                                     // go back to start

    chr = fgetc(fptr);                                                     // get next character
    int cnt = 0;                                                           // counter for file read
    while (cnt < size) {                                                   // read until file over
        printf("%0x", chr);                                                // print character in hex, padded
        chr = fgetc(fptr);                                                 // get next character
        cnt++;                                                             // up counter
    }

    fclose(fptr);                                                          // close file
    return 0;                                                              // success
}
