/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:54:15 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/01 13:54:18 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list **stack, char *to_print)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*stack) <= 1)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp2 = (*stack)->next;
	(*stack)->next = temp;
	temp->next = temp2;
	write(1, to_print, ft_strlen(to_print));
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	s(stack_a, "ss\n");
	s(stack_b, "");
}
