/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:11:25 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/01 15:44:45 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check(char *str)
{
	long long	number;
	int			i;
	int			sign;

	number = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		sign *= -1;
	}
	if (!str[i])
		return (0);
	while (str[i++])
	{
		if (str[i - 1] < '0' || str[i - 1] > '9')
			return (0);
		number = (number * 10) + (str[i - 1] - '0');
		if ((number * sign) > 2147483647 || (number * sign) < -2147483648)
			return (0);
	}
	return (1);
}

int	check_dup(char *line, t_list *stack_a)
{
	while ((stack_a -> content) != line)
	{
		if (ft_atoi(line) == ft_atoi(stack_a -> content))
			return (0);
		stack_a = stack_a -> next;
	}
	return (1);
}

int	correct_input(char **matrix, t_list *stack_a)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (check(matrix[i]) == 0 || check_dup(matrix[i], stack_a) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	splitting(char *str, t_list **stack_a)
{
	char	**matrix;
	int		i;
	t_list	*node;

	matrix = ft_split(str, ' ');
	i = 0;
	if (!matrix[i])
	{
		free(matrix);
		return (0);
	}
	while (matrix[i] != NULL)
	{
		node = ft_lstnew(matrix[i]);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	if (correct_input(matrix, *stack_a) == 0)
	{
		ft_lstclear(stack_a, free);
		return (free(matrix), 0);
	}
	return (free(matrix), 1);
}

int	parsing_input(int ac, char **av, t_list **stack_a)
{
	int		n;

	n = 1;
	*stack_a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		while (ac > 1)
		{
			if (splitting(av[n], stack_a) == 0)
				return (0);
			ac--;
			n++;
		}
	}
	return (1);
}
