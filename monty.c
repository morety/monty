#include "monty.h"



/**
 * push - Pushes an element onto the stack
 * @line_number: The line number in the file
 * @arg: The argument to push onto the stack
 */



/**
 * pall - Prints all the values on the stack
 */

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: EXIT_SUCCESS if successful, otherwise EXIT_FAILURE
 */


int stack[STACK_SIZE];
int top = -1;

void push(int line_number, const char *arg)
{
    char *endptr;
    int value;

    if (arg == NULL)
    {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = strtol(arg, &endptr, 10);
    if (*endptr != '\0')
    {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    top++;
    stack[top] = value;
}

void pall()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[])
{
    FILE *file;
    char line[100];
    int line_number = 1;

    if (argc != 2)
    {
        printf("Usage: ./monty <filename>\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *opcode = strtok(line, " \n");
        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
            {
                char *arg = strtok(NULL, " \n");
                push(line_number, arg);
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall();
            }
        }

        line_number++;
    }

    fclose(file);

    return (EXIT_SUCCESS);
}

