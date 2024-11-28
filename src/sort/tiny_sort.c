/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:43 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/28 10:38:38 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*tiny_sort:
*	- Sorts a stack of 3 elements or less
*	- If the stack is already sorted, it does nothing
*	- If the stack is not sorted, it sorts it with a maximum of 3 operations
*	- The function is called by sort_stacks
*/
void	tiny_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	if (is_sorted(*stack_a))
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b > c)
		(do_sa(stack_a, stack_b, TRUE), do_rra(stack_a, stack_b, TRUE));
	else if (a > b && a > c)
		do_ra(stack_a, stack_b, TRUE);
	else if (a > b)
		do_sa(stack_a, stack_b, TRUE);
	else if (b > c && a < c)
		(do_sa(stack_a, stack_b, TRUE), do_ra(stack_a, stack_b, TRUE));
	else if (a < c)
		do_rra(stack_a, stack_b, TRUE);
}
