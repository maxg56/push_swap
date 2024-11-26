/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:02:50 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 04:17:52 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotate:
 * Rotate the stack
 * @param stack: the stack to rotate
 */
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
}

/*do_ra:
 * Rotate the stack a
 * @param stack_a: the stack a
 */
void	do_ra(t_stack **stack_a)
{
	if (!stack_a)
		return ;
	(rotate(stack_a), ft_printf("ra\n"));
}

/*do_rb:
 * Rotate the stack b
 * @param stack_b: the stack b
 */
void	do_rb(t_stack **stack_b)
{
	if (!stack_b)
		return;
	(rotate(stack_b), ft_printf("rb\n"));
}

/*do_rr:
 * Rotate the stack a and the stack b
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	(ft_printf("rr\n"), rotate(stack_a), rotate(stack_b));
}
