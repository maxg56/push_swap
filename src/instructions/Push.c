/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:55:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/18 17:41:15 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_strte, t_stack **stack_dest)
{
	t_stack	*tmp;

	if (!stack_strte)
		return ;
	tmp = *stack_strte;
	*stack_strte = (*stack_strte)->next;
	tmp->next = *stack_dest;
	*stack_dest = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	(push(stack_b, stack_a), ft_putstr_fd("pa\n", 1));
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	(push(stack_a, stack_b), ft_putstr_fd("pb\n", 1));
}
