/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:56:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/28 12:57:31 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*nuw_move(int cost, t_stack *source, t_stack *target, t_move *move)
{
	move = malloc(sizeof(t_move));
	move->cost = cost;
	move->target = target;
	move->source = source;
	return (move);
}

t_move	*update_move(int cost, t_stack *source, t_stack *target, t_move *move)
{
	move->cost = cost;
	move->target = target;
	move->source = source;
	return (move);
}
