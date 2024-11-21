/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:50:30 by rohidalg          #+#    #+#             */
/*   Updated: 2024/11/19 11:59:42 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_more_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	next_min;
	int	distance;
	int	ddistance;
	int	distance_max;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	min = ft_little_num(stack_a, MIN);
	next_min = ft_little_num(stack_a, min);
	while (size_a)
	{
		distance = ft_distance(stack_a, min);
		ddistance = (ft_lstsize(*stack_a) - distance);
		distance_max = ft_distance(stack_a, (ft_high_num(stack_a, MIN)));
		if (distance_max < distance || distance_max < ddistance)
		{
			ft_next(stack_a, stack_b);
		}
		if (ddistance <= distance)
		{
			while (ddistance)
			{
				rra(stack_a);
				ddistance--;
			}
			if (ddistance == 0)
			{
				pb(stack_a, stack_b);
				min = next_min;
				ddistance = ft_distance(stack_a, min);
				size_a = ft_lstsize(*stack_a);
			}
		}
		else
		{
			while (distance)
			{
				ra(stack_a);
				distance--;
			}
			if (distance == 0)
			{
				pb(stack_a, stack_b);
				min = next_min;
				distance = ft_distance(stack_a, min);
				size_a = ft_lstsize(*stack_a);
			}
		}
		min = ft_little_num(stack_a, MIN);
		next_min = ft_little_num(stack_a, min);
	}
	size_b = ft_lstsize(*stack_b);
	while (size_b)
	{
		pa(stack_b, stack_a);
		size_b = ft_lstsize(*stack_b);
	}
}

void	ft_next(t_list **stack_from, t_list **stack_to)
{
	t_list	*first;

	int high_a, distance, reverse;
	if (!stack_to || !*stack_to)
		return ;
	first = *stack_to;
	high_a = ft_high_num(stack_from, MIN);
	while (first)
	{
		if (high_a > first->nmb)
			first = first->next;
		else
			break ;
		if (first && first->nmb > high_a)
		{
			distance = ft_distance(stack_to, first->nmb);
			reverse = distance;
			while (distance--)
				rra(stack_to);
			while (reverse--)
				ra(stack_to);
		}
	}
}
