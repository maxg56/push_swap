/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:10:32 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/14 16:45:16 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list *stack)
{
	t_list	*tmp;
	t_list	*last;


	tmp = stack;
	last = stack;
	while (last->next->next)
		last = last->next;
	stack = last->next;
	last->next = NULL;
	stack->next = tmp;
}

void	do_rra(t_list *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_list *stack_b)
{
	if (!stack_b || !stack_b->next)
		return ;
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_a->next || !stack_b || !stack_b->next)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
