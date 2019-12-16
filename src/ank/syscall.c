/*
  ank v0.0.1.1a
  syscall.c
  link in programs to get ANK syscalls
 */

#include <ftw.h>         // for rm
#include <time.h>        // for date
#include <stdio.h>       // stdio, for print and stuff
#include <dirent.h>      // for listing dirs
#include <locale.h>      // localization
#include <stdlib.h>      // some other stuff
#include <string.h>      // for string maniplutation
#include <unistd.h>      // for symlinks and s***
#include <langinfo.h>    // language info
#include <sys/statvfs.h> // filesystems

// begin our own definitions
#include <main.h>
#include <shell.h>
#include <syscall.h>
#include <defaults.h>

int   UNLINK_FILES(const char *F_PATH, const struct stat *STAT_STRUCT, int TYPE, struct FTW *FTW_STRUCT) {
    /*
     unlinks files
     */

    return remove(F_PATH);
}

int REMOVE_DIR(char *PATH) {
    /*
     uses nftw to remove directories
     */
    return nftw(PATH, UNLINK_FILES, 64, 8 | 1);
}

int STRING_EQUAL_TO_STRING(char input[], char cmp[], int len) {
    /*
        gets input
        thing to compare to
        and the length
    */
    for (int i = 0; i < len; i++) {                                            // for i up to length
        if (cmp[i] == input[i]) {                                              // if characters are the same
            continue;                                                          // next item
        }
        else {                                                                 // if not
            return 0;                                                          // fail
        };
    };
    return 1;                                                                  // success
};

char* INT_TO_FORMATTED_STRING(long long integer) {
    static char returnChar[64];                                                // returned char array
    int itc;                                                                   // int to convert to char array
    char chrToAdd[3];                                                          // char to add to string
    if (integer < 1024) {
        itc = integer;                                                         // set int to number, as it's under 1K, so bytes
        strcpy(chrToAdd, "B");                                                 // copy size specifier
    }
    else if (integer < 1048576) {
        itc = integer / 1024;                                                  // set int to number / 1024, as it's under 1MB, so kilobytes
        strcpy(chrToAdd, "KB");                                                // copy size specifier
    }
    else if (integer < 1073741824) {
        itc = integer / 1048576;                                               // set int to number / 1048576, as it's under 1GB, so megabytes
        strcpy(chrToAdd, "MB");                                                // copy size specifier
    }
    else if (integer < 1099511627776) {
        itc = integer / 1073741824;                                            // set int to number / 2**30, as it's under 1TB, so gigabytes
        strcpy(chrToAdd, "GB");                                                // copy size specifier
    }
    else {
        itc = integer / 1099511627776;                                         // set int to number / 2**40, as it's under 1EB, so terabytes
        strcpy(chrToAdd, "TB");                                                // copy size specifier
    }
    sprintf(returnChar, "%i", itc);                                            // put integer in char array
    int offset = strlen(returnChar);                                           // offset for the string to be added
    for (int i = strlen(returnChar); i < strlen(returnChar)+2; i++) {          // for the characters
        returnChar[i] = chrToAdd[i - offset];                                  // set last characters
    };
    return returnChar;                                                         // return char*
}

int SPAWN_PTR_WITH_UID_IF_PRIVILEGED(int (*ptr)(int uid), int uid) {
    /*
     spwuif
     if uid passed == ADMIN_ID, spawn it
     */
    if (uid == ADMIN_ID) {

        (*ptr)(uid);                                                           // if admin uid, set in kernel, run ptr with uid
    }
    else {
        return 1;                                                             // fail :(
    }
    return 0;                                                                  // success!
}

char* UNAME() {
    char* ret_val;                                                             // returned char*
    sprintf(ret_val, "ANK v%s", VERSION);                                      // format version
    return ret_val;                                                            // return char*
}
