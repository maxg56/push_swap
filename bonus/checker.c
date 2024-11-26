# include "push_swap.h"

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
	ft_print_stack(&stack_a, &stack_b);
	ft_print_stack(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
