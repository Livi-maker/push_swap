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

void	check_efficiency(t_rotations *moves)
{
	int	both_r;
	int	both_rr;
	int	r_rr;
	int	rr_r;

	both_r = max(abs_value(moves->ra), abs_value(moves->rb));
	both_rr = max(abs_value(moves->rra), abs_value(moves->rrb));
	r_rr = abs_value(moves->ra) + abs_value(moves->rrb);
	rr_r = abs_value(moves->rra) + abs_value(moves->rb);
	if (both_r < both_rr && both_r < r_rr && both_r < rr_r)
		set_efficiency(moves, 0, both_r);
	else if (both_rr < r_rr && both_rr < rr_r)
		set_efficiency(moves, 1, both_rr);
	else if (r_rr < rr_r)
		set_efficiency(moves, 2, r_rr);
	else
		set_efficiency(moves, 3, rr_r);
}

t_list	*best_element(t_list *stack_a, t_list *stack_b)
{
	int		n1;
	int		n2;
	t_list	*end;
	t_list	*min;
	t_list	*copy;

	n1 = stack_b->number;
	end = ft_lstlast(stack_a);
	min = findmin(stack_a);
	end->next = stack_a;
	copy = min;
	while (min->next != copy)
	{
		n2 = min->number;
		if (n1 < n2)
		{
			end -> next = NULL;
			return (min);
		}
		min = min -> next;
	}
	end -> next = NULL;
	if (n1 < min->number)
		return (min);
	return (min -> next);
}

void	best_move(t_list **stack_a, t_list **stack_b)
{
	t_rotations	info;
	int			rtsa;
	int			rtsb;
	int			efficiency;
	t_list		*temp;

	temp = *stack_b;
	efficiency = INT_MAX;
	while (temp != NULL)
	{
		info.b_el = temp;
		info.a_el = best_element(*stack_a, temp);
		fill_info(&info, *stack_a, *stack_b);
		check_efficiency(&info);
		if (info.efficiency < efficiency)
		{
			rtsa = set_rotations(&info, 'a');
			rtsb = set_rotations(&info, 'b');
			efficiency = info.efficiency;
		}
		temp = temp->next;
	}
	go_for_rotation(rtsa, rtsb, stack_a, stack_b);
}
