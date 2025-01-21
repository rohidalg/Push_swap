/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:57:57 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/21 16:58:18 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*next;
	int		tmp_nmb;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	next = first->next;
	if (!first || !next)
		ft_putendl_fd("ERROR_SWAP", 1);
	tmp_nmb = first->nmb;
	tmp_index = first->index;
	first->nmb = next->nmb;
	first->index = next->index;
	next->nmb = tmp_nmb;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == -1 || swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}
