/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:18:43 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/13 16:37:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_pslst *stack_a, t_pslst *stack_b)
{
	if (!stack_a  || stack_a == 0)
		return ;
	if (stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			do_sa(stack_a);
		
	}

}

