#include "monty.h"

Stack stack;

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./monty <file_path>\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    stack.top = 0;
    run_monty_program(file);

    fclose(file);
    return (EXIT_SUCCESS);
}

