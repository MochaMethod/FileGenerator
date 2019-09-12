#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct FileInfo {
    char **emailArr;
    
} FileInfo;

FileInfo *createFileInfo(int count) {
    FileInfo *fi = malloc(sizeof(FileInfo));

    char *emailPrefix = "test";
    char *emailDomain = "@test.com";
    size_t emailLen = strlen(emailPrefix) + strlen(emailDomain);
    char *buffer = malloc(emailLen + count);

    fi->emailArr = malloc(count*sizeof (char*));
    for (int i=0; i<count; ++i) {
        fi->emailArr[i] = malloc(emailLen*sizeof(char));
    }

    for (int i=0; i<count; ++i) {
        snprintf(buffer, emailLen + count, "%s%d%s", emailPrefix, i, emailDomain);
        strcpy(fi->emailArr[i], buffer);
    }

    free(buffer);

    return fi;
}

int main() {
    int count = 25;
    FileInfo *fi = createFileInfo(count);

    for (int i=0; i<count; ++i) {
        fprintf(stdout, "%s\n", fi->emailArr[i]);
    }

    for (int i=0; i<count; ++i) {
        free(fi->emailArr[i]);
    }

    free(fi->emailArr);
    free(fi);

    return 0;
}