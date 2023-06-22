#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value, int line_number) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

void pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    FILE *file;
    int line_number = 1;
    char opcode[5];
    int argument;

    file = fopen("bytecodes/00.m", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%4s %d", opcode, &argument) == 2) {
        if (strcmp(opcode, "push") == 0) {
            push(argument, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        line_number++;
    }

    fclose(file);
    return 0;
}
        

