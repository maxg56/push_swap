/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:36:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 17:59:18 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>

# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define DEF_COLOR "\033[0;39m"

typedef int	t_bool;

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

void	tiny_sort(t_stack **stack);
void	sort_stacks_5(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);

// parse.c

t_bool	parse_input(int ac, char **av, t_stack **stack_a);

//get

t_stack	*get_biggest(t_stack *stake);
t_stack	*get_smallest(t_stack *stack);
t_stack	*get_smaller(t_stack *stack, int target);
t_stack	*get_bigger(t_stack *stack, int target);

//cost

int		get_move_cost(t_stack *stack_a, t_stack *source,
			t_stack *stack_b, t_stack *target);
t_bool	get_rotation_way(t_stack *target, t_stack *stack);

//check

t_bool	is_sorted(t_stack *stack);
t_bool	is_mini(int n, t_stack *stack_b);
t_bool	is_maxi(int n, t_stack *stack_b);

// utils.c

void	ft_print_stack(t_stack **stack_a, t_stack **stack_b);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
char	**free_arr(char **split);
int		ft_stackindex(t_stack *stack, t_stack *ptr);
int		ft_stacksize(t_stack *stack);
void	ft_stackadd(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);
t_stack	*ft_stacknew(int nb);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
t_bool	is_stack_valid(t_stack **stack);

// instructions

void	do_sa(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_sb(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_ss(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_pa(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_pb(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_ra(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_rb(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_rr(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_rra(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_rrb(t_stack **stack_a, t_stack **stack_b, t_bool print);
void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_bool print);

#endif