/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:50:30 by rohidalg          #+#    #+#             */
/*   Updated: 2024/09/19 17:09:47 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_more_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	next_min;
	int	distance;
	int	ddistance;
	int distance_max;
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
			printf("entre en distance max");
			ft_next(stack_a,stack_b);
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
				printf("entre en ddistance\n");
		}
		else
		{
			printf("entre en distance\n");
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

void ft_next(t_list **stack_from, t_list **stack_to)
{
	t_list *first;
	int high_a;
	int distance;
	int reverse;
	
	first = *stack_to;
	high_a = ft_high_num(stack_from, MIN);
	while(high_a > first->nmb)
	{
		first = first->next;
		if (first->nmb > high_a)
		{
			distance = ft_distance(stack_to, first->nmb);
			reverse = ft_distance(stack_to, first->nmb);
			while(distance)
			{
				rra(stack_to);
				printf("entre en istance");
				distance--;
			}
			while(reverse)
			{
				ra(stack_to);
				distance--;
			}
		}
	}
}

//buscar el siguiente max
//implementar el rrr