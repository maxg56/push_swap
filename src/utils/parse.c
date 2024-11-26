/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:24:22 by mgendrot          #+#    #+#             */
/*   Updated: 2024/11/26 15:22:04 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*isvala :
*	Checks if the string is a valid number
*	- Returns TRUE if the string is a valid number
*	- Returns FALSE if the string is not a valid number
*/
static t_bool	isvala(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (FALSE);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (FALSE);
	return (TRUE);
}

/*ismax_min :
*	Checks if the number is between INT_MIN and INT_MAX
*	- Returns TRUE if the number is between INT_MIN and INT_MAX
*	- Returns FALSE if the number is not between INT_MIN and INT_MAX
*/
static t_bool	ismax_min(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < INT_MIN || nb > INT_MAX)
		return (FALSE);
	return (TRUE);
}

/*notrp :
*	Checks if there are no repeated numbers in the stack
*	- Returns TRUE if there are no repeated numbers
*	- Returns FALSE if there are repeated numbers
*/
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

/*parse :
*	Parses the input and creates a stack
*	- Returns TRUE if the input is valid
*	- Returns FALSE if the input is not valid
*/
static t_bool	parse(int i, char **av, t_stack **stack_a)
{
	int		nb;
	t_stack	*new_node;

	while (av[i])
	{
		if (!isvala(av[i]) || !ismax_min(av[i]) || !notrp(av))
			return (FALSE);
		nb = ft_atoi(av[i]);
		new_node = ft_stacknew(nb);
		if (!new_node)
			return (FALSE);
		ft_stackadd_back(stack_a, new_node);
		i++;
	}
	return (TRUE);
}

/*parse_input :
*	Parses the input and creates a stack
*	- Returns TRUE if the input is valid
*	- Returns FALSE if the input is not valid
*/
t_bool	parse_input(int ac, char **av, t_stack **stack_a)
{
	int		i;
	char	**age;
	t_bool	free;
	t_bool	var;

	i = 1;
	free = FALSE;
	if (ac == 2)
	{
		i = 0;
		free = TRUE;
		age = ft_split(av[1], ' ');
	}
	else
		age = av;
	var = parse(i, age, stack_a);
	if (free)
		free_arr(age);
	return (var);
}
