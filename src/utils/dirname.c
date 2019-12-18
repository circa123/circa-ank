/*
  dirname
  circa v0.0.2
*/

#include <stdio.h>
#include <libgen.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("dirname: usage: dirname [PATH]\n");                        // no args specified.
        return 1;
    }

    printf("%s\n", dirname(argv[1]));                                      // run dirname syscall on argv[1]
    return 0;
}
