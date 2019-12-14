/*
 circa utils
 head
 */

#include <stdio.h>
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
    while ((chr != EOF) && (another_counter < head_int)) {                 // read until file over or read all of the head bytes, whichever comes first
        printf("%c", chr);                                                 // print character
        chr = fgetc(fptr);                                                 // get next character
        another_counter++;                                                 // up counter
    }
    
    fclose(fptr);                                                          // close file
    return 0;                                                              // success
}
