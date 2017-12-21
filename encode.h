#ifndef ENCODE_H
#define ENCODE_H

#define CYPHERLEN 10

int checkCypher(char* cypher);

char** encode(char* cypher, char* message);

char standardise(char letter);

int isLetter(char letter);

char toLower(char letter);

char toUpper(char letter);

char alphaNum(char letter);

#endif