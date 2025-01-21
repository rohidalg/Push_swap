/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:59:15 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/21 17:01:40 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;
	t_list	*first_to;
	t_list	*first_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	first_to = *stack_to;
	first_from = *stack_from;
	tmp = first_from;
	first_from = first_from->next;
	*stack_from = first_from;
	if (!first_to)
	{
		first_to = tmp;
		first_to->next = NULL;
		*stack_to = first_to;
	}
	else
	{
		tmp->next = first_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
