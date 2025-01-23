/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:38 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/23 18:31:14 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_little_num(t_list **stack_from, int lit)
{
	t_list	*first;
	int		little;

	if (!stack_from || !(*stack_from))
		return (0);
	first = *stack_from;
	little = first->nmb;
	while (first)
	{
		if (first->nmb < little && first->nmb != lit)
			little = first->nmb;
		first = first->next;
	}
	return (little);
}
// busca el minimo dentro del stack

int	ft_high_num(t_list **stack_from, int max)
{
	t_list	*first;
	int		high;

	if (!stack_from || !(*stack_from))
		return (0);
	first = *stack_from;
	high = first->nmb;
	while (first->next)
	{
		first = first->next;
		if ((first->nmb > high) && first->nmb != max)
			high = first->nmb;
	}
	return (high);
}
// busca el maximo dentro del stack

int	ft_distance(t_list **stack_from, int nmb)
{
	t_list	*first;
	int		distance;

	first = *stack_from;
	distance = 0;
	while (first)
	{
		if (first->nmb == nmb)
			break ;
		distance++;
		first = first->next;
	}
	return (distance);
}
//busca la distancia que hay desde el inicio hasta 
//el numero indicado

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
//comprueba si esta ordenadoo

void	ft_free_stack(t_list **stack)
{
	t_list	*nmb;
	t_list	*tmp;

	nmb = *stack;
	while (nmb)
	{
		tmp = nmb;
		nmb = nmb->next;
		free(tmp);
	}
	free(stack);
}
