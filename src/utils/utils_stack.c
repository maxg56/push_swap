/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:34:25 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/28 12:48:36 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_stacksize:
* Returns the size of the stack
*/
int	ft_stacksize(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/* ft_stacknew:
* Creates a new stack element with the given value 
*/
t_stack	*ft_stacknew(int nb)
{
	t_stack	*stak;

	stak = malloc(sizeof(t_stack));
	if (!stak)
		return (NULL);
	stak->next = NULL;
	stak->value = nb;
	return (stak);
}

/* ft_stackadd:
 * Adds a new element to the top of the stack
*/
void	ft_stackadd(t_stack **stak, t_stack *new)
{
	if (!stak || !new)
		return ;
	new->next = *stak;
	*stak = new;
}

/* ft_stackdelone:
 * Deletes an element from the stack
*/
static void	ft_stackdelone(t_stack *stak)
{
	if (!stak)
		return ;
	free(stak);
}

/* ft_stackclear:
 * Deletes all elements from the stack
*/
void	ft_stackclear(t_stack **stak)
{
	t_stack	*tmp;

	if (!stak)
		return ;
	while (*stak)
	{
		tmp = (*stak)->next;
		ft_stackdelone(*stak);
		*stak = tmp;
	}
	*stak = NULL;
}
