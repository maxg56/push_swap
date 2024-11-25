/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:24:22 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/25 15:44:52 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isvala(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	return (str[i] != '\0');
}

static int	ismax_min(char *str)
{
	long	nb;

	nb = ft_atol(str);
	return (nb >= INT_MIN && nb <= INT_MAX);
}

static t_bool	notrp(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_bool	parse(int i, char **av, t_stack **stack_a)
{
	int		nb;
	t_stack	*new_node;

	while (av[i])
	{
		if (isvala(av[i]) || !ismax_min(av[i]) || !notrp(av))
			return (FALSE);
		nb = ft_atoi(av[i]);
		new_node = ft_stacknew(nb);
		if (!new_node)
			return (FALSE);
		ft_stackadd(stack_a, new_node);
		i++;
	}
	return (TRUE);
}

int	parse_input(int ac, char **av, t_stack **stack_a)
{
	int	i;
	char	**age;
	t_bool	fre;
	t_bool	var;

	i = 1;
	fre = FALSE;
	if (ac == 2)
	{
		i = 0;
		fre = TRUE;
		age = ft_split(av[1], ' ');
	}
	else
		age = av;
	var = parse(i, age, stack_a);
	if (fre)
		free_arr(age);
	return (var);
}
