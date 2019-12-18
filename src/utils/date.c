/*
  date.c
  circa v0.0.2
 */

#include <langinfo.h>    // language info
#include <locale.h>      // localization
#include <stdio.h>
#include <time.h>        // for date

int main() {
    /*
     basic *ss date command
     */
    time_t     TIME = time(NULL);                                                       // time_t, gives us the time
    struct tm  tm = *localtime(&TIME);                                                  // get time struct for date command
    char*      TIME_STRING;                                                            // string holding time
    setlocale(LC_ALL, "");                                                             // set the locale
    strftime(TIME_STRING, 256, "%a %d %b %Y %r %Z", &tm);                              // format date
    printf("%s\n", TIME_STRING);                                                       // print date string
    return 0;
}
