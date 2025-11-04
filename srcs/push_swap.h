/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:58:56 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/01 13:58:59 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_rotations
{
	int efficiency;
	int move;
	t_list *a_el;
	t_list *b_el;
	int	ra;
	int rb;
	int rra;
	int rrb;
}	t_rotations;

int		create_stack_and_check(int ac, char **av, t_list **stack_a);
void	sorting(t_list **stack_a, t_list **stack_b);
t_list	*findmin(t_list *stack);
int		is_sorted(t_list *stack);
void	free_list(t_list **list);
int		max(int n1, int n2);

void	print_stack(t_list	*stack);
void	s(t_list **stack_a, char *to_print);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	r(t_list **stack, char *to_print, int *n);
void	rr(t_list **stack_a, t_list **stack_b, int *rtsa, int *rtsb);
void	reverse_rotate(t_list **stack_a, char *to_print, int *n);
void	rrr(t_list **stack_a, t_list **stack_b, int *rtsa, int *rtsb);
int		is_right_order(t_list *stack_a);
void	start_sorting(t_list **stack_a, t_list **stack_b);
int		abs_value(int number);
void	go_for_rotation(int rtsa, int rtsb, t_list **stack_a, t_list **stack_b);
t_list	*best_element(t_list *stack_a, t_list *stack_b);
int		find_rotations(t_list *stack_a, t_list *node, int flag);
void	insert_A(t_list **stack_a, t_list **stack_b);
int		one_input(char *str);
int		check(char *str);

void	free_array(char **array);
void	order_three(t_list **stack);
void	final_sorting(t_list **stack_a);
int		lenghtordered(t_list *stack);
t_list	*longest(t_list *stack);

#endif
