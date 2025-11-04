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