/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:10:37 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/12 17:12:13 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*get_biggest:
 * Get the biggest element of the stack
 */
t_stack	*get_biggest(t_stack *stake)
{
	int		number;
	int		biggest;
	t_stack	*biggest_ptr;

	biggest_ptr = stake;
	while (stake)
	{
		number = stake->value;
		biggest = biggest_ptr->value;
		if (number > biggest)
			biggest_ptr = stake;
		stake = stake->next;
	}
	return (biggest_ptr);
}

/*get_smallest:
 * Get the smallest element of the stack
 */
t_stack	*get_smallest(t_stack *stack)
{
	t_stack	*biggest_ptr;

	biggest_ptr = stack;
	while (stack)
	{
		if (stack->value < biggest_ptr->value)
			biggest_ptr = stack;
		stack = stack->next;
	}
	return (biggest_ptr);
}

/*get_smaller:
 * Get the smaller element of the stack
 */
t_stack	*get_smaller(t_stack *stack, int target)
{
	t_stack	*smaller_ptr;

	smaller_ptr = stack;
	while (stack)
	{
		if (stack->value <= target)
		{
			if (target < smaller_ptr->value)
				smaller_ptr = stack;
			else if (stack->value > smaller_ptr->value)
				smaller_ptr = stack;
		}
		stack = stack->next;
	}
	return (smaller_ptr);
}

/*get_bigger:
 * Get the bigger element of the stack
 */
t_stack	*get_bigger(t_stack *stack, int target)
{
	t_stack	*smaller_ptr;

	smaller_ptr = stack;
	while (stack)
	{
		if (stack->value >= target)
		{
			if (target > smaller_ptr->value)
				smaller_ptr = stack;
			else if (stack->value < smaller_ptr->value)
				smaller_ptr = stack;
		}
		stack = stack->next;
	}
	return (smaller_ptr);
}
