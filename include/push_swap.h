/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:36:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/18 17:39:14 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

typedef struct s_stack
{
	int			*nb;
	struct s_stack	*next;
}		t_stack;

// swap.c
void	do_sa(t_list *stack_a);
void	do_sb(t_list *stack_b);
void	do_ss(t_list *stack_a, t_list *stack_b);

// push.c
void	do_pa(t_list **stack_a, t_list **stack_b);
void	do_pb(t_list **stack_a, t_list **stack_b);

// rotate.c
int	do_ra(t_list **stack_a);
int	do_rb(t_list **stack_b);
int	do_rr(t_list **stack_a, t_list **stack_b);

// reverse_rotate.c
int	do_rra(t_list **stack_a);
int	do_rrb(t_list **stack_b);
int	do_rrr(t_list **stack_a, t_list **stack_b);

// push_swap.c
void	push_swap(t_list **stack_a, t_list **stack_b);
void	smolr_sort(t_list **stack);
void	big_sort(t_list *stack_a, t_list *stack_b);
void	sxe_sort(t_list **stack_a, t_list **stack_b, int len);
int		is_sorted(t_list *stack);
#endif