/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:10:28 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/03 18:12:23 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_num(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_distance(stack_a, ft_little_num(stack_a, MIN));
	if (distance == 1)
		sa(stack_a);
	else if (distance == 2)
		rra(stack_a);
	pb(stack_a, stack_b);
	if (ft_order(stack_a) != 1)
		sa(stack_a);
	pa(stack_b, stack_a);
}
// busca el minimo y lo pasa al stack_b

void	ft_four_num(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_distance(stack_a, ft_little_num(stack_a, MIN));
	if (distance == 1)
		sa(stack_a);
	else if (distance == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	ft_three_num(stack_a, stack_b);
	pa(stack_b, stack_a);
}
// busca el minimo y lo pasa al stack_b y ejecuta la funcion de 3 numeros

void	ft_five_num(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ft_distance(stack_a, ft_little_num(stack_a, MIN));
	if (distance == 1)
		sa(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	ft_four_num(stack_a, stack_b);
	pa(stack_b, stack_a);
}
// busca el minimo y lo pasa al stack_b y ejecuta la funcion de 4 numeros

void	ft_options(t_list **stack_a, t_list **stack_b)
{
	t_stack	*stack;
	int		size;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2 && ft_order(stack_a) != 1)
		sa(stack_a);
	else if (size == 3 && ft_order(stack_a) != 1)
		ft_three_num(stack_a, stack_b);
	else if (size == 4 && ft_order(stack_a) != 1)
		ft_four_num(stack_a, stack_b);
	else if (size == 5 && ft_order(stack_a) != 1)
		ft_five_num(stack_a, stack_b);
	else if (size > 5 && ft_order(stack_a) != 1)
		ft_move_cheap(stack, stack_a, stack_b);
	free(stack);
}
// segun la cantidad de numeros ejecuta unna funcionn distinta
