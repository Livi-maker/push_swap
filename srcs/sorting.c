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
	{
		moves->efficiency = both_r;
		moves->move = 0;
	}
	else if (both_rr < r_rr && both_rr < rr_r)
	{
		moves->efficiency = both_rr;
		moves->move = 1;
	}
	else if (r_rr < rr_r)
	{
		moves->efficiency = r_rr;
		moves->move = 2;
	}
	else
	{
		moves->efficiency = rr_r;
		moves->move = 3;
	}
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

void	go_for_rotation(int rtsa, int rtsb, t_list **stack_a, t_list **stack_b)
{
	while (rtsa < 0 && rtsb < 0)
		rrr(stack_a, stack_b, &rtsa, &rtsb);
	while (rtsa < 0)
		reverse_rotate(stack_a, "rra\n", &rtsa);
	while (rtsb < 0)
		reverse_rotate(stack_b, "rrb\n", &rtsb);
	while (rtsa > 0 && rtsb > 0)
		rr(stack_a, stack_b, &rtsa, &rtsb);
	while (rtsa > 0)
		r(stack_a, "ra\n", &rtsa);
	while (rtsb > 0)
		r(stack_b, "rb\n", &rtsb);
}

void	fill_info(t_rotations *info, t_list *stack_a, t_list *stack_b)
{
	info->ra = find_rotations(stack_a, info->a_el, 0);
	info->rra = find_rotations(stack_a, info->a_el, 1);
	info->rb = find_rotations(stack_b, info->b_el, 0);
	info->rrb = find_rotations(stack_b, info->b_el, 1);
}

void	best_move(t_list **stack_a, t_list **stack_b)
{
	t_rotations	info;
	int		rtsa;
	int		rtsb;
	int		efficiency;
	t_list	*temp;

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

void	push_all_in_b(t_list **stack_a, t_list **stack_b)
{
	// int	len;

	// len = ft_lstsize(*stack_a);
	// if (len < 200)
	// {
	// 	while (is_sorted(*stack_a) != 1 && ft_lstsize(*stack_a) > 3)
	// 	{
	// 		if (*stack_a == findmin(*stack_a))
	// 			go_for_rotation(1, 0, stack_a, stack_b);
	// 		pb(stack_a, stack_b);
	// 	}
	// 	return ;
	//}
	while (is_sorted(*stack_a) != 1 && ft_lstsize(*stack_a) > 3)
	{

		if ((*stack_a)->number > ((*stack_a)->next)->number)
		{
			go_for_rotation(1, 0, stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		else
			pb(stack_a, stack_b);
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
