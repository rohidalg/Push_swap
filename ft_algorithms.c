/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:10:28 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/02 13:10:17 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two_num(t_list **stack_from)
{
	// t_list *first;
	// t_list *last;

	// first = *stack_from;
	// last = ft_lstlast(*stack_from);
	if (ft_lstsize(*stack_from) == 2)
	{
		ft_putendl_fd("es mayor\n", 1);
		sa(stack_from);
	}
}