/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:15:26 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/25 13:59:49 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int max_value;
	t_stack	*temp;

	max = 0;
	max_value = 0;
	temp = stack;
	while (temp)
	{
		if (temp->value > max)
			max_value = temp->value;
		temp = temp->next;
	}
	while (max_value >> max)
		max++;
	return (max);
}



void radix_sort(t_stack **stack_a, t_stack **stack_b) 
{
	int max_bits;
	int size;
	int i;
	int	j;
	int num;

	size = ft_stacksize(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while ( j < size)
		{
			num = (*stack_a)->value;
			ft_prnit_stack(stack_a, stack_b);
			if ((num >> i) & 1)
				do_ra(stack_a);
			else
				do_pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
		{
			do_pa(stack_b, stack_a);
			ft_prnit_stack(stack_a, stack_b);
		}
		i++;
	}
}

