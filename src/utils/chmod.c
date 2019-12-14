#include <stdio.h>

int main(int argc, char *argv[]) {
    /*
     chmod, circa edition
     */
    if (argc < 3) {
        printf("chmod: file mode\ne.g. chmod example 777\n"); // if not enough arguments
        return argc;                                          // return argument count
    }
    else {
        return chmod(argv[1], strtol(argv[2], NULL, 8));      // otherwise, chmod first argument [file], with permissions [argv[2]]
    };
}
