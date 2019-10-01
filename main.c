#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "random.h"


int x = 1;

uint32_t y = 1;

/*
    (WIP) The goal of the "File Generation" program is to
    generate CSV or Excel files and populate them with fake
    testing data, like names, phone numbers, date of births,
    email addresses, etc.
*/

/*
    The struct "FileInfo" is used to store testing data that
    will be written to a given file. Using a struct is an
    easy way to group similar data. 
*/
typedef struct FileInfo {
    char **emailArr;
    char **nameArr;
    char **phoneArr;
    
} FileInfo;

/*
    The "createFileInfo()" function allocates memory for
    the struct and its arrays, and inputs data into the arrays.

    @param count - The amount of fake data to create.

    @param emailPrefix - The part of the email that comes
    before the "@" sign.

    @param emailDomain - The part of the email that includes
    the "@" sign and everything that follows, e.g.
    "@gmail.com".

    @param firstName - The first name used for the test data.

    @param lastName - The last name used for the test data.
*/
FileInfo *createFileInfo(uint32_t count, char *emailPrefix, char *emailDomain, char *firstName, char *lastName) 
{
    // Allocate memory for struct and arrays.
    FileInfo *fi = malloc(sizeof(FileInfo));

    size_t emailLen = strlen(emailPrefix) + strlen(emailDomain);
    char *emailBuffer = malloc(emailLen + count);

    size_t nameLen = strlen(firstName) + strlen(lastName);
    char *nameBuffer = malloc(nameLen*count*sizeof(nameBuffer));

    char *phone = "555-0";
    size_t phoneLen = (sizeof(uint32_t) * 2) + strlen(phone);
    char *phoneBuffer = malloc(phoneLen*count*sizeof(nameBuffer));

    fi->emailArr = malloc(count*nameLen*sizeof(char*));
    fi->nameArr = malloc(count*nameLen*sizeof(char *));
    fi->phoneArr = malloc(count*phoneLen*sizeof(char *));
    for (uint32_t i=0; i<count; ++i) {
        fi->emailArr[i] = malloc(count*nameLen*sizeof(emailBuffer));
        fi->nameArr[i] = malloc(count*nameLen*sizeof(nameBuffer));
        fi->phoneArr[i] = malloc(count*phoneLen*sizeof(phoneBuffer));
    }

    // If memory allocation was successful, append to arrays.
    if (fi->nameArr != NULL && fi->emailArr != NULL && fi->phoneArr != NULL) {
        for (uint32_t i=0; i<count; ++i) {
            uint32_t phoneAreaCode = randominteger(i, 201, 901, 1);
            uint32_t phoneSuffix = randominteger(i+1, 100, 199, 1);

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

void writeToFile(uint32_t count, char *filename, char **nameArr, char **emailArr, char **phoneArr)
{ 
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
    }

    const char *nameCol = "Full Name";
    const char *emailCol = "Email"; 
    const char *phoneCol = "Phone";

    fprintf(f, "%s,%s,%s\n", nameCol, emailCol, phoneCol);

    for (uint32_t i=0; i<count; ++i) {
        fprintf(f, "%s,%s,%s\n", nameArr[i], emailArr[i], phoneArr[i]);
    }

    fclose(f);
}

int main() 
{
    uint32_t count = 101;
    char *emailPrefix = "test";
    char *emailDomain = "@test.com";
    char *firstName = "Tester";
    char *lastName = "Testerson";

    FileInfo *fi = createFileInfo(count, emailPrefix, emailDomain, firstName, lastName);

    /*for (uint32_t i=0; i<count; ++i) {
        fprintf(stdout, "Name: %s, Email: %s, Phone: %s\n", fi->nameArr[i], fi->emailArr[i], fi->phoneArr[i]);
    }*/

    writeToFile(count, "test.csv", fi->nameArr, fi->emailArr, fi->phoneArr);

    for (uint32_t i=0; i<count; ++i) {
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