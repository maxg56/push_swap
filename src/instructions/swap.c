/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:25:01 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/21 13:25:53 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	do_sa(t_stack *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->next)
		return ;
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}
