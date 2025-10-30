#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	if (!stack_b)
		return ;
	temp = *stack_a;
	temp2 = *stack_b;
	*stack_b = (*stack_b)-> next;
	ft_lstadd_front(stack_a, temp2);
	(*stack_a)-> next = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	if (!stack_a)
		return ;
	temp = *stack_b;
	temp2 = *stack_a;
	*stack_a = (*stack_a)-> next;
	ft_lstadd_front(stack_b, temp2);
	(*stack_b)-> next = temp;
	write(1, "pb\n", 3);
}
