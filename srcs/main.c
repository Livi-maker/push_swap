/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:21:22 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/02 18:19:46 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**inizialize(void)
{
	t_list	**list;

	list = malloc(sizeof(t_list *));
	*list = NULL;
	return (list);
}

void	free_list(t_list **list)
{
	ft_lstclear(list, free);
	free(list);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac > 1)
	{
		stack_a = inizialize();
		if (create_stack_and_check(ac, av, stack_a) == 0 || *stack_a == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		stack_b = inizialize();
		sorting(stack_a, stack_b);
		free_list(stack_a);
		free_list(stack_b);
	}
}
