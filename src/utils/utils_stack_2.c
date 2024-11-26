/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:17:11 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 15:29:55 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ft_stackadd_back:
* Adds a new element to the end of the stack
*/
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = ft_stacklast(*stack);
	tmp->next = new;
}

/*ft_stackclear:
* Deletes and frees the stack
*/
t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*ft_stackindex:
* Returns the index of the stack element.
* Returns -1 if the element is not found.
*/
int	ft_stackindex(t_stack *stack, t_stack *ptr)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack == ptr)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}
