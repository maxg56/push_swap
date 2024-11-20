/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:57:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/20 09:43:05 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prit_stack(t_stack **stack_a, t_stack **stack_b)
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
		printf(" %d", current_a->nb);
		if (len_b == len_a && current_b)
		{
			(printf(" %d\n", current_b->nb), len_b--);
			current_b = current_b->next;
		}
		else
			printf(" \n");
		current_a = current_a->next;
	}
	printf(" _ _\n a b \n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		ft_printf("\033[0;91mError\n");
		return (0);
	}
	stack_a = NULL;
	stack_b = NULL;
	if (!parse(argv, &stack_a))
	{
		ft_printf("\033[0;91mError\n");
		return (0);
	}
	ft_prit_stack(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	ft_prit_stack(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
