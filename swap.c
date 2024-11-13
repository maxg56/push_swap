/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:25:01 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/13 13:03:21 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void	swap(t_pslst *stack)
{
	int	tmp;

	if (stack && stack->next)
		return ;
	tmp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = tmp;
}

void	do_sa(t_pslst *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_pslst *stack_b)
{
	if (!stack_b || !stack_b->next)
		return ;
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	do_ss(t_pslst *stack_a, t_pslst *stack_b)
{
	if (!stack_a || !stack_a->next || !stack_b || !stack_b->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
