#pragma once

#define STRING_MAX 100

typedef char letter;

letter string[STRING_MAX];
int stringTop = -1;

int isStringEmpty();
letter popString();
void printString();