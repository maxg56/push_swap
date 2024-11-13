/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:10:32 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/13 17:45:55 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_pslst *stack)
{
	t_pslst	*tmp;
	t_pslst	*last;


	tmp = *stack;
	last = *stack;
	while (last->next->next)
		last = last->next;
	*stack = last->next;
	last->next = NULL;
	*stack->next = tmp;
}

void	do_rra(t_pslst *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_pslst *stack_b)
{
	if (!stack_b || !stack_b->next)
		return ;
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_pslst *stack_a, t_pslst *stack_b)
{
	if (!stack_a || !stack_a->next || !stack_b || !stack_b->next)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
