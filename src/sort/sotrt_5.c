/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sotrt_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:54:44 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 17:12:14 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort_stacks_5:
 * Sorts the stacks with 5 elements
 * @param a: the stack a
 * @param b: the stack b
 */
void	sort_stacks_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_target;

	while (ft_stacksize(*stack_a) > 3)
		do_pb(stack_a, stack_b, TRUE);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		if (is_maxi((*stack_b)->value, *stack_a))
			temp_target = get_smallest(*stack_a);
		else
			temp_target = get_bigger(*stack_a, (*stack_b)->value);
		while (*stack_a != temp_target)
		{
			if (get_rotation_way(temp_target, *stack_a))
				do_ra(stack_a, stack_b, TRUE);
			else if (!get_rotation_way(temp_target, *stack_a))
				do_rra(stack_a, stack_b, TRUE);
		}
		do_pa(stack_a, stack_b, TRUE);
	}
	temp_target = get_smallest(*stack_a);
	while (*stack_a != temp_target)
		do_ra(stack_a, stack_b, TRUE);
}
