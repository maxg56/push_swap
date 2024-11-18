/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:10:32 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/18 17:42:01 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_stack_valid(t_stack **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return (0);
	return (1);
}

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*second_last;

	if (!is_stack_valid(stack))
		return ;

	tmp = *stack;
	last = *stack;
	second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = tmp;
	*stack = last;
}

int	do_rra(t_stack **stack_a)
{
	if (!is_stack_valid(stack_a))
		return (0);
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	return (1);
}

int	do_rrb(t_stack **stack_b)
{
	if (!is_stack_valid(stack_b))
		return (0);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_stack_valid(stack_a) && !is_stack_valid(stack_b))
		return (0);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}


