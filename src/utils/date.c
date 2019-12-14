/*
 circa v0.0.1a
 date
 */

#include <langinfo.h>    // language info
#include <locale.h>      // localization
#include <stdio.h>
#include <time.h>        // for date

int main() {
    /*
     basic ass date command
     */
    time_t TIME = time(NULL);                                              // time_t, gives us the time
    struct tm tm = *localtime(&TIME);                                      // get time struct for date command
    char TIME_STRING[256];                                                 // string holding time
    setlocale(LC_ALL, "");                                                 // set the locale
    strftime(TIME_STRING, sizeof(TIME_STRING), nl_langinfo(D_T_FMT), &tm); // format date
    printf("%s\n", TIME_STRING);                                           // print date string
    return 0;
}
