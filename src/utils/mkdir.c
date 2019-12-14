/*
  mkdir
  circa v0.0.1.1a
 */

#include <stdio.h>
#include <syscall.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("mkdir: usage: mkdir [DIRECTORY]\n");
    }
    int mode = strtol("700", NULL, 8);                                     // default mode is 700
    for (int i = 1; i < argc; i++) {
        /*
          for each argument, run this
         */
        if (STRING_EQUAL_TO_STRING(argv[i], "-m", 2)) {
            /*
              run if -m enabled
             */
            mode = strtol(argv[i + 1], NULL, 8);                           // get mode with -m
        }
    }
    if (mkdir(argv[argc - 1], mode) == 0) {                                // attempt to make the directory in first argument, and check if functional (0 is good, remember?)
        return 0;                                                          // success
    }
    else {
        return 1;                                                          // fail
    };
}
