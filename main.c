#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "random.h"

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
*/
FileInfo *createFileInfo(uint32_t count) 
{
    printf("Creating base variables...\n");

    char *names[] = { "Aaron", "Adaline", "Adam", "Adelle", "Adena", "Alethea", "Alethia", "Alex", "Alexander", "Alfredia", "Ali", "Alleen", "Allegra", "Allen", "Allena", "Alline", "Allyn", "Almeta", "Alona", "Altha", "Alvera", "Alverta", "Alysa", "Angila", "Angla", "Angle", "Anika", "Anisa", "Anisha", "Annett", "Annice", "Annika", "Annis", "Annita", "Anthony", "Antonetta", "Antonietta", "Antonina", "Antonio", "Anya", "Apolonia", "Apryl", "Ara", "Aracelis", "Arcelia", "Ardath", "Ardelia", "Ardell", "Armanda", "Armandina", "Arminda", "Arnetta", "Arnette", "Arnita", "Arthur", "Arvilla", "Ashanti", "Ashlea", "Ashli", "Ashlyn", "Aundrea", "Aurore", "Austin", "Avelina", "Avery", "Avril", "Ayako", "Ayana", "Ayanna", "Ayesha", "Azalee", "Azucena", "Azzie", "Babara", "Babette", "Bao", "Barabara", "Barbar", "Barbera", "Barbie", "Bari", "Barrie", "Basilia", "Beata", "Beatris", "Beaulah", "Bebe", "Becki", "Beckie", "Bernardine", "Berneice", "Bernetta", "Bernie", "Birgit", "Blake", "Blondell", "Blossom", "Brett", "Brian", "Brigid", "Brigida", "Brinda", "Britany", "Britni", "Britt", "Britta", "Cammie", "Cammy", "Cyndy", "Cyrstal", "Cythia", "Dacia", "Dagmar", "Domonique", "Donald", "Donella", "Donetta", "Donette", "Nisha", "Nobuko", "Noella", "Nohemi", "Numbers", "Nyla", "Obdulia", "Oda", "Odelia", "Odilia", "Olene", "Olevia", "Olimpia", "Olinda", "Tomiko", "Tommye", "Tomoko", "Zetta", "Zita", "Zofia", "Zonia", "Zulema", "Zulma" "Aaron", "Abe", "Abel", "Abraham", "Abram", "Adalberto", "Adam", "Adan", "Adolfo", "Adolph", "Adrian", "Agustin", "Al", "Alan", "Albert", "Alberto", "Alejandro", "Alex", "Alexander", "Alexis", "Alfonso", "Alfonzo", "Alfred", "Alfredo", "Amado", "Ambrose", "Amos", "Anderson", "Andre", "Anthony", "Antione", "Bernardo", "Bernie", "Berry", "Bert", "Bertram", "Bill", "Billie", "Billy", "Blaine", "Blair", "Blake", "Bo", "Bob", "Bobbie", "Bobby", "Booker", "Boris", "Boyce", "Boyd", "Brad", "Bradford", "Bradley", "Bradly", "Brady", "Brain", "Branden", "Brandon", "Brant", "Brendan", "Bryce", "Bryon", "Buck", "Bud", "Buddy", "Buford", "Burl", "Burt", "Burton", "Buster", "Byron", "Caleb", "Calvin", "Cameron", "Carey", "Carl", "Carlo", "Carlos", "Carlton", "Carmelo", "Carmen", "Chad", "Chadwick", "Chance", "Chang", "Charles", "Charley", "Charlie", "Chas", "Colin", "Cornell", "Cortez", "Cory", "Courtney", "Coy", "Craig", "Cristobal", "Cristopher", "Cruz", "Curt", "Curtis", "Cyril", "Cyrus", "Dale", "Dallas", "Dalton", "Damian", "Damien", "Danny", "Darnell", "Daron", "Darrel", "Darrell", "Darren", "Darrick", "Darrin", "Darron", "Darryl", "Delmar", "Delmer", "Demarcus", "Demetrius", "Denis", "Dennis", "Denny", "Denver", "Devon", "Dewayne", "Dewey", "Dewitt", "Dexter", "Dick", "Diego", "Dillon", "Dino", "Dion", "Dirk", "Domenic", "Domingo", "Dominic", "Dominick", "Dominique", "Don", "Donald", "Dong", "Donn", "Donnell", "Donnie", "Donny", "Donovan", "Donte", "Dudley", "Duncan", "Dustin", "Dusty", "Dwain", "Dwayne", "Dwight", "Dylan", "Earl", "Earle", "Earnest", "Ed", "Eddie", "Eddy", "Edmund", "Grady", "Graham", "Graig", "Grant", "Granville", "Greg", "Gregg", "Gregory", "Grover", "Guadalupe", "Jerome", "Jeromy", "Jerrell", "Jerrod", "Jerrold", "Jerry", "Jess", "Jesse", "Jessie", "Joaquin", "Jody", "Joe", "Joel", "Joesph", "Joey", "John", "Johnathan", "Johnathon", "Johnie", "Johnnie", "Johnson", "Jon", "Jonah", "Jonas", "Jonathan", "Jonathon", "Jordan", "Jordon", "Jorge", "Jose", "Josef", "Joseph", "Josh", "Joshua", "Josiah", "Julian", "Julio", "Julius", "Junior", "Justin", "Kareem", "Karl", "Kasey", "Keenan", "Keith", "Mario", "Marion", "Mark", "Markus", "Marlin", "Marlon", "Marquis", "Marshall", "Martin", "Marty", "Marvin", "Mary", "Mason", "Mathew", "Merlin", "Merrill", "Mervin", "Micah", "Michael", "Michal", "Michale", "Micheal", "Warner", "Warren", "Waylon", "Wayne", "Weldon", "Wendell", "Werner", "Wes", "Wesley", "Weston", "Whitney", "Wilber", "Wilbert", "Wilbur", "Wilburn", "Wiley", "Wilford", "Wilfred", "Yong", "Young", "Zachariah", "Zachary", "Zachery", "Zack", "Zackary", "Zane"
    };

    printf("Allocating memory for variables...\n");
    // Acceptable email address domains
    char *emailDomain[] = {
        "@gmail.com", "@yahoo.com", "@hotmail.com", "@mail.net"
        };

    FileInfo *fi = malloc(sizeof(FileInfo));
    if (fi == NULL) {
        printf("Null pointer for FileInfo struct\n");
        return 0;
    }

    // Allocate memory for buffer strings
    size_t emailLen = strlen(names[0])*sizeof(char *);
    char *emailBuffer = malloc(emailLen*sizeof(char *));

    size_t nameLen = strlen(names[0])*sizeof(char *);
    char *nameBuffer = malloc(nameLen*sizeof(char *));

    char *phone = "555-0";
    size_t phoneLen = strlen(phone)*sizeof(uint32_t);
    char *phoneBuffer = malloc(phoneLen*sizeof(char *));
    if (emailDomain == NULL || nameBuffer == NULL || phoneBuffer == NULL) {
        printf("Null pointer(s) for buffer string(s)\n");
        return 0;
    }

    // Allocate memory for arrays in the struct, as well as their indexes
    fi->emailArr = malloc(count*emailLen*sizeof(fi->emailArr));
    printf("Allocated memory for heap: %d\n", count*emailLen*sizeof(fi->emailArr));
    fi->nameArr = malloc(count*nameLen*sizeof(fi->nameArr));
    fi->phoneArr = malloc(count*phoneLen*sizeof(fi->phoneArr));
    if (fi->emailArr == NULL || fi->nameArr == NULL || fi->phoneArr == NULL) {
        printf("Null pointer(s) for struct array(s)\n");
        return 0; 
    }
    
    for (uint32_t i=0; i<count; ++i) {
        fi->emailArr[i] = malloc(count*nameLen*sizeof(emailBuffer));
        fi->nameArr[i] = malloc(count*nameLen*sizeof(nameBuffer));
        fi->phoneArr[i] = malloc(count*phoneLen*sizeof(phoneBuffer));
        if (fi->emailArr[i] == NULL || fi->nameArr[i] == NULL || fi->phoneArr[i] == NULL) {
            printf("Null pointer(s) for struct array index\n");
            return 0; 
        }
    }   
    
    char *firstname = malloc(count*sizeof(char *));
    char *lastname = malloc(count*sizeof(char *));

    printf("Creating and modifying data for arrays...\n");
    // Create and modify data to append to struct arrays
    for (uint32_t i=0; i<count; ++i) {
        char *randEmailDomain = emailDomain[randominteger(i*time(0), 0, 3, 1)];

        uint32_t phoneAreaCode = randominteger(i, 201, 901, 1);
        uint32_t phoneSuffix = randominteger(i+1, 100, 199, 1);

        snprintf(phoneBuffer, phoneLen + count, "(%d) %s%d", phoneAreaCode, phone, phoneSuffix);
        strcpy(fi->phoneArr[i], phoneBuffer);

        sprintf(firstname, "%s", names[randominteger(i*i*count, 0, sizeof(names)/sizeof(names[0]), 1)]);
        sprintf(lastname, "%s", names[randominteger(time(0)*i+count, 0, sizeof(names)/sizeof(names[0]), 1)]);

        snprintf(nameBuffer, nameLen * count, "%s %s", firstname, lastname);
        strcpy(fi->nameArr[i], nameBuffer);

        snprintf(emailBuffer, emailLen * count, "%s.%s%d%s", firstname,lastname, i, randEmailDomain);
        strcpy(fi->emailArr[i], emailBuffer);
    }
    
    printf("Freeing memory and exiting function...\n");
    free(emailBuffer);
    free(nameBuffer);
    free(phoneBuffer);
    free(firstname);
    free(lastname);

    return fi;
}

/*
    The "writeToFile()" function inserts data from arrays into a csv file.

    @param count - The amount of fake data to append to file.

    @param filename - The name of the file to write to.

    @param nameArr - A 2D array containing names.

    @param emailArr - A 2D array containing email addresses.

    @param phoneArr - A 2D array containing phone numbers.
*/
void writeToFile(uint32_t count, char *filename, char **nameArr, char **emailArr, char **phoneArr)
{ 
    printf("Creating file...\n");
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
    }

    const char *nameCol = "Full Name";
    const char *emailCol = "Email"; 
    const char *phoneCol = "Phone";

    fprintf(f, "%s,%s,%s\n", nameCol, emailCol, phoneCol);

    printf("Appending to file...\n");
    for (uint32_t i=0; i<count; ++i) {
        fprintf(f, "%s,%s,%s\n", nameArr[i], emailArr[i], phoneArr[i]);
    }

    fclose(f);
}

int main(int argc, char **argv) 
{
    uint32_t count = atoi(argv[1]);

    printf("Calling create file info function...\n");

    FileInfo *fi = createFileInfo(count);

    printf("Calling write to file function...\n");
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