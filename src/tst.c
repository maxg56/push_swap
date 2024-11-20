/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:45:33 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/20 13:54:21 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	i;
	int	len;

	len = ft_stacksize(*stack_a);
	while (len > 0)
	{
		i = 0;
		while (i < chunk_size && len > 0)
		{
			do_pb(stack_a, stack_b);
			i++;
			len--;
		}
	}
}
void	sort_chunk(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stacksize(*stack_b);
	while (len > 0)
	{
		if ((*stack_b)->nb < (*stack_a)->nb)
			do_pa(stack_a, stack_b);
		else
			do_ra(stack_a);
		len--;
	}
}

void	merge_chunks(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		do_pa(stack_a, stack_b);
	}
}

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;

	chunk_size = 5;
	divide_chunks(stack_a, stack_b, chunk_size);
	while (*stack_b)
	{
		sort_chunk(stack_a, stack_b);
	}
	merge_chunks(stack_a, stack_b);
}
