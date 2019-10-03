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
    The `writeToFile()` function creates strings that represent fake 'people' -- that is, fake names, emails, and phone numbers -- and appends the data to a csv format. 

    @param char *filename: A string pointer representing the csv to write to.

    @param uint32_t count: An integer representing the amount of 'people' to create.
*/
int writeToFile(char *filename, uint32_t count)
{ 
    char *names[] = {
        "Aaron", "Adaline", "Adam", "Adelle", "Adena", "Alethea", "Alethia", "Alex", "Alexander", "Alfredia", "Ali", "Alleen", "Allegra", "Allen", "Allena", "Alline", "Allyn", "Almeta", "Alona", "Altha", "Alvera", "Alverta", "Alysa", "Angila", "Angla", "Angle", "Anika", "Anisa", "Anisha", "Annett", "Annice", "Annika", "Annis", "Annita", "Anthony", "Antonetta", "Antonietta", "Antonina", "Antonio", "Anya", "Apolonia", "Apryl", "Ara", "Aracelis", "Arcelia", "Ardath", "Ardelia", "Ardell", "Armanda", "Armandina", "Arminda", "Arnetta", "Arnette", "Arnita", "Arthur", "Arvilla", "Ashanti", "Ashlea", "Ashli", "Ashlyn", "Aundrea", "Aurore", "Austin", "Avelina", "Avery", "Avril", "Ayako", "Ayana", "Ayanna", "Ayesha", "Azalee", "Azucena", "Azzie", "Babara", "Babette", "Bao", "Barabara", "Barbar", "Barbera", "Barbie", "Bari", "Barrie", "Basilia", "Beata", "Beatris", "Beaulah", "Bebe", "Becki", "Beckie", "Bernardine", "Berneice", "Bernetta", "Bernie", "Birgit", "Blake", "Blondell", "Blossom", "Brett", "Brian", "Brigid", "Brigida", "Brinda", "Britany", "Britni", "Britt", "Britta", "Cammie", "Cammy", "Cyndy", "Cyrstal", "Cythia", "Dacia", "Dagmar", "Domonique", "Donald", "Donella", "Donetta", "Donette", "Nisha", "Nobuko", "Noella", "Nohemi", "Numbers", "Nyla", "Obdulia", "Oda", "Odelia", "Odilia", "Olene", "Olevia", "Olimpia", "Olinda", "Tomiko", "Tommye", "Tomoko", "Zetta", "Zita", "Zofia", "Zonia", "Zulema", "Zulma" "Aaron", "Abe", "Abel", "Abraham", "Abram", "Adalberto", "Adam", "Adan", "Adolfo", "Adolph", "Adrian", "Agustin", "Al", "Alan", "Albert", "Alberto", "Alejandro", "Alex", "Alexander", "Alexis", "Alfonso", "Alfonzo", "Alfred", "Alfredo", "Amado", "Ambrose", "Amos", "Anderson", "Andre", "Anthony", "Antione", "Bernardo", "Bernie", "Berry", "Bert", "Bertram", "Bill", "Billie", "Billy", "Blaine", "Blair", "Blake", "Bo", "Bob", "Bobbie", "Bobby", "Booker", "Boris", "Boyce", "Boyd", "Brad", "Bradford", "Bradley", "Bradly", "Brady", "Brain", "Branden", "Brandon", "Brant", "Brendan", "Bryce", "Bryon", "Buck", "Bud", "Buddy", "Buford", "Burl", "Burt", "Burton", "Buster", "Byron", "Caleb", "Calvin", "Cameron", "Carey", "Carl", "Carlo", "Carlos", "Carlton", "Carmelo", "Carmen", "Chad", "Chadwick", "Chance", "Chang", "Charles", "Charley", "Charlie", "Chas", "Colin", "Cornell", "Cortez", "Cory", "Courtney", "Coy", "Craig", "Cristobal", "Cristopher", "Cruz", "Curt", "Curtis", "Cyril", "Cyrus", "Dale", "Dallas", "Dalton", "Damian", "Damien", "Danny", "Darnell", "Daron", "Darrel", "Darrell", "Darren", "Darrick", "Darrin", "Darron", "Darryl", "Delmar", "Delmer", "Demarcus", "Demetrius", "Denis", "Dennis", "Denny", "Denver", "Devon", "Dewayne", "Dewey", "Dewitt", "Dexter", "Dick", "Diego", "Dillon", "Dino", "Dion", "Dirk", "Domenic", "Domingo", "Dominic", "Dominick", "Dominique", "Don", "Donald", "Dong", "Donn", "Donnell", "Donnie", "Donny", "Donovan", "Donte", "Dudley", "Duncan", "Dustin", "Dusty", "Dwain", "Dwayne", "Dwight", "Dylan", "Earl", "Earle", "Earnest", "Ed", "Eddie", "Eddy", "Edmund", "Grady", "Graham", "Graig", "Grant", "Granville", "Greg", "Gregg", "Gregory", "Grover", "Guadalupe", "Jerome", "Jeromy", "Jerrell", "Jerrod", "Jerrold", "Jerry", "Jess", "Jesse", "Jessie", "Joaquin", "Jody", "Joe", "Joel", "Joesph", "Joey", "John", "Johnathan", "Johnathon", "Johnie", "Johnnie", "Johnson", "Jon", "Jonah", "Jonas", "Jonathan", "Jonathon", "Jordan", "Jordon", "Jorge", "Jose", "Josef", "Joseph", "Josh", "Joshua", "Josiah", "Julian", "Julio", "Julius", "Junior", "Justin", "Kareem", "Karl", "Kasey", "Keenan", "Keith", "Mario", "Marion", "Mark", "Markus", "Marlin", "Marlon", "Marquis", "Marshall", "Martin", "Marty", "Marvin", "Mary", "Mason", "Mathew", "Merlin", "Merrill", "Mervin", "Micah", "Michael", "Michal", "Michale", "Micheal", "Warner", "Warren", "Waylon", "Wayne", "Weldon", "Wendell", "Werner", "Wes", "Wesley", "Weston", "Whitney", "Wilber", "Wilbert", "Wilbur", "Wilburn", "Wiley", "Wilford", "Wilfred", "Yong", "Young", "Zachariah", "Zachary", "Zachery", "Zack", "Zackary", "Zane"
    };

    // Create file and set up column headers
    fprintf(stdout, "Creating / opening variables and file...\n");
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
    }

    const char *nameCol = "Full Name";
    const char *emailCol = "Email"; 
    const char *phoneCol = "Phone";
    fprintf(f, "%s,%s,%s\n", nameCol, emailCol, phoneCol);

    char *emailDomain[] = {
        "@gmail.com", "@yahoo.com", "@hotmail.com", "@mail.net"
        };

    // Allocate memory for buffer strings
    size_t emailLen = strlen(emailDomain[0])*sizeof(char *);
    char *emailBuffer = malloc(emailLen*sizeof(char *));

    size_t nameLen = strlen(names[0])*sizeof(char *);
    char *nameBuffer = malloc(nameLen*sizeof(char *));

    char *phone = "555-0";
    size_t phoneLen = strlen(phone)*sizeof(uint32_t);
    char *phoneBuffer = malloc(phoneLen*sizeof(char *));
    if (emailBuffer == NULL || nameBuffer == NULL || phoneBuffer == NULL) {
        printf("Null pointer(s) for buffer string(s)\n");
        goto cleanup;
    }

    char *firstNameBuffer = malloc(count*sizeof(char *));
    char *lastNameBuffer = malloc(count*sizeof(char *));
    if (firstNameBuffer == NULL || lastNameBuffer == NULL) {
        printf("Null pointer(s) for firstname / lastname buffer string(s)\n");
        goto cleanup;
    }

    fprintf(stdout, "Appending to file...\n");
    // Start loop to create and append strings to csv
    for (uint32_t i=0; i<count; ++i) {
        char *randEmailDomain = emailDomain[randomInteger(i*time(0), 0, 3, 1)];

        uint32_t phoneAreaCode = randomInteger(i, 201, 901, 1);
        uint32_t phoneSuffix = randomInteger(i+1, 100, 199, 1);

        snprintf(phoneBuffer, phoneLen + count, "(%d) %s%d", phoneAreaCode, phone, phoneSuffix);

        uint32_t firstNameRand = randomInteger(i*count, 0, sizeof(names)/sizeof(names[0])-1, 1);
        uint32_t lastNameRand = randomInteger(time(0)*count+i, 0, sizeof(names)/sizeof(names[0])-1, 1);

        sprintf(firstNameBuffer, "%s", names[firstNameRand]);
        sprintf(lastNameBuffer, "%s", names[lastNameRand]);

        snprintf(nameBuffer, nameLen * count, "%s %s", firstNameBuffer, lastNameBuffer);

        snprintf(emailBuffer, emailLen * count, "%s.%s%d%s", firstNameBuffer,lastNameBuffer, i, randEmailDomain);

        // Write to file
        fprintf(f, "%s,%s,%s\n", nameBuffer, emailBuffer, phoneBuffer);
    }
    
    // Close file and free allocated memory
    fprintf(stdout, "Closing file and freeing memory...\n");
    fclose(f);

    cleanup:
        free(emailBuffer);
        free(nameBuffer);
        free(phoneBuffer);
        free(firstNameBuffer);
        free(lastNameBuffer);

    return 1;
}

int main(int argc, char **argv) 
{
    uint32_t count = atoi(argv[1]);
    writeToFile("test1.csv", count);

    return argc;
}