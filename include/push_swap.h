/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:36:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/21 13:50:29 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>

# define RED "\033[0;91m"
# define DEF_COLOR "\033[0;39m"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// sort.c
void	sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void	shift_stack(t_stack **stack_a);

// position.c
void	get_position(t_stack **stack);
int		get_lowest_index_position(t_stack **stack);
int		get_target(t_stack **a, int b_idx, int target_idx, int target_pos);

void	tiny_sort(t_stack **stack);
int 	is_sorted(t_stack *stack);
// instructions

void	do_sa(t_stack *stack_a);
void	do_sb(t_stack *stack_b);
void	do_ss(t_stack *stack_a, t_stack *stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
int		do_ra(t_stack **stack_a);
int		do_rb(t_stack **stack_b);
int		do_rr(t_stack **stack_a, t_stack **stack_b);
int		do_rra(t_stack **stack_a);
int		do_rrb(t_stack **stack_b);
int		do_rrr(t_stack **stack_a, t_stack **stack_b);

// utils_stack.c
int		ft_stacksize(t_stack *stack);
void	ft_stackadd(t_stack **lst, t_stack *new);
void	ft_stackdelone(t_stack *lst);
void	ft_stackclear(t_stack **lst);
t_stack	*ft_stacknew(int nb);
// utils.c
void	ft_prnit_stack(t_stack **stack_a, t_stack **stack_b);
int		exit_error(t_stack **stack_a, t_stack **stack_b);

// parschque.c
int		parse(char **argv, t_stack **stack_a);

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b);


#endif