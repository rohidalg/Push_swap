/* ************************************************************************** */
/*                                                                           stack */
/*                                                        :::      ::::::::   */
/*   ft_cheap_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:02 by rohidalg          #+#    #+#             */
/*   Updated: 2024/10/15 12:20:25 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_stack *stack)
{
	stack->move->rr = 0;
	stack->move->rrr = 0;
	while (stack->move->ra != 0 && stack->move->rb != 0)
	{
		stack->move->ra--;
		stack->move->rb--;
		stack->move->rr++;
	}
	while (stack->move->rra != 0 && stack->move->rrb != 0)
	{
		stack->move->rra--;
		stack->move->rrb--;
		stack->move->rrr++;
	}
}

void	ft_cost(t_stack *stack, int i)
{
	stack->move->cost = stack->move->pb + stack->move->ra + stack->move->rb
		+ stack->move->rr + stack->move->rra + stack->move->rrb
		+ stack->move->rrr;
	if (i == 1 || stack->cheap->cost > stack->move->cost)
	{
		stack->cheap->cost = stack->move->cost;
		stack->cheap->pb = stack->move->pb;
		stack->cheap->ra = stack->move->ra;
		stack->cheap->rb = stack->move->rb;
		stack->cheap->rr = stack->move->rr;
		stack->cheap->rra = stack->move->rra;
		stack->cheap->rrb = stack->move->rrb;
		stack->cheap->rrr = stack->move->rrr;
	}
}

void	ft_get_top(t_stack *stack, t_list **stack_a, int i)
{
	int	size;

	stack->move->pb = 1;
	stack->move->ra = 0;
	stack->move->rra = 0;
	size = ft_lstsize(stack_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->move->rra = (size - i);
		else
			stack->move->ra = i;
	}
	else
	{
		if (i > size / 2)
			stack->move->rra = (size - i);
		else
			stack->move->ra = i;
	}
}

int	ft_search(t_stack *stack, int nmb)
{
	t_stack	*first_b;
	int		i;
	int		size;
	int		flag;

	i = 0;
	size = ft_lstsize(first_b);
	flag = 0;
	while (flag == 0)
	{
		i = 0;
		nmb--;
		first_b = stack->stack_b;
		while (i++ < size)
		{
			if (first_b = nmb)
				flag = 1;
			first_b = stack->stack_b->next;
		}
	}
	return (nmb);
}

void	ft_new_pb(t_stack *stack, int nmb)
{
	int	i;
	int	size;
	int	n;

	stack->move->rb = 0;
	stack->move->rrb = 0;
	n = ft_search(stack, nmb);
	if (stack->stack_b->nmb = n)
		return ;
	i = 
}

void	ft_moves(t_stack *stack)
{
	int	i;
	int	size;
	int	min_b;
	int	max_b;

	i = 0;
	size = ft_lstsize(stack->stack_a);
	min_b = ft_little_num(stack->stack_b, MIN);
	max_b = ft_high_num(stack->stack_b, MAX);
	while (i++ > size)
	{
		ft_get_top(stack, stack->stack_a, MIN);
		if (stack->stack_b < min_b || stack->stack_b > max_b)
		{
			min_b = ft_little_num(stack->stack_b, MIN);
			max_b = ft_high_num(stack->stack_b, MAX);
		}
		else
		{

		}
	}
}
