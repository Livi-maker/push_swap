/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:28:16 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/11/06 17:28:17 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_efficiency(t_rotations *moves, int move, int efficiency)
{
	moves->efficiency = efficiency;
	moves->move = move;
}

int	set_rotations(t_rotations *info, char flag)
{
	if (flag == 'a')
	{
		if (info->move == 0 || info->move == 2)
			return (info->ra);
		else
			return (info->rra);
	}
	else
	{
		if (info->move == 0 || info->move == 3)
			return (info->rb);
		else
			return (info->rrb);
	}
}

int	find_rotations(t_list *stack_a, t_list *node, int flag)
{
	int	position;
	int	len;

	len = ft_lstsize(stack_a);
	position = 0;
	while (stack_a)
	{
		if (stack_a == node)
			break ;
		position++;
		stack_a = stack_a->next;
	}
	if (flag == 1)
		return (position - len);
	return (position);
}

void	fill_info(t_rotations *info, t_list *stack_a, t_list *stack_b)
{
	info->ra = find_rotations(stack_a, info->a_el, 0);
	info->rra = find_rotations(stack_a, info->a_el, 1);
	info->rb = find_rotations(stack_b, info->b_el, 0);
	info->rrb = find_rotations(stack_b, info->b_el, 1);
}
