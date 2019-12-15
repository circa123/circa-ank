/*
  rm
  circa v0.0.1.1a
 */

#include <stdio.h>
#include <syscall.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("rm: usage: rm [FILE/DIR]\n");
    }
    struct stat PATH_STAT;                                                 // path stat struct
    stat(argv[1], &PATH_STAT);                                             // stat the path specified by user in argv[1]
    if (S_ISREG(PATH_STAT.st_mode)) {
        remove(argv[1]);                                                   // just remove if regular file
    }
    else if (S_ISDIR(PATH_STAT.st_mode)) {
        REMOVE_DIR(argv[1]);                                               // use REMOVE_DIR function if directory
    }
    else {
        return 1;                                                          // not a file or directory, so fail.
    }
    return 0;                                                              // success
};
