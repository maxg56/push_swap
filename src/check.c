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

/* is_sorted :
*	Checks if a stack is sorted.
*	Returns FALSE if the stack is not sorted, TRUE if it is sorted.
*/
t_bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

/* is_mini :
*	Checks if the value n is the smallest in the stack.
*	Returns TRUE if n is the smallest, FALSE otherwise.
*/
t_bool	is_mini(int n, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_b->value < n)
			return (FALSE);
		stack_b = stack_b->next;
	}
	return (TRUE);
}

/* is_maxi :
*	Checks if the value n is the largest in the stack.
*	Returns TRUE if n is the largest, FALSE otherwise.
*/
t_bool	is_maxi(int n, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_b->value > n)
			return (FALSE);
		stack_b = stack_b->next;
	}
	return (TRUE);
}
