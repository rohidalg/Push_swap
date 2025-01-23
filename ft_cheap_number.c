/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheap_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:02 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/23 19:00:09 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_double(t_stack *stack)
{
	stack->move_rr = 0;
	stack->move_rrr = 0;
	while (stack->move_ra != 0 && stack->move_rb != 0)
	{
		stack->move_ra--;
		stack->move_rb--;
		stack->move_rr++;
	}
	while (stack->move_rra != 0 && stack->move_rrb != 0)
	{
		stack->move_rra--;
		stack->move_rrb--;
		stack->move_rrr++;
	}
}
//rebaja los movimientos con rrr cuando hay uno de rr de cada

void	ft_cost(t_stack *stack, int i)
{
	stack->move_cost = stack->move_pb + stack->move_ra + stack->move_rb
		+ stack->move_rr + stack->move_rra + stack->move_rrb + stack->move_rrr;
	if (i == 1 || stack->cheap_cost > stack->move_cost)
	{
		stack->cheap_cost = stack->move_cost;
		stack->cheap_pb = stack->move_pb;
		stack->cheap_ra = stack->move_ra;
		stack->cheap_rb = stack->move_rb;
		stack->cheap_rr = stack->move_rr;
		stack->cheap_rra = stack->move_rra;
		stack->cheap_rrb = stack->move_rrb;
		stack->cheap_rrr = stack->move_rrr;
	}
}
// cuando encuentra un numero que sea mas barato de mover se guarda

void	ft_moves(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	int		i;
	int		size;

	first_a = *stack_a;
	i = 0;
	size = ft_lstsize(*stack_a);
	while (i++ < size)
	{
		ft_get_top_a(stack, stack_a, i - 1);
		if (first_a->nmb < stack->min_b || first_a->nmb > stack->max_b)
			ft_get_top_b(stack, stack_b);
		else
			ft_new_pb(stack, stack_b, first_a->nmb);
		ft_check_double(stack);
		ft_cost(stack, i);
		first_a = first_a->next;
	}
}
//calcula los movimmientos necesarios para mover numeros del stack_a al b

void	ft_move_cost(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	while (stack->cheap_rra-- != 0)
		rra(stack_a);
	while (stack->cheap_rrb-- != 0)
		rrb(stack_b);
	while (stack->cheap_rrr-- != 0)
		rrr(stack_a, stack_b);
	while (stack->cheap_ra-- != 0)
		ra(stack_a);
	while (stack->cheap_rb-- != 0)
		rb(stack_b);
	while (stack->cheap_rr-- != 0)
		rr(stack_a, stack_b);
	while (stack->cheap_pb-- != 0)
		pb(stack_a, stack_b);
}
//ejecuta los movimientos mas bratos que se han encontrado

void	ft_move_cheap(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 0)
	{
		stack->min_b = ft_little_num(stack_b, MIN);
		stack->max_b = ft_high_num(stack_b, MAX);
		ft_moves(stack, stack_a, stack_b);
		ft_move_cost(stack, stack_a, stack_b);
	}
	ft_return(stack, stack_a, stack_b);
}
//mueve los numeros mas baaratos y los ordena de mayor a menor
// en el stack_b y los  devuelve al stack_a ordenads de menos a mayor
