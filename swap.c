/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:25:01 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/15 11:35:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

void	swap(t_list *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = *(int *)stack->content;
	*(int *)stack->content = *(int *)stack->next->content;
	*(int *)stack->next->content = tmp;
}

void	do_sa(t_list *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_list *stack_b)
{
	if (!stack_b || !stack_b->next)
		return ;
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}
