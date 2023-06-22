#include "monty.h"

/**
 * m_swap - swap the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->prev == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->prev;
    (*stack)->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = *stack;
    temp->prev = *stack;
    (*stack)->next = temp;
    *stack = temp;
}

