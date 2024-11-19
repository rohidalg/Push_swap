/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheap_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:02 by rohidalg          #+#    #+#             */
/*   Updated: 2024/11/13 19:52:09 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_double(t_stack *stack)
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

void	ft_get_top(t_stack *stack, int i)
{
	int	size;

	stack->move->pb = 1;
	stack->move->ra = 0;
	stack->move->rra = 0;
	size = ft_lstsize(stack->first);
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

int	ft_search(t_list **stack_b, int nmb)
{
	t_list	*first_b;
	int		i;
	int		size;

	if (!stack_b || !*stack_b)
		return (-1);
	size = ft_lstsize(*stack_b);
	while (1)
	{
		first_b = *stack_b;
		i = 0;
		while (i++ < size)
		{
			if (first_b->nmb == nmb)
				return (nmb);
			first_b = first_b->next;
		}
		nmb--;
	}
}

void	ft_new_pb(t_stack *stack, t_list **stack_b, int nmb)
{
	t_list	*first_b;
	int		i;
	int		size;
	int		n;

	first_b = *stack_b;
	stack->move->rb = 0;
	stack->move->rrb = 0;
	n = ft_search(stack_b, nmb);
	if (first_b->nmb == n)
		return ;
	i = ft_distance(stack_b, nmb);
	size = ft_lstsize(*stack_b);
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

void	ft_moves(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	int		i;
	int		size;
	int		min_b;
	int		max_b;

	first_a = *stack_a;
	i = 0;
	size = ft_lstsize(*stack_a);
	min_b = ft_little_num(stack_b, MIN);
	max_b = ft_high_num(stack_b, MAX);
	while (i++ < size)
	{
		ft_get_top(stack, MIN);
		if (first_a->nmb < min_b || first_a->nmb > max_b)
		{
			min_b = ft_little_num(stack_b, MIN);
			max_b = ft_high_num(stack_b, MAX);
		}
		else
		{
			ft_new_pb(stack, stack_b, first_a->nmb);
		}
		ft_check_double(stack);
		ft_cost(stack, i);
		first_a = first_a->next;
	}
}
