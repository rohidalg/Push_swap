/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:54:27 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/23 18:56:16 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search(t_list **stack_b, int nmb)
{
	t_list	*first_b;
	int		i;
	int		size;
	int		flag;

	first_b = *stack_b;
	i = 0;
	size = ft_lstsize(*stack_b);
	flag = 0;
	while (flag == 0)
	{
		i = 0;
		nmb--;
		first_b = *stack_b;
		while (i++ < size)
		{
			if (first_b->nmb == nmb)
				flag = 1;
			first_b = first_b->next;
		}
	}
	return (nmb);
}

void	ft_get_top_a(t_stack *stack, t_list **stack_a, int i)
{
	int	size;

	stack->move_pb = 1;
	stack->move_ra = 0;
	stack->move_rra = 0;
	size = ft_lstsize(*stack_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->move_rra = (size - i);
		else
			stack->move_ra = i;
	}
	else
	{
		if (i > size / 2)
			stack->move_rra = (size - i);
		else
			stack->move_ra = i;
	}
}
// comprueba cual es mas barato de llevar a la cima del stack_a

void	ft_get_top_b(t_stack *stack, t_list **stack_b)
{
	t_list	*first_b;
	int		i;
	int		size;

	stack->move_rb = 0;
	stack->move_rrb = 0;
	first_b = *stack_b;
	if (first_b->nmb == stack->max_b)
		return ;
	i = ft_distance(stack_b, stack->max_b);
	size = ft_lstsize(*stack_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->move_rrb = (size - i);
		else
			stack->move_rb = i;
	}
	else
	{
		if (i > size / 2)
			stack->move_rrb = (size - i);
		else
			stack->move_rb = i;
	}
}
//busca el max y lo pone en la cima

void	ft_new_pb(t_stack *stack, t_list **stack_b, int nmb)
{
	int		i;
	int		size;
	int		n;

	stack->move_rb = 0;
	stack->move_rrb = 0;
	n = ft_search(stack_b, nmb);
	i = ft_distance(stack_b, n);
	size = ft_lstsize(*stack_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->move_rrb = (size - i);
		else
			stack->move_rb = i;
	}
	else
	{
		if (i > size / 2)
			stack->move_rrb = (size - i);
		else
			stack->move_rb = i;
	}
}
//busca en donde deberia ir el numero en especifico dentro del stack_b
