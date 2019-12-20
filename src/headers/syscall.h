/*
  syscall.h
  ank v0.0.2
 */

int   REMOVE_DIR(char *PATH);                                                                             // remove dir with path
int   STRING_EQUAL_TO_STRING(char INPUT[], char COMPARE_STRING[], int LEN);                               // compares string to other string
char* INT_TO_FORMATTED_STRING(long long integer);                                                         // takes integer and puts it to formatted amount of bytes (1KB, 2MB, 4GB, 8TB, etc.)
int   SPAWN_PTR_WITH_UID_IF_PRIVILEGED(int (*ptr)(int uid), int uid);                                     // takes pointer and executes it if uid == ADMIN_ID
int   ANK_UNAME();
