/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:43 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/14 16:50:18 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void smolr_sort(t_list *stack);
void big_sort(t_list *stack_a, t_list *stack_b);
void sxe_sort(t_list *stack_a, t_list *stack_b, int len);
int is_sorted(t_list *stack);



void	push_swap(t_list *stack_a, t_list *stack_b)
{
	int	len;

	if (!stack_a || !stack_a->next)
		return ;
	len = ft_lstsize(stack_a);
	if (len <= 3)
	{
		smolr_sort(stack_a);
		return ;
	}
	else if (len <= 6)
	{
		sxe_sort(stack_a, stack_b, len);
	}
	else
	{
		big_sort(stack_a, stack_b);
	}
}


void	smolr_sort(t_list *stack)
{
	if (!stack || !stack->next || !stack->next->next)
		return ;
	if (stack->content > stack->next->content &&
		stack->next->content > stack->next->next->content)
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if (stack->content > stack->next->content &&
		stack->content > stack->next->next->content)
		do_ra(stack);
	else if (stack->content > stack->next->content)
		do_sa(stack);
	else if (stack->next->content > stack->next->next->content)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if (stack->content < stack->next->next->content)
		do_rra(stack);
}


void sxe_sort(t_list *stack_a, t_list *stack_b, int len)
{
	while (len-- > 3)
		do_pb(stack_a, stack_b);
	smolr_sort(stack_a);
	smolr_sort(stack_b);
	while (stack_b)
	{
		if (stack_b->content < stack_a->content)
			do_pa(stack_a, stack_b);
		else
			do_ra(stack_a);
	}
	while (!is_sorted(stack_a))
        do_ra(stack_a);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	big_sort(t_list *stack_a, t_list *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return ;
}


