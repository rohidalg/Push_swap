/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:10:28 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/16 13:43:38 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_num(t_list **stack_a)
{
	t_list	*first;

	first = *stack_a;
	if (first->nmb > first->next->next->nmb)
	{
		if (first->nmb < first->next->nmb) //(B, C, A)
		{
			rra(stack_a);
			printf("===============\n");
			ft_print_list(*stack_a);
			printf("===============\n");
		}
		else if (first->next->nmb > first->next->next->nmb) //(C, B, A)
		{
			sa(stack_a);
			printf("===============\n");
			ft_print_list(*stack_a);
			printf("===============\n");
			rra(stack_a);
			printf("===============\n");
			ft_print_list(*stack_a);
			printf("===============\n");
		}
		else //(C, A, B)
		{	
			ra(stack_a);
			printf("===============\n");
			ft_print_list(*stack_a);
			printf("===============\n");
		}
	}
	else if (first->nmb > first->next->nmb) //(B, A, C)
	{
		sa(stack_a);
		printf("===============\n");
		ft_print_list(*stack_a);
		printf("===============\n");
	}
	else if (first->next->nmb > first->next->next->nmb) //(A, C, B)
	{
		rra(stack_a);
		printf("===============\n");
		ft_print_list(*stack_a);
		printf("===============\n");
		sa(stack_a);
		printf("===============\n");
		ft_print_list(*stack_a);
		printf("===============\n");
	}
}

void	ft_four_num(t_list **stack_a, t_list **stack_b)
{
	// t_list *first;
	int distance;
	
	// first = *stack_a;
	distance = ft_distance(stack_a, ft_little_num(stack_a, -1));
	printf("===============\n");
	ft_print_list(*stack_a);
	printf("===============\n");
	if (distance == 1)
	{
		sa(stack_a);
		printf("===============\n");
		ft_print_list(*stack_a);
		printf("===============\n");
	}
	else if (distance == 2)
	{
		rra(stack_a);
		printf("===============\n");
		ft_print_list(*stack_a);
		printf("===============\n");
		rra(stack_a);
		printf("===============\n");
		ft_print_list(*stack_a);
		printf("===============\n");
	}
	else if (distance == 3)
	{
		rra(stack_a);
		printf("===============\n");
		ft_print_list(*stack_a);
		printf("===============\n");
	}
	pb(stack_b, stack_a);
	
	printf("===============\n");
	ft_print_list(*stack_a);
	printf("---------------\n");
	ft_print_list(*stack_b);
	printf("===============\n");
	
	ft_three_num(stack_a);
	
	pa(stack_a, stack_b);

	printf("===============\n");
	ft_print_list(*stack_a);
	printf("---------------\n");
	ft_print_list(*stack_b);
	printf("===============\n");

}

void	ft_options(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2 && ft_order(stack_a) != 1)
		sa(stack_a);
	else if (size == 3 && ft_order(stack_a) != 1)
		ft_three_num(stack_a);
	else if (size == 4 && ft_order(stack_a) != 1)
		ft_four_num(stack_a, stack_b);
}
