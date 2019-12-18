/*
  ank v0.0.1.1a
  init.c
  compiles to cfs/init
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    /*
     stole fork + exec code from shell.c
     */

    printf("{ank} init\nTHIS PROGRAM COMES WITH ABSOLUTELY NO WARRANTY, SEE LICENSE TEXT FOR DETAILS.\n"); // print startup message

    int CHILD = 0;
    int status;                                                            // for waitpid
    int pid = fork();                                                      // fork

    if (pid == CHILD) {
        /*
        if child process
         */

        char CWD[256];
        if (getcwd(CWD, sizeof(CWD)) != NULL) {
            // success with getting cwd
        }

        else {
            printf("error getting cwd. :(\n");
            exit(0);
        }

        char BIN[256];                                                     // binary path
        char BINS[256] = "binaries/";                                      // just an array with binaries/ in it

        strncpy(BIN, CWD, 256);                                            // put cwd in bin
        BIN[strlen(BIN)] = '/';                                            // for fix
        int len = strlen(BIN);                                             // get len for loop

        for (int i = len; i < len + strlen("binaries/"); i++) {
            BIN[i] = BINS[i - len];                                        // chuck on bins to end of bin
        }

        char* K_ARGS = "-n";                                               // -n stops looking for args, and just continues. see SPEC.TXT in docs for the documentation on the arguments you can use

        char *argv_list[] = {"", BIN, CWD, K_ARGS, NULL};                  // initialize argv list for the execution with "", to pad the code
        execv("binaries/circa", argv_list);                                // actually exec the binary
        exit(0);                                                           // exit
    }

    else if (waitpid(pid, &status, 0) > 0) {
        /*
          wait for binary to exit
        */
        if (WIFEXITED(status)) {                                           // if exited
            printf("halting ank\n");
            return 0;                                                      // return 0
        }
    }
}
