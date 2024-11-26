/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:25:01 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 04:21:33 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

/*swap:
 * Swap the first two elements of the stack
 * @param stack: the stack to swap
 */
static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

/*do_sa:
 * Swap the first two elements of stack a
 * @param stack_a: the stack a
 */
void	do_sa(t_stack *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

/*do_sb:
 * Swap the first two elements of stack b
 * @param stack_b: the stack b
 */
void	do_sb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->next)
		return ;
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

/*do_ss:
 * Swap the first two elements of stack a and stack b
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->next)
		swap(stack_a);
	if (stack_b && stack_b->next)
		swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}