#include "push_swap.h"

t_list	*findmin(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (stack->next)
	{
		if (stack->number > (stack->next)->number)
			temp = stack->next;
		stack = stack->next;
	}
	return (temp);
}

int	is_sorted(t_list *stack)
{
	t_list	*min;
	t_list	*start;
	t_list	*end;

	min = findmin(stack);
	start = min;
	end = ft_lstlast(stack);
	end->next = stack;
	while (min->next != start)
	{
		if (min->number > (min->next)->number)
		{
			end->next = NULL;
			return (0);
		}
		min = min->next;
	}
	end->next = NULL;
	return (1);
}

int	is_right_order(t_list *stack)
{
	while (stack->next)
	{
		if (stack->number > (stack->next)->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
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