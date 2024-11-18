/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:02:50 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/18 17:42:31 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	last = ft_lstlast(*stack);
	*stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
}

int	do_ra(t_stack **stack_a)
{
	if (!stack_a)
		return (0);
	(rotate(stack_a), ft_putstr_fd("ra\n", 1));
	return (1);
}

int	do_rb(t_stack **stack_b)
{
	if (!stack_b)
		return (0);
	(rotate(stack_b), ft_putstr_fd("rb\n", 1));
	return (1);
}

int	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return (0);
	(ft_putstr_fd("rr\n", 1), rotate(stack_a), rotate(stack_b));
	return (1);
}
