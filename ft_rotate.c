/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:01:03 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/21 17:01:36 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack_from)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_from) < 2)
		return (-1);
	first = *stack_from;
	last = ft_lstlast(first);
	*stack_from = first->next;
	first->next = NULL;
	last->next = first;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
