/*
  shell.c
  piping not a thing yet. sry
  circa v0.0.1.1a
 */

#include <ftw.h>         // for rm
#include <stdio.h>       // stdio, for print and stuff
#include <dirent.h>      // for listing dirs
#include <locale.h>      // localization
#include <stdlib.h>      // some other stuff
#include <unistd.h>      // for symlinks and s***
#include <langinfo.h>    // language info
#include <sys/statvfs.h> // filesystems

// begin our own definitions
#include <main.h>
#include <shell.h>
#include <defaults.h>

int shell(char input[1024]) {
    /*
     take shell input,
     break it apart,
     execute it, etc.
     */

    for (int i = 0; i < 64; i++) {                                             // go through each arg
        for (int j = 0; j < 64; j++) {                                         //' go through arg
            args[i][j] = 0;                                                    // clear arg
        };
    }

    token = strtok(input, " ");                                                // string split token

    if (STRING_EQUAL_TO_STRING(input, "\n", 1)) {
        return 0;                                                              // empty input, so return
    }

    int cnt = 0;                                                               // counter for loop
    int len;                                                                   // strncpy len
    char backup[64];

    while (token != NULL) {
        len = strlen(token);                                                   // get strlen

        strncpy(backup, token, 64);
        token = strtok(NULL, " ");                                             // get new token

        if (token == NULL) {
            len--;
        };

        strncpy(args[cnt], backup, len);                                       // copy str to argument by counter, with the token, up to length
        cnt++;                                                                 // up counter
    }

    if (STRING_EQUAL_TO_STRING("cd", args[0], 2)) {
        if (chdir(args[1]) == 0) {                                             // success
            return 0;                                                          // success
        }
        else {
            printf("error changing directory :(\n");                           // fail
            return 1;                                                          // return fail :(
        };
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "echo", 4)) {
        for (int i = 1; i < cnt; i++) {                                        // for each argument in the array
            printf("%s", args[i]);                                             // print the argument
            if (i < (cnt - 1)){
                printf(" ");                                                   // if not the last argument, print a space
            }
        }
        printf("\n");                                                          // print a newline.
        return 0;
    }

    /*
     f*** ed
     nano all the way b****
     */

    else if (STRING_EQUAL_TO_STRING(args[0], "id", 2)) {
        printf("id: 0 group: god\n");                                          // print id
        return 0;
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "logname", 7)) {
        printf("circa\n");                                                     // you are circa
        return 0;
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "pwd", 3)) {
        char CWD[256];                                                         // current working directory array.
        /*
         yes i stole this from the main.c code.
         sue me
         */
        if (getcwd(CWD, sizeof(CWD)) != NULL) {
            // success with getting cwd
            printf("%s\n", CWD);
        }

        else {
            printf("error with getting cwd, sry :P\n");                        // error getting cwd
            return 1;
        };

        return 0;                                                              // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "halt", 4)) {
        exit(-255);
        return -255;                                                           // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "sleep", 5)) {
        int sleep_time;                                                        // integer, the amount of time we will sleep
        sleep_time = atoi(args[1]);                                            // set sleep time to the integer value of the first argument to the command
        sleep(sleep_time);                                                     // sleep for sleep_time seconds
        return 0;                                                              // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "tty", 3)) {
        printf("god\n");
        return 0;                                                              // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "uname", 5)) {
        printf("circa v%s\n", VERSION);                                        // print name and version of circa
        return 0;                                                              // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "users", 5)) {
        printf("circa\n");                                                     // this is a single user system, thus only you are logged in. :P
        return 0;                                                              // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "who", 3)) {
        printf("circa\n");                                                     // this is a single user system, thus only you are logged in. :P
        return 0;                                                              // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "whoami", 6)) {
        /*
         may add ability to change username at some point
         but not yet
         */
        printf("circa\n");
        return 0;                                                              // success
    }

    else if (STRING_EQUAL_TO_STRING(args[0], "suom", 4)) {
        /*
         this is currently a singler user system
         i am planning on maybe creating mu (multi user) circa
         but that will be difficult
         :) bye
         */
        if (SUOM == 's') {
            printf("single user\n");                                           // 99% of time this
        }
        else if (SUOM == 'm') {
            printf("multi user\n");                                            // no multi user implemented, at least in the same launch process
            /*
             note to self
             might implement multi user and s*** with an init binary
             kinda make a micro kernel inside of a real kernel
             */
        }
        else {
            printf("Strangely, the SUOM environment variable is not correctly set, please check your kernel settings and try again. :)\n");
        }
        return 0;
    }

    else {                                                                     // if not implemented directly in the shell, run this code
        int status;                                                            // for waitpid
        int pid = fork();                                                      // fork
        if (pid == 0){                                                         // if child process, run this code
            char *argv_list[] = {""};                                          // initialize argv list for the execution with "", to pad the code
            char a0[128] = "/Users/jp/circa/cfs/binaries/";                    // binary path
            for (int i = 1; i < cnt; i++) {                                    // for each argument passed
                argv_list[i] = args[i];                                        // add argument to end of argv_list
            }
            int len = strlen(a0);
            for (int i = len; i < len + strlen(args[0]); i++) {
                a0[i] = args[0][i - len]; // copy command after binaries
            }
            argv_list[cnt] = NULL;                                             // because exec
            execv(a0, argv_list);                                              // actually exec the binary
            exit(0);                                                           // exit
        }
        if (waitpid(pid, &status, 0) > 0) {                                    // wait for binary to exit
            if (WIFEXITED(status)) {                                           // if exited
                return 0;                                                      // return 0
            }
        }
        return 0;
    }
    return -1;
}
