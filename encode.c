#include "encode.h"
#include <stdlib.h>
#include <strings.h>

int checkCypher(char* cypher){
    int len = strlen(cypher);

    if(len < 10){
        return 0;
    }

    for(int i = 0; i < len-1; i++){
        for(int j = i+1; j < len; j++){
            if(cypher[i] == cypher[j] || !isLetter(cypher[i])){
                return 0;
            }
        }
    }

    return 1;
}

char** encode(char* cypher, char* message){
    int msgLen = strlen(message);

    int currNum = 0;
    int let1;
    int let2;

    int si = 0;

    char** strings = malloc(sizeof(char*) * msgLen);
    
    for(int i = 0; i < msgLen; i++){
        strings[i] = calloc(3, sizeof(char));
    }

    for(int i= 0; i < msgLen; i++){
        if(!isLetter(message[i])){
            continue;
        }

        currNum = alphaNum(message[i]) - 1;
        
        let1 = currNum / 10; //purposeful int division
        let2 = currNum - let1 * 10;

        strings[si][0] = toUpper(cypher[let1]);
        strings[si][1] = toUpper(cypher[let2]);

        ++si;

    }
    

    return strings;
}

int isLetter(char letter){
    return (letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z');
}

char toLower(char letter){
    /* returns '-' if non alphabetical */ 
    if(letter >= 'A' && letter <= 'Z'){
        return letter - 'A' + 'a';
    }
    else if(letter >= 'a' && letter <= 'z'){
        return letter;
    }
    else {
        return 0;
    }
}

char toUpper(char letter){
    if(letter >= 'A' && letter <= 'Z'){
        return letter;
    }
    else if(letter >= 'a' && letter <= 'z'){
        return letter + 'A' - 'a';
    }
    else {
        return 0;
    }
}

char alphaNum(char letter){
    if(isLetter(letter)){
        return toLower(letter) - 'a' + 1;
    }
    return 0;
}