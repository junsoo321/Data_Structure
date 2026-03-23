#pragma once

#include <stdio.h>

#define BUFFER_SIZE 50

#define true 1
#define false 0

void line();

int getInt(char* label);
char* getChar(char* label, const int size);

typedef struct week{
    int number;
    void (*operate) (void);
};

void run(const int number);