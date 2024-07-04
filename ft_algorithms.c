/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:10:28 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/04 20:16:50 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	little_num(t_list **stack_from, int lit)
{
	t_list	*first;
	int		little;

	first = *stack_from;
	little = first->nmb;
	while (first->next)
	{
		first = first->next;
		if (first->nmb < little && first->nmb > lit)
			little = first->nmb;
	}
	return (little);
}

int	ft_order(t_list **stack_from)
{
	t_list	*first;

	first = *stack_from;
	while (first && first->next)
	{
		if (first->nmb > first->next->nmb)
			return (0);
		first = first->next;
	}
	return (1);
}

void	ft_three_num(t_list **stack_from)
{
	t_list	*first;

	first = *stack_from;
	printf("===============\n");
	ft_print_list(*stack_from);
	printf("===============\n");
	if (first->nmb > first->next->nmb)
	{
		sa(stack_from);
		printf("===============\n");
		ft_print_list(*stack_from);
		printf("===============\n");
	}
	if (first->next->nmb > first->next->next->nmb)
	{
		rra(stack_from);
		printf("===============\n");
		ft_print_list(*stack_from);
		printf("===============\n");
	}
	if (first->nmb > first->next->nmb)
	{
		printf("hola?\n");
		sa(stack_from);
		printf("===============\n");
		ft_print_list(*stack_from);
		printf("===============\n");
	}	
}
// (A, B, C), (A, C, B), (B, A, C), (B, C, A), (C, A, B), (C, B, A).

void	ft_options(t_list **stack_from)
{
	int	size;

	size = ft_lstsize(*stack_from);
	if (size == 2 && ft_order(stack_from) != 1)
		sa(stack_from);
	else if (size == 3 && ft_order(stack_from) != 1)
		ft_three_num(stack_from);
}
