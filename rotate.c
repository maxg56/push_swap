/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:02:50 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/14 16:44:00 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list *stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !stack || !stack->next)
		return ;
	tmp = stack;
	last = stack;
	while (last->next)
		last = last->next;
	stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	do_ra(t_list *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	do_rb(t_list *stack_b)
{
	if (!stack_b || !(stack_b)->next)
		return ;
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	do_rr(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_a->next || !stack_b || !stack_b->next)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
