/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:10:37 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/12 17:12:13 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_is_minimum(int n, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_b->value < n)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	get_is_maximum(int n, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_b->value > n)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}
