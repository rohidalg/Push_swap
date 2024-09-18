/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:50:30 by rohidalg          #+#    #+#             */
/*   Updated: 2024/08/13 17:31:36 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_more_five(t_list **stack_a, t_list **stack_b)
{
	int min;
	int next_min;
	int distance;
	int size_a;
	int size_b;
	
	size_a = ft_lstsize(*stack_a);
	
	min = ft_little_num(stack_a, MIN);
	next_min = ft_little_num(stack_a, min);
	
	while (size_a)
	{
		distance = ft_distance(stack_a, min);
			//printf("aqui empieza el while\n");
		while (distance)
		{	
			//printf("la distancia es %i\n", distance);
			ra(stack_a);
				//printf("===============\n");
				//ft_print_list(*stack_a);
				//printf("---------------\n");
				//ft_print_list(*stack_b);
				//printf("===============\n");
			distance--;
		}
		if (distance == 0)
		{
				// //printf("el minimo reiniciado es %i\n", min);
			pb(stack_a, stack_b);
				// //printf("===============\n");
				// //ft_print_list(*stack_a);
				// //printf("---------------\n");
				// //ft_print_list(*stack_b);
				// //printf("===============\n");
			min = next_min;
			distance = ft_distance(stack_a, min);
			size_a = ft_lstsize(*stack_a);
		}
		min = ft_little_num(stack_a, MIN);
		next_min = ft_little_num(stack_a, min);
			// //printf("el minimo es %i\n", min);
	}
	
	size_b = ft_lstsize(*stack_b);
	while(size_b)
	{
		pa(stack_b,stack_a);
				// //printf("===============\n");
				// //ft_print_list(*stack_a);
				// //printf("---------------\n");
				// //ft_print_list(*stack_b);
				// //printf("===============\n");
		size_b = ft_lstsize(*stack_b);
	}
}
