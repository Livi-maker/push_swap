/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:30:00 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/01/30 20:34:59 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sorting(t_list **stack_a)
{
	t_list	*min;
	int		rotations;

	min = findmin(*stack_a);
	rotations = find_rotations(*stack_a, min);
	go_for_rotation(rotations, 0, stack_a, NULL);
}

int	lenghtordered(t_list *stack)
{
	int	lenght;

	lenght = 0;
	while (stack -> next)
	{
		if (stack -> number > (stack -> next)-> number)
			break ;
		lenght++;
		stack = stack -> next;
	}
	return (lenght);
}

t_list	*longest(t_list *stack)
{
	int		lenght;
	t_list	*start;

	lenght = 0;
	while (stack)
	{
		if (lenghtordered(stack) > lenght)
		{
			lenght = lenghtordered(stack);
			start = stack;
		}
		stack = stack -> next;
	}
	return (start);
}
