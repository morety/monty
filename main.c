#include "monty.h"

void push(int line_number, char *arg) {
    int num;
    if (!isdigit(*arg)) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    num = atoi(arg);
    stack.stack[stack.top++] = num;
}

void pall() {
    int i;
    for (i = stack.top - 1; i >= 0; i--) {
        printf("%d\n", stack.stack[i]);
    }
}

void execute_opcode(char *opcode, int line_number, char *argument) {
    if (strcmp(opcode, "push") == 0) {
        if (argument == NULL) {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        push(line_number, argument);
    }
    else if (strcmp(opcode, "pall") == 0) {
        pall();
    }
    
    else {
        fprintf(stderr, "L%d: unknown opcode: %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

void run_monty_program(FILE *file) {
    char line[1000];
    char opcode[100];
    char argument[100];
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%s %s", opcode, argument) == 1) {
            execute_opcode(opcode, line_number, NULL);
        }
        else {
            execute_opcode(opcode, line_number, argument);
        }
        line_number++;
    }
}


