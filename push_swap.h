/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:36:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/14 16:53:05 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

// swap.c
void	swap(t_list *stack);
void	do_sa(t_list *stack_a);
void	do_sb(t_list *stack_b);
void	do_ss(t_list *stack_a, t_list *stack_b);

// push.c
void	push(t_list *stack_a, t_list *stack_b);
void	do_pa(t_list *stack_a, t_list *stack_b);
void	do_pb(t_list *stack_a, t_list *stack_b);

// rotate.c
void	rotate(t_list *stack);
void	do_ra(t_list *stack_a);
void	do_rb(t_list *stack_b);
void	do_rr(t_list *stack_a, t_list *stack_b);

// reverse_rotate.c
void	reverse_rotate(t_list *stack);
void	do_rra(t_list *stack_a);
void	do_rrb(t_list *stack_b);
void	do_rrr(t_list *stack_a, t_list *stack_b);

// push_swap.c
void	push_swap(t_list *stack_a, t_list *stack_b);

#endif