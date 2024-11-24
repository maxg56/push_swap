/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:15:26 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/23 21:14:17 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  get_max_bits(int max) 
{
	int bits;
	
	bits = 0;
	while (max > 0)
	{
		max >>= 1; 
		bits++;
	}
	return (bits);
}

static int  find_max(t_stack *stack) 
{
	int	max;
	
	max = stack->value;
	while (stack) 
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b) 
{
    int max = find_max(*stack_a);
    int max_bits = get_max_bits(max);
    int size = ft_stacksize(*stack_a); // Nombre total d'éléments

    for (int i = 0; i < max_bits; i++) {
        for (int j = 0; j < size; j++) {
            int num = (*stack_a)->value;
			ft_prnit_stack(stack_a,stack_b);
            if ((num >> i) & 1) {
                do_ra(stack_a); // Si le bit est 1, faire une rotation
            } else {
                do_pb(stack_a, stack_b); // Si le bit est 0, pousser dans B
            }
        }
        // Rassembler tous les éléments de B dans A
        while (ft_stacksize(*stack_b) > 0) {
            do_pa(stack_b, stack_a);
			ft_prnit_stack(stack_a,stack_b);
        }
    }
}

