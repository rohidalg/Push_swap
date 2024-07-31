/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:49 by rohidalg          #+#    #+#             */
/*   Updated: 2024/07/25 19:21:02 by rohidalg         ###   ########.fr       */
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
// sa = swap a // intercambia los 2 elementos superiores de la pila a

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}
// sb = swap b // intercambia los 2 elementos superiores de la pila b

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == -1 || swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}
// ss = swap a + swap b // tanto sa como sb

int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;
	t_list	*first_to;
	t_list	*first_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	first_to = *stack_to;
	first_from = *stack_from;
	tmp = first_from;
	first_from = first_from->next;
	*stack_from = first_from;
	if (!first_to)
	{
		first_to = tmp;
		first_to->next = NULL;
		*stack_to = first_to;
	}
	else
	{
		tmp->next = first_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}
// pa = push a
	// mueve el elemento superior de la pila b a la parte superior de la pila a

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
// pb = push b
	// mueve el elemento superior de la pila a a la parte superior de la pila b

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
// ra = rotate a
	// desplaza todos los elementos de la pila a una posicion arriba

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}
// rb = rotate b
	// desplaza todos los elementos de la pila b una posicion arriba

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
// rr = rotate a + rotate b // tanto ra como rb

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
// rra = reverse rotate a
	// desplaza todos los elementos de la pila a de arriba a abajo una posicion

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}
// rrb = reverse rotate b
	// desplaza todos los elementos de la pila b hacia abajo una posicion

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (0);
}
// rrr = reverse rotate a + reverse rotate b // tanto rra como rrb