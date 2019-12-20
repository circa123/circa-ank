/*
  chmod
  circa v0.0.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    /*
     chmod, circa edition
     */
    if (argc < 3) {
        printf("chmod: file mode\ne.g. chmod 777 example\n"); // if not enough arguments
        return argc;                                          // return argument count
    }

    if (atoi(argv[1]) > 4095) {
        /*
          if permission higher than possible, exit.
        */
        printf("error. need proper permission. \n");
        return -1;
    }

    else {
        return chmod(argv[2], strtol(argv[1], NULL, 8));      // otherwise, chmod first argument [argv[1]], with permissions [argv[2]]
    };
}
