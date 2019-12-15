/*
  ank v0.0.1.1a
  main.c
  compiles to cfs/binaries/circa
 */
#include <main.h>                                            // definitions for main
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <defaults.h>                                        // our defaults

int shell_code(int uid) {
    while (RUNNING) {
        if (getcwd(CWD, sizeof(CWD)) != NULL) {
            // success with getting cwd
        }

        else {
            printf("error with getting cwd, sry :P\n");      // error getting cwd
        };

        for (int i = 0; i < 1024; i++) {
            INPUT[i] = 0;                                    // clear input array
        }

        printf("circa %s # ", CWD);                          // print the input array
        fgets(INPUT, 1024, stdin);                           // gets the input

        ERROR = shell(INPUT);                                // runs shell command
        if (ERROR) {                                         // if error returned
            printf("error with shell command\n", ERROR);     // print error message
        }
    };
}

void dummy( int dummy ){return;};                            // dummy function, just returns

int main() {
    cfs_bin[256]  = "/Users/jp/circa/cfs/binaries/";         // where the binaries are
    cfs[256]      = "/Users/jp/circa/cfs/";                  // where the cfs is
    signal(SIGINT, dummy);                                   // skip stop, ctrl+c
    signal(SIGTSTP, dummy);                                  // skip stop, ctrl+z
    SUOM    = 's';                                           // single user
    ADMIN_ID = 0;                                            // admin_id is 0, circa
    RUNNING  = 1;                                            // while running == 1, it's running
    VERSION  = "0.0.1.1a";                                   // version of circa
	printf("starting circa v%s\n", VERSION);                 // print startup message
    SPAWN_PTR_WITH_UID_IF_PRIVILEGED(&shell_code, ADMIN_ID); // spawn shell_code, the code for FEC in circa
	return 0;
};
