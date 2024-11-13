/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:36:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/13 13:25:25 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

typedef struct s_pslst
{
	int				nb;
	struct s_pslst	*next;
}					t_pslst;

// swap.c
void	swap(t_pslst *stack);
void	do_sa(t_pslst *stack_a);
void	do_sb(t_pslst *stack_b);
void	do_ss(t_pslst *stack_a, t_pslst *stack_b);

// push.c
void	push(t_pslst *stack_a, t_pslst *stack_b);
void	do_pa(t_pslst *stack_a, t_pslst *stack_b);
void	do_pb(t_pslst *stack_a, t_pslst *stack_b);

// rotate.c
void	rotate(t_pslst *stack);
void	do_ra(t_pslst *stack_a);
void	do_rb(t_pslst *stack_b);
void	do_rr(t_pslst *stack_a, t_pslst *stack_b);

// reverse_rotate.c
void	reverse_rotate(t_pslst *stack);
void	do_rra(t_pslst *stack_a);
void	do_rrb(t_pslst *stack_b);
void	do_rrr(t_pslst *stack_a, t_pslst *stack_b);

// push_swap.c
void	push_swap(t_pslst *stack_a, t_pslst *stack_b);

#endif