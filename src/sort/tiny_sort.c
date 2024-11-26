/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:43 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 17:10:17 by mgendrot         ###   ########.fr       */
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
		(do_sa(stack, NULL, TRUE), do_rra(stack, NULL, TRUE));
	else if (a > b && a > c)
		do_ra(stack, NULL, TRUE);
	else if (a > b)
		do_sa(stack, NULL, TRUE);
	else if (b > c && a < c)
		(do_sa(stack, NULL, TRUE), do_ra(stack, NULL, TRUE));
	else if (a < c)
		do_rra(stack, NULL, TRUE);
}
