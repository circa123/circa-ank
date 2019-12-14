/*
  syscall.h
  ank v0.0.1.1a
 */

int  UNLINK_FILES(const char *F_PATH, const struct stat *STAT_STRUCT, int TYPE, struct FTW *FTW_STRUCT); // unlinks files
int  REMOVE_DIR(char *PATH);                                                                             // remove dir with path
int  STRING_EQUAL_TO_STRING(char INPUT[], char COMPARE_STRING[], int LEN);                               // compares string to other string
char* INT_TO_FORMATTED_STRING(long long integer);                                                       // takes integer and puts it to formatted amount of bytes (1KB, 2MB, 4GB, 8TB, etc.)
int  SPAWN_PTR_WITH_UID_IF_PRIVILEGED(int (*ptr)(int uid), uid);                                         // takes pointer and executes it if uid == ADMIN_ID
