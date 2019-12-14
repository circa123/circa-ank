/*
 circa utilites
 ls
 */

#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    /*
     can't ls files yet.
     sry
     */
    DIR *DP;                                                               // dir object, for listing files inside of specific directory.
    struct dirent *EP;                                                     // dirent struct for actually getting the name of the files in the directory while listing them. my god i'm long winded
    if (argc == 1) {                                                       // if no arguments, just the command
        DP = opendir(".");                                                 // open current working directory (cwd / pwd)
    }
    else {                                                                 // if directory specified
        DP = opendir(argv[1]);                                             // open the first argument, i'm lazy so i'm not programming multiple lists at once atm, sry.
    }
    if (DP != NULL) {                                                      // if not empty and directory exists
        while ((EP = readdir(DP)) != NULL) {                               // set EP to next file to read, and check if done
            printf("%s\n", EP->d_name);                                    // print directory / file name to stdout
        }
        closedir(DP);                                                      // close directory, as we are done.
    }
    /*
     i removed an else statement, as it would also trigger if the directory was empty, if i can fix that with statvfs, i will. otherwise, :P.
     */
    return 0;                                                              // success
}
