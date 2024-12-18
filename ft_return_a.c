/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:44:59 by rohidalg          #+#    #+#             */
/*   Updated: 2024/12/18 13:45:13 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_return(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	t_list *first_a;
	int i;
	int size;

	first_a = *stack_a;
	ft_init_move(stack);
	printf("inicie los valores\n");
	if (first_a->nmb != stack->min_a)
	{
		i = ft_distance(stack_a, stack->min_a);
		size = ft_lstsize(*stack_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stack->move_rrb = (size - i);
			else
				stack->move_rb = i;
		}
		else
		{
			if (i > size / 2)
				stack->move_rrb = (size - i);
			else
				stack->move_rb = i;
		}
		printf("se guardaron los valores\n");
		ft_move_cost(stack, stack_a, stack_b);
	}
}
