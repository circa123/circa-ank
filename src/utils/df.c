/*
  df
  circa v0.0.1.1a
 */

#include <stdio.h>
#include <syscall.h>
#include <sys/statvfs.h>                                                   // filesystems

int main(int argc, char* argv[]) {
    struct statvfs fs;                                                     // filesystem stat struct, for getting free space
    if (argc < 2) {
        printf("error: usage: df [MOUNTPOINT]\ne.g. df /\n");
        return argc;
    }
    if (statvfs(argv[1], &fs) != 0) {
        printf("error opening path. :(\n");                                // lol rip
        return 1;                                                          // fail
    }

    long long free_space;                                                  // long, for free space
    free_space = (fs.f_bavail*4);                                          // set free space in kilobytes
    printf("%s\n", INT_TO_FORMATTED_STRING(free_space*1024));              // printf free space
    return 0;                                                              // success
}
