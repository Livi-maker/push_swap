/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:44:02 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/02 18:31:59 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*stack_a) <= 2)
		return ;
	temp2 = *stack_a;
	temp = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)-> next;
	temp -> next = temp2;
	temp2 -> next = NULL;
}

void	rb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*stack_b) <= 2)
		return ;
	temp2 = *stack_b;
	temp = ft_lstlast(*stack_b);
	*stack_b = (*stack_b)-> next;
	temp -> next = temp2;
	temp2 -> next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
