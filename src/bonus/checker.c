# include "push_swap.h"

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
	if (ft_strncmp(ope, "pa\n", ft_strlen(ope)) == 0)
		do_pa(stack_a, stack_b);
	if (ft_strncmp(ope, "pb\n", ft_strlen(ope)) == 0)
		do_pb(stack_a, stack_b);
	if (ft_strncmp(ope, "sa\n", ft_strlen(ope)) == 0)
		do_sa(*stack_a);
	if (ft_strncmp(ope, "sb\n", ft_strlen(ope)) == 0)
		do_sb(*stack_b);
	if (ft_strncmp(ope, "ss\n", ft_strlen(ope)) == 0)
		do_ss(*stack_a, *stack_b);
	if (ft_strncmp(ope, "ra\n", ft_strlen(ope)) == 0)
		do_ra(stack_a);
	if (ft_strncmp(ope, "rra\n", ft_strlen(ope)) == 0)
		do_rra(stack_a);
	if (ft_strncmp(ope, "rb\n", ft_strlen(ope)) == 0)
		do_rb(stack_b);
	if (ft_strncmp(ope, "rrb\n", ft_strlen(ope)) == 0)
		do_rrb(stack_b);
	if (ft_strncmp(ope, "rr\n", ft_strlen(ope)) == 0)
		do_rr(stack_a, stack_b);
	if (ft_strncmp(ope, "rrr\n", ft_strlen(ope)) == 0)
		do_rrr(stack_a, stack_b);
	return (TRUE);
}

/*execute_operations:
 * Execute the operations
 * @param stack_a: the stack a
 * @param stack_b: the stack b
 */
static void	execute_operations(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		is_running;

	line = NULL;
	is_running = 1;
	while (is_running)
	{
		ft_print_stack(stack_a, stack_b);
		line = get_next_line(0);
		if (!line)
			break ;
		is_running = handle_ope(line, stack_a, stack_a);
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		exit_error(NULL, NULL);
	stack_a = NULL;
	stack_b = NULL;
	if (!parse_input(ac, av, &stack_a))
		exit_error(&stack_a, &stack_b);
	execute_operations(&stack_a, &stack_b);
	if (is_sorted(stack_a) && ft_stacksize(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
