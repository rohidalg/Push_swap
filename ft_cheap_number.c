/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheap_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:02 by rohidalg          #+#    #+#             */
/*   Updated: 2024/11/21 13:23:38 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_move(t_stack *stack)
{
	stack->move_cost = 0;
	stack->move_pb = 0;
	stack->move_ra = 0;
	stack->move_rb = 0;
	stack->move_rr = 0;
	stack->move_rra = 0;
	stack->move_rrb = 0;
	stack->move_rrr = 0;
}

void	ft_check_double(t_stack *stack)
{
	stack->move_rr = 0;
	stack->move_rrr = 0;
	while (stack->move_ra != 0 && stack->move_rb != 0)
	{
		stack->move_ra--;
		stack->move_rb--;
		stack->move_rr++;
	}
	while (stack->move_rra != 0 && stack->move_rrb != 0)
	{
		stack->move_rra--;
		stack->move_rrb--;
		stack->move_rrr++;
	}
}

void	ft_cost(t_stack *stack, int i)
{
	stack->move_cost = stack->move_pb + stack->move_ra + stack->move_rb + stack->move_rr + stack->move_rra
		+ stack->move_rrb + stack->move_rrr;
	if (i == 1 || stack->cheap_cost > stack->move_cost)
	{
		stack->cheap_cost = stack->move_cost;
		stack->cheap_pb = stack->move_pb;
		stack->cheap_ra = stack->move_ra;
		stack->cheap_rb = stack->move_rb;
		stack->cheap_rr = stack->move_rr;
		stack->cheap_rra = stack->move_rra;
		stack->cheap_rrb = stack->move_rrb;
		stack->cheap_rrr = stack->move_rrr;
	}
}

void	ft_get_top(t_stack *stack, t_list *first_a, int i)
{
	int	size;

	stack->move_pb = 1;
	stack->move_ra = 0;
	stack->move_rra = 0;
	size = ft_lstsize(first_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->move_rra = (size - i);
		else
			stack->move_ra = i;
	}
	else
	{
		if (i > size / 2)
			stack->move_rra = (size - i);
		else
			stack->move_ra = i;
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
	stack->move_rb = 0;
	stack->move_rrb = 0;
	n = ft_search(stack_b, nmb);
	if (first_b->nmb == n)
		return ;
	i = ft_distance(stack_b, nmb);
	size = ft_lstsize(*stack_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->move_rra = (size - i);
		else
			stack->move_ra = i;
	}
	else
	{
		if (i > size / 2)
			stack->move_rra = (size - i);
		else
			stack->move_ra = i;
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
		printf("antes de entrar a get_top\n\n");
		ft_init_move(stack);
		ft_get_top(stack, first_a, i - 1);
		if (first_a->nmb < min_b || first_a->nmb > max_b)
		{
			min_b = ft_little_num(stack_b, MIN);
			max_b = ft_high_num(stack_b, MAX);
			printf("el maximo es :%d\n\n", min_b);	
			printf("el minimo es :%d\n\n", max_b);	
		}
		else
			ft_new_pb(stack, stack_b, first_a->nmb);
		ft_check_double(stack);
		printf("antes de entrar a cost\n\n");
		ft_cost(stack, i);
		first_a = first_a->next;
	}
}
