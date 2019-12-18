/*
  tail
  circa v0.0.1.1a
 */

#include <stdio.h>
#include <stdlib.h>
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
    int FLIP = 0;

    /*
     stolen from head
     */

    for (int i = 1; i < argc; i++) {                                       // for each argument in the array
        if (STRING_EQUAL_TO_STRING(argv[i], "-c", 2)) {                    // if argument is -c
            if (argv[i + 1] == '+') {
                char* str;                                                 // str to copy to
                for (int i = 1; i < strlen(argv[i + 1]); i++) {
                    /*
                      copy stuff
                    */
                    str[i - 1] = argv[i];
                }
                tail_int = atoi(str);
                FLIP = 1;
            }
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

    fseek(fptr, 0, SEEK_END);                                              // go to end
    length = ftell(fptr);                                                  // get length
    fseek(fptr, length - tail_int, SEEK_SET);                              // go to end of file - the integer for how much we are reading

    int cnt = length - tail_int;
    if (FLIP) {
        /*
          flipped
        */
        cnt = tail_int;
    }
    while (cnt < length) {                                                 // read until file is over
        printf("%c", chr);                                                 // print character
        chr = fgetc(fptr);                                                 // get next character
        cnt++;                                                             // up counter
    }

    return 0;                                                              // success
}
