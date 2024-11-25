/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:36:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/25 18:10:14 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>

# define RED "\033[0;91m"
# define DEF_COLOR "\033[0;39m"

typedef int t_bool;

# define TRUE 1
# define FALSE 0
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_move
{
	t_stack	*source;
	t_stack	*target;
	int		cost;
}	t_move;

// sort.c
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void	shift_stack(t_stack **stack_a);

// position.c
int	parse_input(int ac, char **av, t_stack **stack_a);
char	**free_arr(char **split);

void	tiny_sort(t_stack **stack);
int 	is_sorted(t_stack *stack);

//get
t_stack	*get_biggest(t_stack *stake);
t_stack	*get_smallest(t_stack *stack);
t_stack	*get_smaller(t_stack *stack, int target);
t_stack	*get_bigger(t_stack *stack, int target);
int	get_is_minimum(int n, t_stack *stack_b);
int	get_is_maximum(int n, t_stack *stack_b);
//cost
int	ft_lstindex(t_stack *stack, t_stack *ptr);
int	get_rotation_way(t_stack *target, t_stack *stack);
int	get_move_cost(t_stack *stack_a, t_stack *source, t_stack *stack_b, t_stack *target);
int	get_rotation_cost(t_stack *target, t_stack *stack);
int	get_reverse_rotation_cost(t_stack *target, t_stack *stack);
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
void	ft_print_stack(t_stack **stack_a, t_stack **stack_b);
void	exit_error(t_stack **stack_a, t_stack **stack_b);

// parschque.c

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b);


#endif