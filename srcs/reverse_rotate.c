/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:38:45 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/02 18:30:24 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack_a, char *to_print, int *n)
{
	t_list	*temp;

	temp = *stack_a;
	if (ft_lstsize(*stack_a) < 2)
		return ;
	*stack_a = ft_lstlast(*stack_a);
	(*stack_a)->next = temp;
	while (temp->next != *stack_a)
		temp = temp->next;
	temp->next = NULL;
	write(1, to_print, ft_strlen(to_print));
	if (n != NULL)
		*n = *n + 1;
}

void	rrr(t_list **stack_a, t_list **stack_b, int *rtsa, int *rtsb)
{
	reverse_rotate(stack_a, "rrr\n", rtsa);
	reverse_rotate(stack_b, "", rtsb);
}
