#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <getopt.h>

#include "encode.h"

#define ROWLEN 5

int main(int argc, char** argv){
    
    /** Implement options and crap after main functionality is implemented
    char option;

     * -c Cypher
     * -f File
     * -d option to decrypt
     while ((option = getopt(argc, argv, "f:a:m:q:")) != EOF){
         switch(option){
             
        }
        
    }
    */

    printf("%s", checkCypher("abcdefghij") ? "" : "CYPHER UNUSABLE\n");

    char* message = "ELA thicc af boi";
    char** encoded = encode("quickthrow", message);
    int nPrints = 0;
    
    for(int i = 0; i < strlen(message); i++){
        printf("%s", encoded[i][0] ? strcat(encoded[i], " ") : "");
        nPrints++;
        if(nPrints % ROWLEN == 0){
            printf("\n");
        }
    }

    printf("done\n");
    return 0;
}