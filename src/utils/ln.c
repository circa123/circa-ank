/*
 circa utils
 ln
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("ln: usage: ln [file] [file2]\n");
        return argc;
    }
    printf("\n");                                                              // print a newline.
    return symlink(argv[1], argv[2]);                                          // create symlink called args[2] pointing to args[1]
}
