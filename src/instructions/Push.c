/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:55:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/25 15:55:28 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b && *stack_b)
	{
		push(stack_b, stack_a);	
		ft_putstr_fd("pa\n", 1);
	}
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
	{
		push(stack_a, stack_b);	
		ft_putstr_fd("pb\n", 1);
	}
}
