/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:24:22 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/19 16:41:34 by mgendrot         ###   ########.fr       */
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
	return (nb >= -2147483648 && nb <= 2147483647);
}


static int	notrp(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(&str[i]) == ft_atoi(&str[j]))
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
		if (isvala(argv[i]) || !ismax_min(argv[i]) || notrp(argv, i))
			return (1);
		nb = ft_atoi(argv[i]);
		new_node = ft_stacknew(nb);
		if (!new_node)
			return (1); // Gestion d'erreur
		ft_stackadd(stack_a, new_node);
		i++;
	}
	return (0);
}

