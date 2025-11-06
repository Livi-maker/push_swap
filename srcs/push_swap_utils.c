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

#include "push_swap.h"

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

void	print_stack(t_list *stack)
{
	int	number;

	printf("stack\n");
	while (stack)
	{
		number = stack->number;
		printf("%d\n", number);
		stack = stack->next;
	}
	printf("end\n");
}

int	abs_value(int number)
{
	if (number < 0)
		return (-number);
	return (number);
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
}
