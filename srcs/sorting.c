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

int	find_rotations(t_list *stack_a, t_list *node)
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
		stack_a = stack_a -> next;
	}
	if (position > len / 2)
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

	n1 = ft_atoi(stack_b -> content);
	end = ft_lstlast(stack_a);
	min = findmin(stack_a);
	end->next = stack_a;
	copy = min;
	while (min->next != copy)
	{
		n2 = ft_atoi(min -> content);
		if (n1 < n2)
		{
			end -> next = NULL;
			return (min);
		}
		min = min -> next;
	}
	end -> next = NULL;
	if (n1 < ft_atoi(min -> content))
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

void	best_move(t_list **stack_a, t_list **stack_b)
{
	int		efficiency;
	int		rtsa;
	int		rtsb;
	int		rotations;
	t_list	*temp;

	efficiency = INT_MAX;
	temp = *stack_b;
	while (temp != NULL)
	{
		rotations = abs_value(find_rotations(*stack_b, temp))
			+ abs_value(find_rotations(*stack_a, best_element(*stack_a, temp)));
		if (rotations < efficiency)
		{
			rtsa = find_rotations(*stack_a, best_element(*stack_a, temp));
			rtsb = find_rotations(*stack_b, temp);
			efficiency = rotations;
		}
		temp = temp -> next;
	}
	go_for_rotation(rtsa, rtsb, stack_a, stack_b);
}

void	push_all_in_b(t_list **stack_a, t_list **stack_b)
{
	while (is_sorted(*stack_a) != 1 && ft_lstsize(*stack_a) > 3)
	{
		if (*stack_a == findmin(*stack_a))
			go_for_rotation(1, 0, stack_a, stack_b);
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
