/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:00:57 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/25 21:30:41 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_print_stack:
* Prints the elements of stack_a and stack_b.
* The elements of stack_a are printed first, followed by the elements
* of stack_b if both stacks have the same length.
*/
void	ft_print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		len_a;
	int		len_b;

	current_a = *stack_a;
	current_b = *stack_b;
	len_a = ft_stacksize(current_a);
	len_b = ft_stacksize(current_b);
	while (current_a)
	{
		ft_printf(" %d", current_a->value);
		if (len_b == len_a && current_b)
		{
			(ft_printf(" %d\n", current_b->value), len_b--);
			current_b = current_b->next;
		}
		else
			ft_printf(" \n");
		current_a = current_a->next;
		len_a--;
	}
	ft_printf(" _ _\n a b \n");
}

/* exit_error:
*	Writes "Error\n" to the standard output after freeing stack a and b.
*	Exits with standard error code 1.
*/
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_a != NULL)
		ft_stackclear(stack_a);
	if (stack_b == NULL || stack_b != NULL)
		ft_stackclear(stack_b);
	(write(2, RED, 8), write(2, "Error\n", 6), write(2, DEF_COLOR, 8));
	exit(1);
}

/* ft_stacksize:
* Returns the size of the stack.
*/
static int ft_strrlen(char **s)
{
	int len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

/* free_stack:
* Frees all the elements of the stack.
*/
char	**free_arr(char **split)
{
	int i;

	i = ft_strrlen(split);
	while (i > 0)
		free(split[--i]);
	free(split);
	return (NULL);
}

/*ft_stackindex:
* Returns the index of the stack element.
* Returns -1 if the element is not found.
*/
int	ft_stackindex(t_stack *stack, t_stack *ptr)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack == ptr)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}
