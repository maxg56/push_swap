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

/*get_do_r_cost :
*	Returns the cost of rotating the stack to the right to reach the target
*	-1 if the target is not in the stack
*/
static int	get_do_r_cost(t_stack *target, t_stack *stack)
{
	int	index;

	index = ft_stackindex(stack, target);
	if (index == -1)
		return (-1);
	return (index);
}

/*get_do_rr_cost :
*- Returns the cost of reverse_rotate the stack to the left to reach the target
*- -1 if the target is not in the stack
*/
static int	get_do_rr_cost(t_stack *target, t_stack *stack)
{
	int	index;

	index = ft_stackindex(stack, target);
	if (index == -1)
		return (-1);
	return (ft_stacksize(stack) - index);
}

/* get_rotation_way :
*	Returns the way to rotate the stack to reach the target
*	- TRUE if the target is closer by rotating the stack to the right
*	- FALSE if the target is closer by rotating the stack to the left
*/
t_bool	get_rotation_way(t_stack *target, t_stack *stack)
{
	int		cost;
	int		cost_r;

	cost = get_do_r_cost(target, stack);
	cost_r = get_do_rr_cost(target, stack);
	if (cost == -1 || cost_r == -1)
		return (FALSE);
	if (cost <= cost_r)
		return (TRUE);
	return (FALSE);
}

/*get_move_cost :
*	Returns the cost of moving the target to the source
*	-1 if the target is not in the stack
*/
int	get_move_cost(t_stack *stack_a, t_stack *source
					, t_stack *stack_b, t_stack *target)
{
	int		total_a;
	int		total_b;

	if (get_rotation_way(source, stack_a) == get_rotation_way(target, stack_b))
	{
		total_a = get_do_r_cost(source, stack_a);
		total_b = get_do_r_cost(target, stack_b);
		if (!get_rotation_way(source, stack_a))
		{
			total_a = get_do_rr_cost(source, stack_a);
			total_b = get_do_rr_cost(target, stack_b);
		}
		if (total_a > total_b)
			return (total_a);
		return (total_b);
	}
	if (get_rotation_way(source, stack_a))
		total_a = get_do_r_cost(source, stack_a);
	else
		total_a = get_do_rr_cost(source, stack_a);
	if (get_rotation_way(target, stack_b))
		total_b = get_do_r_cost(target, stack_b);
	else
		total_b = get_do_rr_cost(target, stack_b);
	return (total_a + total_b + 1);
}
