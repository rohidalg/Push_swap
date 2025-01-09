/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:44:59 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/09 13:38:12 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_return(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	int size;
	int distance;

	size = ft_lstsize(*stack_b);
	// printf("size vale %i\n", size);
	distance = ft_distance(stack_b, stack->max_b);
	while(distance--)
		rb(stack_b);
	while(size-- != 0)
		pa(stack_b, stack_a);
}
