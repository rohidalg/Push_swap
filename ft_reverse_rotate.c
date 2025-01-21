/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:49 by rohidalg          #+#    #+#             */
/*   Updated: 2024/09/18 16:16:00 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **stack_from)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_from) < 2)
		return (-1);
	first = *stack_from;
	last = ft_lstlast(first);
	while (first)
	{
		if (first->next->next == NULL)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	last->next = *stack_from;
	*stack_from = last;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (0);
}
