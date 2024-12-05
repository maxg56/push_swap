/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:57:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/12/05 00:37:05 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_swap :
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a, stack_b, TRUE);
	else if (stack_size == 3)
		tiny_sort(stack_a, stack_b);
	else if (stack_size > 3 && stack_size < 6 && !is_sorted(*stack_a))
		sort_stacks_5(stack_a, stack_b);
	else if (stack_size > 5 && !is_sorted(*stack_a))
		sort_stacks(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		exit_error(NULL, NULL);
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_input(ac, av, &stack_a))
		exit_error(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b, ft_stacksize(stack_a));
	ft_stackclear(&stack_a);
	if (stack_b)
		ft_stackclear(&stack_b);
	return (0);
}
