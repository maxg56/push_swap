/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:24:22 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/22 12:04:25 by mgendrot         ###   ########.fr       */
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

int	parse_input(int ac, char **av, t_stack **stack_a)
{
	int		i;
	int		nb;
	t_stack	*new_node;
	t_bool	f;

	i = 1;
	f = FALSE;
	if (ac == 2)
	{
		f = TRUE;
		av = ft_split(av[1], ' ');
	}
	while (av[i])
	{
		if (isvala(av[i]) || !ismax_min(av[i]) || !notrp(av))
			return (0);
		nb = ft_atoi(av[i]);
		new_node = ft_stacknew(nb);
		if (!new_node)
			return (0);
		(ft_stackadd(stack_a, new_node), i++);
	}
	if (f)
		free_arr(av);
	return (1);
}
