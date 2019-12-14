/*
 circa utilites
 mkdir
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("mkdir: usage: mkdir [DIRECTORY]\n");
    }
    if (mkdir(argv[1], 777) == 0) {                                        // attempt to make the directory in first argument, and check if functional (0 is good, remember?)
        return 0;                                                          // success
    }
    else {
        return 1;                                                          // fail
    };
}
