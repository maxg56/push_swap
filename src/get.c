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



t_stack	*get_biggest(t_stack *stake)
{
	int		number;
	int		biggest;
	t_stack	*biggest_ptr;

	biggest_ptr = stake;
	while (stake)
	{
		number = stake->value;
		biggest = biggest_ptr->value;
		if (number > biggest)
			biggest_ptr = stake;
		stake = stake->next;
	}
	return (biggest_ptr);
}

t_stack	*get_smallest(t_stack *stack)
{
	int	number;
	int	biggest;
	t_stack	*biggest_ptr;

	biggest_ptr = stack;
	while (stack)
	{
		number = stack->value;
		biggest = biggest_ptr->value;
		if (number < biggest)
			biggest_ptr = stack;
		stack = stack->next;
	}
	return (biggest_ptr);
}

t_stack	*get_smaller(t_stack *stack, int target)
{
	int	current;
	t_stack	*smaller_ptr;

	smaller_ptr = stack;
	while (stack)
	{
		current = stack->value;
		if (current <= target)
		{
			if (target < smaller_ptr->value)
				smaller_ptr = stack;
			else if (current > smaller_ptr->value)
				smaller_ptr = stack;
		}
		stack = stack->next;
	}
	return (smaller_ptr);
}

t_stack	*get_bigger(t_stack *stack, int target)
{
	int	current;
	t_stack	*smaller_ptr;

	smaller_ptr = stack;
	while (stack)
	{
		current = stack->value;
		if (current >= target)
		{
			if (target > smaller_ptr->value)
				smaller_ptr = stack;
			else if (current < smaller_ptr->value)
				smaller_ptr = stack;
		}
		stack = stack->next;
	}
	return (smaller_ptr);
}
