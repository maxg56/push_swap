/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:15:26 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 04:26:06 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*finalize_a:
 * Finalize the stack a
 * @param stack_a: the stack a
 */
static void	finalize_a(t_stack **stack_a)
{
	t_stack	*target;

	target = get_smallest(*stack_a);
	while (*stack_a != target)
	{
		if (get_rotation_way(target, *stack_a))
			do_ra(stack_a);
		else if (!get_rotation_way(target, *stack_a))
			do_rra(stack_a);
		else
			break ;
	}
}

/*get_move_cost:
 * Get the cost of the move
 * @param src_stack: the source stack
 * @param src: the source element
 * @param tgt_stack: the target stack
 * @param tgt: the target element
 * @return: the cost of the move
 */
static	t_move	*update_move(int cost, t_stack *source, t_stack *target)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	move->cost = cost;
	move->target = target;
	move->source = source;
	return (move);
}

/*get_move_cost:
 * Get the cost of the move
 * @param src_stack: the source stack
 * @param src: the source element
 * @param tgt_stack: the target stack
 * @param tgt: the target element
 * @return: the cost of the move
 */
static t_move	*find_best_move(t_stack *src_stack, t_stack *tgt_stack)
{
	t_stack	*temp_source;
	t_stack	*temp_target;
	t_move	*move;
	int		latest_cost;

	move = update_move(INT_MAX, NULL, NULL);
	temp_source = src_stack;
	temp_target = tgt_stack;
	while (temp_source)
	{
		if (is_mini(temp_source->value, tgt_stack))
			temp_target = get_biggest(tgt_stack);
		else
			temp_target = get_smaller(tgt_stack,temp_source->value);
		latest_cost = get_move_cost(src_stack,
				temp_source, tgt_stack, temp_target);
		if (latest_cost < move->cost)
			move = update_move(latest_cost, temp_source, temp_target);
		temp_source = temp_source->next;
	}
	return (move);
}

/*fiexecute_move:
 * Execute the move
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 * @param move: the move to execute
 */
static	void	fiexecute_move(t_stack **stack_a, t_stack **stack_b, t_move *move)
{
	while (*stack_a != move->source && *stack_b != move->source)
	{
		if (get_rotation_way(move->source, *stack_a) == 1
			&& get_rotation_way(move->target, *stack_b) == 1)
			do_rr(stack_a, stack_b);
		else if (get_rotation_way(move->source, *stack_a) == 0
			&& get_rotation_way(move->target, *stack_b) == 0)
			do_rrr(stack_a, stack_b);
		else
			break ;
	}
	if (get_rotation_way(move->source, *stack_a) == 1)
		while (*stack_a != move->source)
			do_ra(stack_a);
	else
		while (*stack_a != move->source)
			do_rra(stack_a);
	if (get_rotation_way(move->target, *stack_b) == 1)
		while (*stack_b != move->target)
			do_rb(stack_b);
	else
		while (*stack_b != move->target)
			do_rrb(stack_b);
	do_pb(stack_a, stack_b);
	return ;
}

/*sort_stacks:
 * Sort the stacks
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
void	sort_stacks(t_stack **stack_a, t_stack **stack_b) 
{
	t_move	*move;

	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
	while (*stack_a)
    {
		move = find_best_move(*stack_a, *stack_b);
		fiexecute_move(stack_a, stack_b, move);
	}
	while (*stack_b)
		do_pa(stack_a, stack_b);
	finalize_a(stack_a);
	free(move);
	return ;
}

