/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:43 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/25 21:31:53 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*tiny_sort:
*	- Sorts a stack of 3 elements or less
*	- If the stack is already sorted, it does nothing
*	- If the stack is not sorted, it sorts it with a maximum of 3 operations
*	- The function is called by sort_stacks
*/
void	tiny_sort(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	if (is_sorted(*stack))
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;

	if (a > b && b > c)
		(do_sa(*stack), do_rra(stack));
	else if (a > b && a > c)
		do_ra(stack);
	else if (a > b)
		do_sa(*stack);
	else if (b > c && a < c)
		(do_sa(*stack), do_ra(stack));
	else if (a < c)
		do_rra(stack);
}
