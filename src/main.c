/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:57:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/18 16:05:01 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_prit_stack(t_list **stack_a, t_list **stack_b)
{
	t_list *current_a = *stack_a;
	t_list *current_b = *stack_b;
	int len_a = ft_lstsize(current_a);
	int len_b = ft_lstsize(current_b);

	while (current_a)
	{
		printf(" %d", *(int *)current_a->content);
		if (len_b == len_a && current_b)
		{
			printf(" %d\n", *(int *)current_b->content);
			current_b = current_b->next;
			len_b--;
		}
		else
		{
			printf(" \n");
		}
		current_a = current_a->next;
	}
	printf(" _ _\n a b \n");
}
int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ft_lstnew((void *)malloc(sizeof(int)));
	*(int *)stack_a->content = 6;
	stack_b = ft_lstnew(NULL);
	ft_lstadd_back(&stack_a, ft_lstnew((void *)malloc(sizeof(int))));
	*(int *)stack_a->next->content = 4;
	ft_lstadd_back(&stack_a, ft_lstnew((void *)malloc(sizeof(int))));
	*(int *)stack_a->next->next->content = 5;
	ft_lstadd_back(&stack_a, ft_lstnew((void *)malloc(sizeof(int))));
	*(int *)stack_a->next->next->next->content = 3;
	ft_lstadd_back(&stack_a, ft_lstnew((void *)malloc(sizeof(int))));
	*(int *)stack_a->next->next->next->next->content = 2;
	ft_lstadd_back(&stack_a, ft_lstnew((void *)malloc(sizeof(int))));
	*(int *)stack_a->next->next->next->next->next->content = 1;
	ft_prit_stack(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	ft_prit_stack(&stack_a, &stack_b);

	// Free allocated memory
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);

	return (0);
}
