/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:12:07 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/01 13:53:52 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	create_stack(t_list **stack_a, int ac, char **av)
{
	t_list		*node;
	int			n;

	n = 1;
	*stack_a = NULL;
	while (n < ac)
	{
		node = ft_lstnew(av[n]);
		ft_lstadd_back(stack_a, node);
		n++;
	}
}

void	free_array(char **array)
{
	int	n;

	n = 0;
	while (array[n] != NULL)
	{
		free(array[n]);
		n++;
	}
	free(array);
}

int	is_right_order(t_list *stack)
{
	int	n1;
	int	n2;

	while (stack -> next != NULL)
	{
		n1 = ft_atoi(stack-> content);
		n2 = ft_atoi((stack-> next)-> content);
		if (n1 > n2)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
