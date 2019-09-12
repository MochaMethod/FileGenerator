#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

typedef struct FileInfo {
    char **emailArr;
    char **nameArr;
    char **phoneArr;
    
} FileInfo;

FileInfo *createFileInfo(
    int count, char *emailPrefix, char *emailDomain, char *firstName, char *lastName
    ) {
    FileInfo *fi = malloc(sizeof(FileInfo));

    size_t emailLen = strlen(emailPrefix) + strlen(emailDomain);
    char *emailBuffer = malloc(emailLen + count);

    size_t nameLen = strlen(firstName) + strlen(lastName);
    char *nameBuffer = malloc(nameLen*count*sizeof(nameBuffer));

    char *phone = "555-0";
    size_t phoneLen = (sizeof(int) * 2) + strlen(phone);
    char *phoneBuffer = malloc(phoneLen*count*sizeof(nameBuffer));

    fi->emailArr = malloc(count*nameLen*sizeof(char*));
    for (int i=0; i<count; ++i) {
        fi->emailArr[i] = malloc(count*nameLen*sizeof(emailBuffer));
    }

    fi->nameArr = malloc(count*nameLen*sizeof(char *));
    for (int i=0; i<count; ++i) {
        fi->nameArr[i] = malloc(count*nameLen*sizeof(nameBuffer));
    }

    fi->phoneArr = malloc(count*phoneLen*sizeof(char *));
    for (int i=0; i<count; ++i) {
        fi->phoneArr[i] = malloc(count*phoneLen*sizeof(phoneBuffer));
    }

    if (fi->nameArr != NULL && fi->emailArr != NULL && fi->phoneArr != NULL) {
        for (int i=0; i<count; ++i) {
            int phoneAreaCode = randomInteger(i, 201, 901, 1);
            int phoneSuffix = randomInteger(i+1, 100, 199, 1);

            snprintf(phoneBuffer, phoneLen + count, "(%d) %s%d", phoneAreaCode, phone, phoneSuffix);
            strcpy(fi->phoneArr[i], phoneBuffer);

            snprintf(nameBuffer, nameLen + count, "%s%d %s", firstName, i, lastName);
            strcpy(fi->nameArr[i], nameBuffer);

            snprintf(emailBuffer, emailLen + count, "%s%d%s", emailPrefix, i, emailDomain);
            strcpy(fi->emailArr[i], emailBuffer);
        }
    }
    
    free(emailBuffer);
    free(nameBuffer);
    free(phoneBuffer);

    return fi;
}

int main() {
    int count = 101;
    char *emailPrefix = "test";
    char *emailDomain = "@test.com";
    char *firstName = "Tester";
    char *lastName = "Testerson";

    FileInfo *fi = createFileInfo(count, emailPrefix, emailDomain, firstName, lastName);

    for (int i=0; i<count; ++i) {
        fprintf(stdout, "Name: %s, Email: %s, Phone: %s\n", fi->nameArr[i], fi->emailArr[i], fi->phoneArr[i]);
    }

    for (int i=0; i<count; ++i) {
        free(fi->emailArr[i]);
        free(fi->nameArr[i]);
        free(fi->phoneArr[i]);
    }

    free(fi->emailArr);
    free(fi->nameArr);
    free(fi->phoneArr);
    free(fi);

    return 0;
}