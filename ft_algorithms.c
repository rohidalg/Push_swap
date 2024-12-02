/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:10:28 by rohidalg          #+#    #+#             */
/*   Updated: 2024/12/02 14:38:26 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_num(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_distance(stack_a, ft_little_num(stack_a, MIN));
	if (distance == 1)
		sa(stack_a);
	else if (distance == 2)
		rra(stack_a);
	// comprobr si  ya esta ordenado
	pb(stack_a, stack_b);
	if (ft_order(stack_a) != 1)
		sa(stack_a);
	pa(stack_b, stack_a);
}

void	ft_four_num(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_distance(stack_a, ft_little_num(stack_a, MIN));
	// if (ft_order(stack_a) != 1)
	// 	pa(stack_a, stack_b);
	if (distance == 1)
		sa(stack_a);
	else if (distance == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	ft_three_num(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	ft_five_num(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_distance(stack_a, ft_little_num(stack_a, MIN));
	if (distance == 1)
		sa(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	ft_four_num(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	ft_options(t_list **stack_a, t_list **stack_b)
{
	t_stack *stack;
	int size;

	stack = malloc(sizeof(t_stack));
	size = ft_lstsize(*stack_a);
	if (size == 2 && ft_order(stack_a) != 1)
		sa(stack_a);
	else if (size == 3 && ft_order(stack_a) != 1)
		ft_three_num(stack_a, stack_b);
	else if (size == 4 && ft_order(stack_a) != 1)
		ft_four_num(stack_a, stack_b);
	else if (size == 5 && ft_order(stack_a) != 1)
		ft_five_num(stack_a, stack_b);
	else if (size > 5 && ft_order(stack_a) != 1)
		ft_move_cheap(stack, stack_a, stack_b);
}
