/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:11:53 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 18:04:05 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*handle_ope;
 * Handle the operation
 * @param ope: the operation to handle
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 * @return: TRUE if the operation is handled, FALSE otherwise
 */
static t_bool	handle_ope(char *ope, t_stack **stack_a, t_stack **stack_b)
{
	if (!ope)
		return (FALSE);
	else if (ft_strncmp(ope, "pa\n", ft_strlen(ope)) == 0)
		return (do_pa(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "pb\n", ft_strlen(ope)) == 0)
		return (do_pb(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "sa\n", ft_strlen(ope)) == 0)
		return (do_sa(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "sb\n", ft_strlen(ope)) == 0)
		return (do_sb(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "ss\n", ft_strlen(ope)) == 0)
		return (do_ss(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "ra\n", ft_strlen(ope)) == 0)
		return (do_ra(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "rra\n", ft_strlen(ope)) == 0)
		return (do_rra(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "rb\n", ft_strlen(ope)) == 0)
		return (do_rb(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "rrb\n", ft_strlen(ope)) == 0)
		return (do_rrb(stack_b, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "rr\n", ft_strlen(ope)) == 0)
		return (do_rr(stack_a, stack_b, FALSE), TRUE);
	else if (ft_strncmp(ope, "rrr\n", ft_strlen(ope)) == 0)
		return (do_rrr(stack_a, stack_b, FALSE), TRUE);
	return (FALSE);
}

/*execute_operations:
 * Execute the operations
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
static void	execute_operations(t_stack **stack_a, t_stack **stack_b, t_bool pri)
{
	char	*line;

	if (pri)
		ft_print_stack(stack_a, stack_b);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!handle_ope(line, stack_a, stack_b) && line[0] != '\n')
			break ;
		free(line);
		if (pri)
			ft_print_stack(stack_a, stack_b);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_bool	print;

	print = FALSE;
	if (ac < 2)
		exit_error(NULL, NULL);
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_input(ac, av, &stack_a))
		exit_error(&stack_a, &stack_b);
	execute_operations(&stack_a, &stack_b, print);
	if (is_sorted(stack_a) && ft_stacksize(stack_b) == 0)
		ft_printf("%sOK%s\n", GREEN, DEF_COLOR);
	else
		ft_printf("%sKO%s\n", RED, DEF_COLOR);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
