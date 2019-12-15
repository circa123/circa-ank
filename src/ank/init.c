/*
  ank v0.0.1.1a
  init.c
  compiles to cfs/init
 */

#include <stdlib.h>
#include <unistd.h>

int main(){
    /*
     stole fork + exec code from shell.c
     */
    printf("{ank} init\nTHIS PROGRAM COMES WITH ABSOLUTELY NO WARRANTY, SEE LICENSE TEXT FOR DETAILS. \n");
    int CHILD = 0;
    int status;                                                            // for waitpid
    int pid = fork();                                                      // fork
    if (pid == CHILD) {
        /*
        if child process
         */
        char *argv_list[] = {"", NULL};                                    // initialize argv list for the execution with "", to pad the code
        execv("binaries/circa", argv_list);                                // actually exec the binary
        exit(0);                                                           // exit
    }
    else if (waitpid(pid, &status, 0) > 0) {                               // wait for binary to exit
        if (WIFEXITED(status)) {                                           // if exited
            printf("halting circa\n");
            return 0;                                                      // return 0
        }
    }
}
