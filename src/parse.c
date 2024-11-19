/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:24:22 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/19 22:12:48 by maxence          ###   ########.fr       */
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


static int	notrp(char **str)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse(char **argv, t_stack **stack_a)
{
	int	i;
	int	nb;
	t_stack	*new_node;

	i = 1;
	while (argv[i])
	{
		if (isvala(argv[i]) || !ismax_min(argv[i]) || !notrp(argv))
			return (0);
		nb = ft_atoi(argv[i]);
		new_node = ft_stacknew(nb);
		if (!new_node)
			return (0); 
		ft_stackadd(stack_a, new_node);
		i++;
	}
	return (1);
}
