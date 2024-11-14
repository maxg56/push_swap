/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:57:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/14 17:56:04 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(void)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = ft_lstnew((void *)1);
	stack_b = NULL;
	ft_lstadd_back(&stack_a, ft_lstnew((void *)3));
	ft_lstadd_back(&stack_a, ft_lstnew((void *)2));
	while (stack_a)
	{
		printf("stack_a: %d\n", *(int *)stack_a->content);
		printf("stack_b: %d\n", *(int *)stack_b->content);
		stack_a = stack_a->next;
	}
	push_swap(stack_a, stack_b);
	while (stack_a)
	{
		printf("stack_a: %d\n", *(int *)stack_a->content);
		printf("stack_b: %d\n", *(int *)stack_b->content);
		stack_a = stack_a->next;
	}
	return 0;
}
