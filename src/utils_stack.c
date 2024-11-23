/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max_dev <max_dev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:34:25 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/23 18:37:51 by max_dev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

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

void	ft_stackadd(t_stack **stak, t_stack *new)
{
	if (!stak || !new)
		return ;
	new->next = *stak;
	*stak = new;
}

void	ft_stackdelone(t_stack *stak)
{
	if (!stak)
		return ;
	free(stak);
}

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
}
