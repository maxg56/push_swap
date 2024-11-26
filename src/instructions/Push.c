/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:55:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 04:21:58 by max_dev          ###   ########.fr       */
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

	if (!src || !dest)
		return ;
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
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b && *stack_b)
	{
		push(stack_b, stack_a);	
		ft_printf("pa\n");
	}
}

/*do_pb:
 * Push the first element of stack a to stack b
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
	{
		push(stack_a, stack_b);	
		ft_printf("pb\n");
	}
}
