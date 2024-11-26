# include "push_swap.h"

static int	handle_ope(char *ope, t_stack **a_check, t_stack **b_check)
{
	if (!ope)
		return (0);
	if (ft_strncmp(ope, "pa\n", ft_strlen(ope)) == 0)
		do_pa(a_check, b_check);
	if (ft_strncmp(ope, "pb\n", ft_strlen(ope)) == 0)
		do_pb(a_check, b_check);
	if (ft_strncmp(ope, "sa\n", ft_strlen(ope)) == 0)
		do_sa(a_check);
	if (ft_strncmp(ope, "sb\n", ft_strlen(ope)) == 0)
		do_sb(b_check);
	if (ft_strncmp(ope, "ra\n", ft_strlen(ope)) == 0)
		do_ra(a_check);
	if (ft_strncmp(ope, "rra\n", ft_strlen(ope)) == 0)
		do_rra(a_check);
	if (ft_strncmp(ope, "rb\n", ft_strlen(ope)) == 0)
		do_rb(b_check);
	if (ft_strncmp(ope, "rrb\n", ft_strlen(ope)) == 0)
		do_rrb(b_check);
	if (ft_strncmp(ope, "rr\n", ft_strlen(ope)) == 0)
		do_rr(a_check, b_check);
	if (ft_strncmp(ope, "rrr\n", ft_strlen(ope)) == 0)
		do_rrr(a_check, b_check);
	return (1);
}

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
