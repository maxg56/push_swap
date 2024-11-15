/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:55:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/15 11:32:23 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_b;
	stack_b = stack_b->next;
	tmp->next = stack_a;
	stack_a = tmp;
}

void	do_pa(t_list *stack_a, t_list *stack_b)
{
	(push(stack_a, stack_b), ft_putstr_fd("pa\n", 1));
}

void	do_pb(t_list *stack_a, t_list *stack_b)
{
	(push(stack_b, stack_a), ft_putstr_fd("pb\n", 1));
}
