/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:43 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/20 13:55:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stacksize(*stack_a);
	if (len <= 3)
		smoll_sort(stack_a);
	else if (len <= 6)
		sxe_sort(stack_a, stack_b, len);
	else
		turk_algorithm(stack_a, stack_b);
}

void	smoll_sort(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	if (is_sorted(*stack))
		return ;
	a = (*stack)->nb;
	b = (*stack)->next->nb;
	c = (*stack)->next->next->nb;

	if (a > b && b > c)
		(do_sa(*stack), do_rra(stack));
	else if (a > b && a > c)
		do_ra(stack);
	else if (a > b)
		do_sa(*stack);
	else if (b > c && a < c)
		(do_sa(*stack), do_ra(stack));
	else if (a < c)
		do_rra(stack);
}

void	sxe_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	while (len-- > 3)
		do_pb(stack_a, stack_b);
	smoll_sort(stack_a);
	smoll_sort(stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->nb < (*stack_a)->nb)
			do_pa(stack_a, stack_b);
		else
			do_ra(stack_a);
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

