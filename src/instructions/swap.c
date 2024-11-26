/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:25:01 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 17:54:29 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

/*swap:
 * Swap the first two elements of the stack
 * @param stack: the stack to swap
 */
static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
}

/*do_sa:
 * Swap the first two elements of stack a
 * @param stack_a: the stack a
 */
void	do_sa(t_stack **stack_a, t_stack **stack_b,	t_bool print)
{
	if (!is_stack_valid(stack_a))
		exit_error(stack_a, stack_b);
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

/*do_sb:
 * Swap the first two elements of stack b
 * @param stack_b: the stack b
 */
void	do_sb(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	if (!is_stack_valid(stack_b))
		exit_error(stack_a, stack_b);
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

/*do_ss:
 * Swap the first two elements of stack a and stack b
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	do_ss(t_stack **stack_a, t_stack **stack_b, t_bool print)
{
	if (!is_stack_valid(stack_a) && !is_stack_valid(stack_b))
		exit_error(stack_a, stack_b);
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
