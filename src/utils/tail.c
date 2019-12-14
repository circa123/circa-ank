/*
  tail
  circa v0.0.1.1a
 */

#include <stdio.h>
#include <syscall.h>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("tail: usage: tail -c [bytes] [file]\n");
        return 0;
    }
    /*
     suprisingly, i did not steal this code from cat
     THIS TIME
     */
    char chr;
    FILE *fptr;
    long length;
    int counter;
    int  tail_int;
    /*
     stolen from head
     */
    for (int i = 1; i < argc; i++) {                                       // for each argument in the array
        if (STRING_EQUAL_TO_STRING(argv[i], "-c", 2)) {                                     // if argument is -c
            tail_int = atoi(argv[i + 1]);                                  // set amount to read to next argument
            counter = i + 2;                                               // counter now equals the filename's place in the args
            break;                                                         // success
        }
    }
    fptr = fopen(argv[counter], "r");
    if (fptr == NULL) {
        printf("error: could not open file. :(\n");                        // lol rip, fail. :(
        return 1;                                                          // fail
    }
    fseek(fptr, 0, SEEK_END);
    length = ftell(fptr);
    fseek(fptr, length - tail_int, SEEK_SET);
    while ((chr != EOF)) {                                                 // read until file is over
        printf("%c", chr);                                                 // print character
        chr = fgetc(fptr);                                                 // get next character
    }
    return 0;                                                              // success
}
