/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduvey <mduvey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:23:12 by mduvey            #+#    #+#             */
/*   Updated: 2024/11/13 18:25:42 by mduvey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstindex(t_stack *stack, t_stack *ptr)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack == ptr)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	get_rotation_way(t_stack *target, t_stack *stack)
{
	int		cost;
	int		cost_r;

	cost = get_rotation_cost(target, stack);
	cost_r = get_reverse_rotation_cost(target, stack);
	if (cost == -1 || cost_r == -1)
		return (-1);
	if (cost <= cost_r)
		return (1);
	return (0);
}

int	get_move_cost(t_stack *stack_a, t_stack *source,
					 t_stack *stack_b, t_stack *target)
{
	int		total_a;
	int		total_b;

	if (get_rotation_way(source, stack_a) == get_rotation_way(target, stack_b))
	{
		total_a = get_rotation_cost(source, stack_a);
		total_b = get_rotation_cost(target, stack_b);
		if (get_rotation_way(source, stack_a) == 0)
		{
			total_a = get_reverse_rotation_cost(source, stack_a);
			total_b = get_reverse_rotation_cost(target, stack_b);
		}
		if (total_a > total_b)
			return (total_a);
		return (total_b);
	}
	if (get_rotation_way(source, stack_a) == 1)
		total_a = get_rotation_cost(source, stack_a);
	else
		total_a = get_reverse_rotation_cost(source, stack_a);
	if (get_rotation_way(target, stack_b) == 1)
		total_b = get_rotation_cost(target, stack_b);
	else
		total_b = get_reverse_rotation_cost(target, stack_b);
	return (total_a + total_b + 1);
}

int	get_rotation_cost(t_stack *target, t_stack *stack)
{
	int	index;

	index = ft_lstindex(stack, target);
	if (index == -1)
		return (-1);
	return (index);
}

int	get_reverse_rotation_cost(t_stack *target, t_stack *stack)
{
	int	index;

	index = ft_lstindex(stack, target);
	if (index == -1)
		return (-1);
	return (ft_stacksize(stack) - index);
}
