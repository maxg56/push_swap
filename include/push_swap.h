/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:36:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/19 21:53:23 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int			nb;
	struct s_stack	*next;
}		t_stack;

// swap.c
void	do_sa(t_stack *stack_a);
void	do_sb(t_stack *stack_b);
void	do_ss(t_stack *stack_a, t_stack *stack_b);

// push.c
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

// rotate.c
int	do_ra(t_stack **stack_a);
int	do_rb(t_stack **stack_b);
int	do_rr(t_stack **stack_a, t_stack **stack_b);

// reverse_rotate.c
int	do_rra(t_stack **stack_a);
int	do_rrb(t_stack **stack_b);
int	do_rrr(t_stack **stack_a, t_stack **stack_b);

// push_swap.c
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	smoll_sort(t_stack **stack);
void	big_sort(t_stack *stack_a, t_stack *stack_b);
void	sxe_sort(t_stack **stack_a, t_stack **stack_b, int len);
int		is_sorted(t_stack *stack);

// utils.c

int		ft_stacksize(t_stack *stack);
void	ft_stackadd(t_stack **lst, t_stack *new);
void	ft_stackdelone(t_stack *lst);
void	ft_stackclear(t_stack **lst);
t_stack	*ft_stacknew(int nb);
// parschque.c
int		parse(char **argv, t_stack **stack_a);

#endif