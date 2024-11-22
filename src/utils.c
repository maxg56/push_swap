/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:00:57 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/22 17:02:24 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prnit_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		len_a;
	int		len_b;

	current_a = *stack_a;
	current_b = *stack_b;
	len_a = ft_stacksize(current_a);
	len_b = ft_stacksize(current_b);
	while (current_a)
	{
		printf(" %d", current_a->value);
		if (len_b == len_a && current_b)
		{
			(ft_printf(" %d\n", current_b->value), len_b--);
			current_b = current_b->next;
		}
		else
			ft_printf(" \n");
		current_a = current_a->next;
	}
	ft_printf(" _ _\n a b \n");
}

/* exit_error:
*   Writes "Error\n" to the standard output after freeing stack a and b.
*	Exits with standard error code 1.
*/

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_a != NULL)
		ft_stackclear(stack_a);
	if (stack_b == NULL || stack_b != NULL)
		ft_stackclear(stack_b);
	(write(2, RED, 8), write(2, "Error\n", 6), write(2, DEF_COLOR, 8));
	exit(1);
}
