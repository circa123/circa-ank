/*
  head
  circa v0.0.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("head: usage: head -c [bytes] [file]\n");
        return 0;
    }

    int head_int;                                                          // amount to read
    int counter;                                                           // argument counter
    int another_counter = 0;                                               // counter for char's read

    for (int i = 1; i < argc; i++) {                                       // for each argument in the array
        if (STRING_EQUAL_TO_STRING(argv[i], "-c", 2)) {                    // if argument is -c
            if (atoi[argv[i+1]] < 0) {
                /*
                  if to read nothing, just exit
                */
                return -1;
            }
            head_int = atoi(argv[i + 1]);                                  // set amount to read to next argument
            counter = i + 2;                                               // counter now equals the filename's place in the args
            break;                                                         // success
        }
    }

    /*
     stealing more code from cat
     :D
     */

    FILE *fptr;                                                            // file pointer
    char chr;                                                              // char for reading

    fptr = fopen(argv[counter], "r");                                      // open file, for reading
    if (fptr == NULL) {
        printf("error opening file :(\n");                                 // lol rip
        return 1;                                                          // fail
    }

    chr = fgetc(fptr);                                                     // get next character
    int size;                                                              // size of file
    fseek(fptr, 0, SEEK_END);                                              // go to end of file
    size = ftell(fptr);                                                    // check where we are and save
    fseek(fptr, 0, 0);                                                     // go back to start
    int cnt = 0;

    while ((cnt < size) && (another_counter < head_int)) {                 // read until file over or read all of the head bytes, whichever comes first
        printf("%c", chr);                                                 // print character
        chr = fgetc(fptr);                                                 // get next character
        another_counter++;                                                 // up counter
        cnt++;
    }

    fclose(fptr);                                                          // close file
    return 0;                                                              // success
}
