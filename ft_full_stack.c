/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:50:30 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/31 17:35:01 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_more_five(t_list **stack_a, t_list **stack_b)
{
	t_list *first_a;
	t_list *first_b;
	int min;
	int next_min;
	int distance;
	int size_a;
	int size_b;

	first_a = *stack_a;
	first_b = *stack_b;
	
	size_a = ft_lstsize(first_a);
	size_b = ft_lstsize(first_b);
	
	min = ft_little_num(stack_a, MIN);
	next_min = ft_little_num(stack_a, min);
	
	distance = ft_distance(stack_a, min);
	while (size_a)
	{
		first_a = *stack_a;
		min = ft_little_num(stack_a, MIN);
		next_min = ft_little_num(stack_a, min);
			printf("el minimo es %i\n", min);
		while (distance)
		{
				printf("la distancia es de %i\n", distance);	
			ra(stack_a);
				printf("===============\n");
				ft_print_list(*stack_a);
				printf("---------------\n");
				ft_print_list(*stack_b);
				printf("===============\n");
			distance--;
		}
		if (distance == 0)
		{
			pb(stack_a, stack_b);
				printf("===============\n");
				ft_print_list(*stack_a);
				printf("---------------\n");
				ft_print_list(*stack_b);
				printf("===============\n");
			min = next_min;
			distance = ft_distance(stack_a, min);
			size_a = ft_lstsize(first_a);
		}
	}
	
	while(size_b >= 0)
	{
		first_a = *stack_a;
		first_b = *stack_b;
		pa(stack_b,stack_a);
	}
}