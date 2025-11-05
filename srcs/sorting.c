/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:23:40 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/01 13:43:21 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sorting(t_list **stack_a)
{
	t_list	*min;
	int		rotations1;
	int		rotations2;

	min = findmin(*stack_a);
	rotations1 = find_rotations(*stack_a, min, 0);
	rotations2 = find_rotations(*stack_a, min, 1);
	if (abs_value(rotations2) < abs_value(rotations1))
		go_for_rotation(rotations2, 0, stack_a, NULL);
	else
		go_for_rotation(rotations1, 0, stack_a, NULL);
}

void	push_all_in_b(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len < 200)
	{
		while (is_sorted(*stack_a) != 1 && len > 3)
		{
			pb(stack_a, stack_b);
			len--;
		}
		return ;
	}
	while (is_sorted(*stack_a) != 1 && len > 3)
	{
		if ((*stack_a)->number > ((*stack_a)->next)->number)
			go_for_rotation(1, 0, stack_a, stack_b);
		pb(stack_a, stack_b);
		len--;
	}
}

void	push_back_in_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) > 0)
	{
		best_move(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_a))
		return ;
	push_all_in_b(stack_a, stack_b);
	order_three(stack_a);
	push_back_in_a(stack_a, stack_b);
	final_sorting(stack_a);
}
