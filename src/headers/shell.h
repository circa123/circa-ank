/*
  shell.h
  circa v0.0.1.1a
 */

int shell(char input[1024]);       // shell command
char args[64][64];                 // arguments
char *token;                       // string split token
char path[64][64];                 // path array of arrays
