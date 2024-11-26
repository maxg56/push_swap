/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:55:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 18:47:24 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push:
 * Push an element from the source stack to the destination stack
 * @param src: the source stack
 * @param dest: the destination stack
 */
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

/*do_pa:
 * Push the first element of stack b to stack a
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	do_pa(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	if (stack_b && *stack_b)
	{
		push(stack_b, stack_a);
		if (print)
			ft_printf("pa\n");
	}
	else
		exit_error(stack_a, stack_b);
}

/*do_pb:
 * Push the first element of stack a to stack b
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	do_pb(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	if (stack_a && *stack_a)
	{
		push(stack_a, stack_b);
		if (print)
			ft_printf("pb\n");
	}
	else
		exit_error(stack_a, stack_b);
}
