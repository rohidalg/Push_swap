/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:50:30 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/23 20:49:19 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_more_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	int		size_a;
	int		i;

	first_a = *stack_a;

	size_a = ft_lstsize(*stack_a);
	i = 0;
	while (size_a != 1)
	{
		first_a = *stack_a;
		size_a = ft_lstsize(*stack_a);
		if (size_a > 1)
		{
			if (first_a->nmb < first_a->next->nmb)
			{
				pb(stack_a, stack_b);
				printf("===============\n");
				ft_print_list(*stack_a);
				printf("---------------\n");
				ft_print_list(*stack_b);
				printf("===============\n");
				i++;	
			}
			else
			{
				sa(stack_a);
				printf("===============\n");
				ft_print_list(*stack_a);
				printf("---------------\n");
				ft_print_list(*stack_b);
				printf("===============\n");	
			}
		}
	}
	pb(stack_a, stack_b);
	
	while(i > 0)
	{
		first_a = *stack_a;

			pa(stack_b, stack_a);
				printf("===============\n");
				ft_print_list(*stack_a);
				printf("---------------\n");
				ft_print_list(*stack_b);
				printf("===============\n");
			i--;
	}
	pa(stack_b, stack_a);
}
