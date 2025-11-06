/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:01:47 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/11/05 17:01:50 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three(t_list **stack)
{
	int	n1;
	int	n2;

	if (is_sorted(*stack))
		return ;
	while (!is_right_order(*stack))
	{
		n1 = (*stack)->number;
		n2 = ((*stack)->next)->number;
		if (is_sorted(*stack) == 1 && n1 > n2)
			r(stack, "ra\n", NULL);
		else if (n1 > n2)
			s(stack, "sa\n");
		else
			reverse_rotate(stack, "rra\n", NULL);
	}
}
