/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:10:28 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/02 17:25:23 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	little_num(t_list **stack_from)
{
	t_list	*first;
	int		little;
	int size;
	
	first = *stack_from;
	little = first->nmb;
	while (first->next)
	{
		first = first->next;
		printf("\nEl little es:%i\n", little);
		if (first->nmb < little)
			little = first->nmb;
	}
	printf("\nEl minimo es:%i\n", little);
	return (little);
}

void	ft_two_num(t_list **stack_from)
{
	little_num(stack_from);
	// if (ft_lstsize(*stack_from) == 2)
	// {
	// 	ft_putendl_fd("es mayor\n", 1);
	// 	sa(stack_from);
	// }
}
