/**
 * m_pop - Remove the top element from the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the current operation
 *
 * Return: void
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		/* Print error message and exit with failure */
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *pop = *stack; /* Save the top element */
	*stack = (*stack)->next; /* Update the stack pointer */
	
	if (*stack != NULL)
		(*stack)->prev = NULL; /* Update the previous pointer */

	free(pop); /* Free the top element */
	var.stack_len--;
}

/**
 * pop_opcode - Implement the pop opcode
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the current operation
 *
 * Return: void
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	m_pop(stack, line_number); /* Call the m_pop function */
}

