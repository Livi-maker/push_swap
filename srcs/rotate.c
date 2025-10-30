/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:44:02 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/02 18:30:47 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_list **stack, char *to_print, int *n)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*stack) <= 1)
		return ;
	temp2 = *stack;
	temp = ft_lstlast(*stack);
	*stack = (*stack)->next;
	temp->next = temp2;
	temp2->next = NULL;
	write(1, to_print, ft_strlen(to_print));
	if (n != NULL)
		*n = *n - 1;
}

void	rr(t_list **stack_a, t_list **stack_b, int *rtsa, int *rtsb)
{
	r(stack_a, "rr\n", rtsa);
	r(stack_b, "", rtsb);
}
