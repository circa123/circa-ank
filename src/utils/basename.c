/*
  basename v_nil
  circa v0.0.1.1a
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* token;
    if (argc == 1) {
        printf("basename: usage: basename [PATH]\n");                      // no args specified.
        return 1;
    }
    token = strtok(argv[1], "/");                                          // get token for args[1]
    char new_backup[256];                                                  // backup for token
    while (token != NULL) {
        for (int i = 0; i < 256; i++) {
            new_backup[i] = 0;                                             // clear backup token
        }
        strncpy(new_backup, token, 256);                                   // copy token into new_backup
        token = strtok(NULL, "/");                                         // get next token
    }
    printf("%s\n", new_backup);                                            // we done, print that stuff
    return 0;
}
