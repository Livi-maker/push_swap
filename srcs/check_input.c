/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:11:25 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/02 18:18:47 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *str)
{
	long long	number;
	int			sign;

	number = 0;
	sign = 1;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		number = (number * 10) + (*str - '0');
		if ((number * sign) > 2147483647 || (number * sign) < -2147483648)
			return (0);
		str++;
	}
	return (1);
}

static int	check_duplicate(char *line, t_list *stack_a)
{
	while (stack_a)
	{
		if (ft_atoi(line) == stack_a->number)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static void	add_to_stack(char *input, t_list **stack_a)
{
	t_list	*node;

	node = ft_lstnew(input);
	ft_lstadd_back(stack_a, node);
}

int	create_stack_and_check(int ac, char **av, t_list **stack_a)
{
	int		n;
	int		i;
	char	**input;

	n = 1;
	while (n < ac)
	{
		input = ft_split(av[n], ' ');
		i = 0;
		while (input && input[i])
		{
			if (!is_int(input[i]) || !check_duplicate(input[i], *stack_a))
			{
				free_list(stack_a);
				return (free(input[i]), free(input), 0);
			}
			else
				add_to_stack(input[i], stack_a);
			i++;
		}
		free(input);
		n++;
	}
	return (1);
}
