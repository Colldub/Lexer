/*
    Cs 210 
    Lexer
    Collin Worth
*/


//open file

//loop
    //get next 
    //decied catagory
    //print out
    //check if we are done
    //if not repeat
//end loop

#include <stdio.h>

int isValidChar(char);
void sort(char*, int);
void printCatagory(char*, char*);

FILE *fptr;
char line[1000];
int i;
int segStart;
int segFinish;
char catName[20];

int main() {
    FILE *fptr;
    char line[1000];
    char fline[1000];
    int i;

    fptr = fopen("hello_world.ccx", "r");

    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, 1000, fptr) != NULL) { //receives all lines (needs to be modified for variable sizes(150))
        
    }

    for (i = 0; fline[i] != '\0'; i++){
        printf("%c", line[i]);
    }
    
    //sort(fline, 0);

    fclose(fptr);

    return 0;
}

//returns 1 if c is inbetween 32 and 126 inclusive to see if it is a character
int isValidChar(char c){
    return c >= 32 && c <= 126;
}

void sort (char* c, int i){
    segStart = i;

    if(c[i] == 47){ // "/"
        i++;
        printf("%s", "i = ");
        printf("%c", i);

        if(c[i] == 42){ // "*"
            i++;

            while(c[i] != 42){ //problem where infinite could occur
                i++;
            }
            
            i++;
            if(c[i] == 47){
                printCatagory("Comment", c);
                sort(c,i);
            }
        }
    }
}

void printCatagory(char* catagory, char* c){
    for(int i = segStart; i <= segFinish; i++){
        printf("%c", c[i]);
    }
    printf("%s", catagory);
}

//decide catagory
//void 


// Store the content of the file
//char myString[100];

// Read the content and store it inside myString
//fgets(myString, 100, fptr);

// Print the file content
//printf("%s", myString);

// Close the file
//fclose(fptr);