/*
  ls
  circa v0.0.1.1a
 */

#include <stdio.h>
#include <dirent.h>
#include <syscall.h>

int main(int argc, char* argv[]) {
    /*
     can't ls files yet.
     sry
     */
    int ARG_A = 0;                                                         // if using -a
    int ARG_B = 0;                                                         // if using -b
    int DIR_SPEC = 0;                                                      // if dir specified

    for (int i = 1; i < argc; i++) {
        /*
          for each argument, run this
         */
        if (STRING_EQUAL_TO_STRING(argv[i], "-a", 2)) {
            /*
              run if -a enabled
             */
            ARG_A = 1;                                                     // if -a enabled, set that
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "-A", 2)) {
            /*
              run if -a enabled
             */
            ARG_A = 2;                                                     // if -A enabled, set to 2
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "-b", 2) || STRING_EQUAL_TO_STRING(argv[i], "--escape", 8)) {
            /*
              if -b or --escape, print non graphic as octal escape
              stub
             */
            ARG_B = 1;
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "--block-size=", 13)) {
            /*
              --block-size custom
              stub
             */
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "-c", 2)) {
            /*
              sort by modification time
              stub
             */
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "-C", 2)) {
            /*
              list entries with columns
              stub
             */
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "--color", 7)) {
            /*
              use color for listing files
              stub
             */
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "-h", 2)) {
            /*
              -h, for human readable sizes
              WORKING ON IT!!!
              stub
             */
        }

        else if (STRING_EQUAL_TO_STRING(argv[i], "-l", 2)) {
            /*
              -l
              long list
              WORKING ON IT!!!
              stub
             */
        }

        else {
            DIR_SPEC = 1;                                                  // if not an argument, set dir to yes
        };
    }

    DIR *DP;                                                               // dir object, for listing files inside of specific directory.
    struct dirent *EP;                                                     // dirent struct for actually getting the name of the files in the directory while listing them. my god i'm long winded

    if (!DIR_SPEC) {                                                       // if no arguments, just the command
        DP = opendir(".");                                                 // open current working directory (cwd / pwd)
    }

    else {                                                                 // if directory specified
        DP = opendir(argv[argc - 1]);                                      // open the first argument, i'm lazy so i'm not programming multiple lists at once atm, sry.
    }

    if (DP != NULL) {                                                      // if not empty and directory exists
        while ((EP = readdir(DP)) != NULL) {                               // set EP to next file to read, and check if done
            if (EP->d_name[0] == '.') {
                if (ARG_A == 1) {                                          // if -a, do nothing
                    if (STRING_EQUAL_TO_STRING(EP->d_name, ".", 1) && EP->d_name[1] == '\0') {
                        continue;                                          // if ., and using -a skip
                    }
                    else if (STRING_EQUAL_TO_STRING(EP->d_name, "..", 2) && EP->d_name[2] == '\0') {
                        continue;                                          // if .., and using -a skip
                    }
                }
                else if (ARG_A == 2) {}                                    // if -A, nothing will change it
                else {
                    continue;                                              // if not, continue
                }
            }
            if (ARG_B) {
                for (int i = 0; i < strlen(EP->d_name); i++) {
                    if ((EP->d_name[i] >= 32) && (EP->d_name[i] <= 254)) {
                        /*
                          if graphic character
                         */
                        printf("%c", EP->d_name[i]);                       // print graphic character
                    }
                    else {
                        /*
                          if not
                         */
                        printf("\\%o", EP->d_name[i]);                    // print character in octal
                    }
                }
                printf("\n");
            }
            else {
                printf("%s\n", EP->d_name);
            };
        }
        closedir(DP);                                                      // close directory, as we are done.
    };
    /*
     i removed an else statement, as it would also trigger if the directory was empty, if i can fix that with statvfs, i will. otherwise, :P.
     */
    return 0;                                                              // success
}
