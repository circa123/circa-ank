/*
  ank v0.0.2
  main.c
  compiles to cfs/binaries/circa
 */
#include <main.h>                                            // definitions for main
#include <shell.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <syscall.h>
#include <defaults.h>                                        // our defaults

int shell_code(int uid) {
    while (RUNNING) {
        if (getcwd(CWD, sizeof(CWD)) != 0) {
            // success with getting cwd
        }

        else {
            printf("error. could not get cwd\n");            // error getting cwd
        };

        for (int i = 0; i < 1024; i++) {
            INPUT[i] = 0;                                    // clear input array
        }

        printf("circa %s # ", CWD);                          // print the input array
        fgets(INPUT, 1024, stdin);                           // gets the input

        ERROR = shell(INPUT);                                // runs shell command
        if (ERROR) {                                         // if error returned
            printf("error: could not execute\n");            // print error message
        }
    };
    return 0;
}

void dummy( int dummy ){ return; };                          // dummy function, just returns

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("error. need cfs and cfs_bin paths\n");
    }

    int VERBOSE = 0;                                         // if verbose, for argv

    if (argc >= 4) {
        /*
          search through the argv for k_params
          also yes, stolen from shell.c
        */
        token = strtok(argv[3], " ");                        // string split token

        int cnt = 0;                                         // counter for loop
        int len;                                             // strncpy len

        while (token != NULL) {
            if (STRING_EQUAL_TO_STRING(token, "-n", 2)) {
                break;                                       // -n skips rest of arguments
            }

            if (STRING_EQUAL_TO_STRING(token, "-v", 2)) {
                VERBOSE = 1;                                 // -v goes full verbose
            }

            token = strtok(NULL, " ");                       // get new token
            cnt++;                                           // up counter
        }
    }

    if (VERBOSE) {
        printf("{ANK} copying cfs_bin\n");
    }
    strncpy(cfs_bin, argv[1], 256);                          // where the binaries are, replace this to fit your needs

    if (VERBOSE) {
        printf("{ANK} copying cfs\n");
    }
    strncpy(cfs, argv[2], 256);                              // where the cfs is,       replace this to fit your needs

    if (VERBOSE) {
        printf("{ANK} setting up signals\n");
    }
    signal(SIGINT, dummy);                                   // skip stop, ctrl+c
    signal(SIGTSTP, dummy);                                  // skip stop, ctrl+z

    if (VERBOSE) {
        printf("{ANK} setting defaults\n");
    }
    SUOM    = 's';                                           // single user
    ADMIN_ID = 0;                                            // admin_id is 0, circa
    RUNNING  = 1;                                            // while running == 1, it's running
    VERSION  = "0.0.2dev";                                   // version of circa

    printf("starting ");                                     // start of print
    ANK_UNAME();                                             // print uname

    if (VERBOSE) {
        printf("{ANK} spawning ptr\n");
    }
    SPAWN_PTR_WITH_UID_IF_PRIVILEGED(&shell_code, ADMIN_ID); // spawn shell_code, the code for FEC in circa
    return 0;
};
