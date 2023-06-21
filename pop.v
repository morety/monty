/**
 * m_pop - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *pop = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(pop);
	var.stack_len--;
}

