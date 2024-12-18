/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:10:32 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/28 13:06:44 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*reverse_rotate:
 * Reverse rotate the stack
 * @param stack: the stack to reverse rotate
 */
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	last = NULL;
	second_last = NULL;
	while (tmp->next)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/*do_rra:
 * Reverse rotate the stack a
 * @param stack_a: the stack a
 */
void	do_rra(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	if (!is_stack_valid(stack_a))
		exit_error(stack_a, stack_b);
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

/*do_rrb:
 * Reverse rotate the stack b
 * @param stack_b: the stack b
 */
void	do_rrb(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	if (!is_stack_valid(stack_b))
		exit_error(stack_a, stack_b);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

/*do_rrr:
 * Reverse rotate the stack a and b
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	if (!is_stack_valid(stack_a) || !is_stack_valid(stack_b))
		exit_error(stack_a, stack_b);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
