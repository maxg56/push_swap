/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:55:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/13 12:58:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pslst *stack_a, t_pslst *stack_b)
{
	t_pslst	*tmp;

	tmp = stack_b;
	stack_b = stack_b->next;
	tmp->next = stack_a;
	stack_a = tmp;
}

void	do_pa(t_pslst *stack_a, t_pslst *stack_b)
{
	if (!stack_b)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(t_pslst *stack_a, t_pslst *stack_b)
{
	if (!stack_a)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
