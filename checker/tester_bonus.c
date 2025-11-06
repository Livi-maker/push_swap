/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:21:22 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/01 18:45:38 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_moves(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
}

int	is_correct(char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "sb\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "pa\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "pb\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "ss\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "ra\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "rb\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "rr\n", 3) == 0)
		return (1);
	if (ft_strncmp(move, "rra\n", 4) == 0)
		return (1);
	if (ft_strncmp(move, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(move, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

int	order_stack(t_list **stack_a)
{
	char	*move;
	t_list	**stack_b;

	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		if (is_correct(move) == 0)
			return (free (move), 0);
		do_moves(stack_a, stack_b, move);
		free (move);
	}
	ft_lstclear(stack_b, free);
	free(stack_b);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;

	stack_a = malloc(sizeof(t_list *));
	if (parsing_input(ac, av, stack_a) == 0 || order_stack(stack_a) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(stack_a);
		return (0);
	}
	if (is_right_order(*stack_a) == 0)
		ft_putstr_fd("KO", 1);
	else
		ft_putstr_fd("OK", 1);
	ft_lstclear(stack_a, free);
	free(stack_a);
}
