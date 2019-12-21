/*
  mv
  circa v0.0.2
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
    /*
     stealing more code from cat
     */
    if (argc < 3) {
        printf("mv: usage: mv [FILE] [NEW_NAME]\ne.g. mv file new_file");
    }

    return rename(argv[1], argv[2]);
}
