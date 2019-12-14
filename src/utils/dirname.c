#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* token;
    if (argc == 1) {
        printf("dirname: usage: dirname [PATH]\n");                        // no args specified.
        return 1;
    }
    token = strtok(argv[1], "/");                                          // get token for argv[1]
    printf("%s\n", token);                                                 // we done, print that stuff
    return 0;
}
