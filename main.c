#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct FileInfo {
    char **emailArr;
    char **nameArr;
    
} FileInfo;

FileInfo *createFileInfo(
    int count, char *emailPrefix, char *emailDomain, char *firstName, char *lastName
    ) {
    FileInfo *fi = malloc(sizeof(FileInfo));

    size_t emailLen = strlen(emailPrefix) + strlen(emailDomain);
    char *emailBuffer = malloc(emailLen + count);

    size_t nameLen = strlen(firstName) + strlen(lastName);
    char *nameBuffer = malloc(nameLen*count*sizeof*nameBuffer);

    char *phoneBuffer = malloc(emailLen + count);

    fi->emailArr = malloc(count*nameLen*sizeof(char*));
    for (int i=0; i<count; ++i) {
        fi->emailArr[i] = malloc(count*nameLen*sizeof(emailBuffer));
    }

    fi->nameArr = malloc(count*nameLen*sizeof(char *));
    for (int i=0; i<count; ++i) {
        fi->nameArr[i] = malloc(count*nameLen*sizeof(nameBuffer));
    }

    if (fi->nameArr != NULL && fi->emailArr != NULL) {
        for (int i=0; i<count; ++i) {
            snprintf(nameBuffer, nameLen + count, "%s%d %s", firstName, i, lastName);
            strcpy(fi->nameArr[i], nameBuffer);

            snprintf(emailBuffer, emailLen + count, "%s%d%s", emailPrefix, i, emailDomain);
            strcpy(fi->emailArr[i], emailBuffer);
        }
    }
    
    free(emailBuffer);
    free(nameBuffer);
    //free(phoneBuffer);

    return fi;
}

int main() {
    int count = 20;
    char *emailPrefix = "test";
    char *emailDomain = "@test.com";
    char *firstName = "Tester";
    char *lastName = "Testerson";

    FileInfo *fi = createFileInfo(count, emailPrefix, emailDomain, firstName, lastName);

    for (int i=0; i<count; ++i) {
        fprintf(stdout, "Name: %s, Email: %s\n", fi->nameArr[i], fi->emailArr[i]);
    }

    for (int i=0; i<count; ++i) {
        free(fi->emailArr[i]);
        free(fi->nameArr[i]);
    }

    free(fi->emailArr);
    free(fi->nameArr);
    free(fi);

    return 0;
}