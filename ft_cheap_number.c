/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheap_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:02:02 by rohidalg          #+#    #+#             */
/*   Updated: 2024/12/17 14:04:08 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_move(t_stack *stack)
{
	stack->cheap_cost = 0;
	stack->cheap_pb = 0;
	stack->cheap_ra = 0;
	stack->cheap_rb = 0;
	stack->cheap_rr = 0;
	stack->cheap_rra = 0;
	stack->cheap_rrb = 0;
	stack->cheap_rrr = 0;
	stack->move_cost = 0;
	stack->move_pb = 0;
	stack->move_ra = 0;
	stack->move_rb = 0;
	stack->move_rr = 0;
	stack->move_rra = 0;
	stack->move_rrb = 0;
	stack->move_rrr = 0;
}

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

void	ft_cost(t_stack *stack, int i)
{
	stack->move_cost = stack->move_pb + stack->move_ra + stack->move_rb
		+ stack->move_rr + stack->move_rra + stack->move_rrb + stack->move_rrr;
	// tengo que arreglar esto cuando quito el i == 1		
	if (i == 1 || stack->cheap_cost > stack->move_cost)
	{
		// printf("se guardaron lo moviminetos de la poicion %i\n", i);
		stack->cheap_cost = stack->move_cost;
		stack->cheap_pb = stack->move_pb;
		stack->cheap_ra = stack->move_ra;
		stack->cheap_rb = stack->move_rb;
		stack->cheap_rr = stack->move_rr;
		stack->cheap_rra = stack->move_rra;
		stack->cheap_rrb = stack->move_rrb;
		stack->cheap_rrr = stack->move_rrr;
		// printf("Valores de stack->cheaps:\n");
		// printf("cheap_cost -> %i\n", stack->cheap_cost);
		// printf("cheap_pb   -> %i\n", stack->cheap_pb);
		// printf("cheap_ra   -> %i\n", stack->cheap_ra);
		// printf("cheap_rb   -> %i\n", stack->cheap_rb);
		// printf("cheap_rr   -> %i\n", stack->cheap_rr);
		// printf("cheap_rra  -> %i\n", stack->cheap_rra);
		// printf("cheap_rrb  -> %i\n", stack->cheap_rrb);
		// printf("cheap_rrr  -> %i\n", stack->cheap_rrr);
	}
}

void	ft_get_top_a(t_stack *stack, t_list **stack_a, int i)
{
	int	size;

	stack->move_pb = 1;
	stack->move_ra = 0;
	stack->move_rra = 0;
	size = ft_lstsize(*stack_a);
	// printf("size = %i\n", size);
	// printf("i = %i\n", i);
	
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
	// printf("rra = %i\n", stack->move_rra);
	// printf("ra = %i\n", stack->move_ra);
	// printf("pb = %i\n", stack->move_pb);
	// printf("sali de get_top_a\n\n");
}

void	ft_get_top_b(t_stack *stack, t_list **stack_b)
{
	t_list *first_b;
	int	i;
	int	size;

	stack->move_rb = 0;
	stack->move_rrb = 0;
	first_b = *stack_b;
	if (first_b->nmb == stack->max_b)
		return ;
	i = ft_distance(stack_b, stack->max_b);
	size = ft_lstsize(*stack_b);
	// printf("size_b = %i\n", size);
	// printf("i_b = %i\n", i);
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
	// printf("rrb = %i\n", stack->move_rrb);
	// printf("rb = %i\n", stack->move_rb);
	// printf("sali de get_top_b\n\n");
}

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

void	ft_new_pb(t_stack *stack, t_list **stack_b, int nmb)
{
	t_list	*first_b;
	int		i;
	int		size;
	int		n;

	first_b = *stack_b;
	stack->move_rb = 0;
	stack->move_rrb = 0;
	n = ft_search(stack_b, nmb);
	if (first_b->nmb == n)
		return ;
	i = ft_distance(stack_b, n);
	size = ft_lstsize(*stack_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
		{
			// printf("entre a rrb\n");
			stack->move_rrb = (size - i);
			// printf("rrb = %i\n", stack->move_rrb);
		}
		else
		{
			// printf("entre a rb\n");
			stack->move_rb = i;
			// printf("rb = %i\n", stack->move_rb);
		}
	}
	else
	{
		if (i > size / 2)
		{
			// printf("entre a rrb\n");
			stack->move_rrb = (size - i);
			// printf("rrb = %i\n", stack->move_rrb);
		}
		else
		{
			// printf("entre a rb\n");
			stack->move_rb = i;
			// printf("rb = %i\n", stack->move_rb);
		}
	}
}

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
		// printf("size = %i---------------------------------------------------------\n", size);
		// printf("nmb = %i\n", first_a->nmb);
		// printf("antes de entrar a get_top\n\n");
		ft_get_top_a(stack, stack_a, i - 1);
		if (first_a->nmb < stack->min_b
			|| first_a->nmb > stack->max_b)
		{
			// printf("ENTREEE!!!!\n\n");
			ft_get_top_b(stack, stack_b);
		}
		else
			ft_new_pb(stack, stack_b, first_a->nmb);
		ft_check_double(stack);
		// printf("antes de entrar a cost\n\n");
		ft_cost(stack, i);
		first_a = first_a->next;
	}
}

void	ft_move_cost(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	// // printf("rra = %i\n\n", stack->cheap_rra);
	// // printf("pb = %i\n\n", stack->cheap_pb);
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

void	ft_move_cheap(t_stack *stack, t_list **stack_a, t_list **stack_b)
{
	ft_init_move(stack);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	
	while (ft_lstsize(*stack_a) > 3)
	{
			// printf("===============\n");
			// ft_print_list(*stack_a);
			// printf("---------------\n");
			// ft_print_list(*stack_b);
			// printf("===============\n");
		stack->min_b = ft_little_num(stack_b, MIN);
		stack->max_b = ft_high_num(stack_b, MAX);
		// printf("hay %i numeros en el stack a\n\n", ft_lstsize(*stack_a));
		ft_moves(stack, stack_a, stack_b);
		ft_move_cost(stack, stack_a, stack_b);
	}
	ft_three_num(stack_a, stack_b);
	ft_return(stack, stack_a, stack_b);
}
